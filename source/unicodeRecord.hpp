#pragma once
#include "define.hpp"
#include <string>
#include "data.hpp"

class unicodeRecord
{
private:
    dataType type = utf16string;
    u2 length;
    std::wstring data;
public:
    unicodeRecord(dataType type, u2 length, std::wstring data);
    unicodeRecord(class data tableData);
    dataType returnType();
    u2 returnLength();
    std::wstring returnData();
};