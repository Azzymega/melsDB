#include "data.hpp"

data::data(dataType type, std::wstring internal)
{
    this->type = type;
    this->internal = internal;
}

dataType data::returnType()
{
    return type;
}

std::wstring data::returnInternal()
{
    return internal;
}
