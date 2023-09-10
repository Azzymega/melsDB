#pragma once
#include "define.hpp"
#include <string>

class data
{
private:
    dataType type;
    std::wstring internal;
public:
    data(dataType type, std::wstring internal);
    dataType returnType();
    std::wstring returnInternal();
};