#pragma once
#include "define.hpp"
#include "data.hpp"

class dataFile
{
private:
    dataType type;
    u4 nameIndex;
public:
    dataType returnType();
    u4 returnNameIndex();
    dataFile(dataType type, u4 nameIndex);
    dataFile(data info, u4 index);
};