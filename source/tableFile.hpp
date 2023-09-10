#pragma once
#include "define.hpp"
#include "dataFile.hpp"
#include "record.hpp"
#include "unicodeRecord.hpp"

struct tableFile
{
    u4 header = 0xBEBEBABA;
    u4 poolRecordCount;
    std::vector<unicodeRecord> pool;
    u2 typesCount;
    std::vector<dataFile> types;
    u4 recordsCount;
    std::vector<record> records;
};