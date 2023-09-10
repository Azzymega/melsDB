#pragma once
#include <vector>
#include "dataFile.hpp"

struct record
{
    u4 count;
    std::vector<dataFile> records;
};

