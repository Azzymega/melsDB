#pragma once
#include <vector>
#include "data.hpp"

class table
{
private:
    std::vector<data> types;
    std::vector<std::vector<data>> internal;
public:
    void setTypes(std::vector<data> types);
    void setInternals(std::vector<std::vector<data>> internal);
    void addInternals(std::vector<data> internal);
    int returnTypesLength();
    int returnAllLength();
    data returnInternal(int x, int y);
    data returnTypes(int index);
    std::vector<std::vector<data>> returnInternals();
    std::vector<data> getTypes() const;
};
