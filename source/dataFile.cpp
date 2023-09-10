#include "dataFile.hpp"

dataType dataFile::returnType()
{
    return type;
}

u4 dataFile::returnNameIndex()
{
    return nameIndex;
}

dataFile::dataFile(dataType type, u4 nameIndex)
{
    this->type = type;
    this->nameIndex = nameIndex;
}

dataFile::dataFile(data info, u4 index)
{
    this->type = info.returnType();
    this->nameIndex = index;
}