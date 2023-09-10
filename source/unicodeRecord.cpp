#include "unicodeRecord.hpp"

unicodeRecord::unicodeRecord(dataType type, u2 length, std::wstring data)
{
    this->type = type;
    this->length = length;
    this->data = data;
}

unicodeRecord::unicodeRecord(class data tableData)
{
    this->type = tableData.returnType();
    this->length = tableData.returnInternal().size();
    this->data = tableData.returnInternal();
}

dataType unicodeRecord::returnType()
{
    return type;
}

u2 unicodeRecord::returnLength()
{
    return length;
}

std::wstring unicodeRecord::returnData()
{
    return data;
}
