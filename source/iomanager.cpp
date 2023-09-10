#include "iomanager.hpp"

u2 iomanager::loadU2()
{
    u1 temp[4];
    readStream >> temp[0];
    readStream >> temp[1];
    readStream >> temp[2];
    readStream >> temp[3];
    return temp[0] >> 24 | temp[1] >> 16 | temp[2] >> 8 | temp[3];
}

u4 iomanager::loadU4()
{
    u1 temp[2];
    readStream >> temp[0];
    readStream >> temp[1];
    return temp[0] >> 8 | temp[1];
}

u1 iomanager::loadU1()
{
    u1 temp[1];
    readStream >> temp[0];
    return temp[0];
}

void iomanager::closeReadStream()
{
    this->readStream.close();
}

void iomanager::closerWriteStream()
{
    this->writeStream.close();
}

void iomanager::outputTable(tableFile *file)
{
    writeStream << file->header;
    writeStream << file->poolRecordCount;
    for (size_t i = 0; i < file->poolRecordCount; i++)
    {
        writeStream << file->pool[i].returnType();
        writeStream << file->pool[i].returnLength();
        for (size_t j = 0; j < file->pool[i].returnData().size(); j++)
        {
            writeStream << file->pool[i].returnData()[j];
        }
    }
    writeStream << file->typesCount;
    for (size_t i = 0; i < file->typesCount; i++)
    {
        writeStream << file->types[i].returnType();
        writeStream << file->types[i].returnNameIndex();
    }
    writeStream << file->recordsCount;
    for (size_t i = 0; i < file->recordsCount; i++)
    {
        writeStream << file->records[i].count;
        for (size_t j = 0; j < file->records[i].count; j++)
        {
            writeStream << file->records[i].records[j].returnType();
            writeStream << file->records[i].records[j].returnNameIndex();
        }
    }
}

tableFile *iomanager::inputTable()
{
    tableFile* file = new tableFile();
    file->header = loadU4();
    if (file->header != 0xBEBEBABA)
    {
        std::cout << "ERROR UNKNOW FILE FORMAT!!!";
        return nullptr;
    }
    file->poolRecordCount = loadU4();
    for (size_t i = 0; i < file->poolRecordCount; i++)
    {
        dataType type = (dataType)loadU4();
        u2 length = loadU2();
        std::wstring data;
        for (size_t j = 0; j < length; j++)
        {
            data.push_back(loadU2());
        }
        file->pool.push_back(unicodeRecord(type,length,data));
    }
    file->typesCount = loadU2();
    for (size_t i = 0; i < file->typesCount; i++)
    {
        dataType type = (dataType)loadU4();
        u4 nameIndex = loadU4();
        file->types.push_back(dataFile(type,nameIndex));
    }
    file->recordsCount = loadU4();
    for (size_t i = 0; i < file->recordsCount; i++)
    {
        record rc{};
        rc.count = loadU4();
        for (size_t j = 0; j < rc.count; j++)
        {
            dataType type = (dataType)loadU4();
            u4 nameIndex = loadU4();
            rc.records.push_back(dataFile(type,nameIndex));
        }
        file->records.push_back(rc);
    }
}

void iomanager::openReadStream(std::wstring path)
{
    this->readStream.open(path, std::ios::binary);
}

void iomanager::openWriteStream(std::wstring path)
{
    this->writeStream.open(path, std::ios::binary);
}

void iomanager::writeTable(table selectedTable)
{
    tableFile *file = new tableFile();
    file->poolRecordCount = selectedTable.returnAllLength();
    file->typesCount = selectedTable.returnTypesLength();
    for (size_t i = 0; i < file->typesCount; i++)
    {
        dataFile currentInfo = dataFile(selectedTable.returnTypes(i), file->pool.size());
        file->pool.push_back(unicodeRecord(selectedTable.returnTypes(i)));
        file->types.push_back(currentInfo);
    }
    file->recordsCount = selectedTable.returnInternals().size();
    for (size_t i = 0; i < file->recordsCount; i++)
    {
        record rc{};
        for (size_t j = 0; j < selectedTable.returnInternals()[i].size(); j++)
        {
            dataFile currentInfo = dataFile(selectedTable.returnInternals()[i][j], file->pool.size());
            file->pool.push_back(unicodeRecord(selectedTable.returnInternals()[i][j]));
            rc.records.push_back(currentInfo);
        }
        file->records.push_back(rc);
    }
    outputTable(file);
    closerWriteStream();
}

table iomanager::readTable()
{
    tableFile* file = inputTable();
    table currentTable = table();
    std::vector<data> types;
    for (size_t i = 0; i < file->types.size(); i++)
    {
        dataType type = file->types[i].returnType();
        std::wstring internal = file->pool[file->types[i].returnNameIndex()].returnData();
        types.push_back(data(type,internal));
    }
    currentTable.setTypes(types);
    std::vector<std::vector<data>> internals;
    for (size_t i = 0; i < file->recordsCount; i++)
    {
        std::vector<data> dataInfo;
        for (size_t j = 0; j < file->records[i].records.size(); j++)
        {
            dataType type = file->records[i].records[j].returnType();
            std::wstring internal = file->pool[file->records[i].records[j].returnNameIndex()].returnData();
            dataInfo.push_back(data(type,internal));
        }
        internals.push_back(dataInfo);
    }
    currentTable.setInternals(internals);
    return table();
}
