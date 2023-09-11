#pragma once
#include "tokenDefinition.hpp"
#include <string>

struct token {
    tokenType type;
    std::wstring internals;
};