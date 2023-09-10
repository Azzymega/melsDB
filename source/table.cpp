#include "table.hpp"

void table::setTypes(std::vector<data> types)
{
    this->types = types;
}

void table::setInternals(std::vector<std::vector<data>> internal)
{
    this->internal = internal;
}

int table::returnTypesLength()
{
    return types.size();
}

int table::returnAllLength()
{
    u4 length = 0;
    for (size_t i = 0; i < internal.size(); i++)
    {
        for (size_t j = 0; j < internal[i].size(); j++)
        {
            length++;
        }
    }
    return length;
}

data table::returnInternal(int x, int y)
{
    return internal[x][y];
}

data table::returnTypes(int index)
{
    return types[index];
}

std::vector<std::vector<data>> table::returnInternals()
{
    return internal;
}
