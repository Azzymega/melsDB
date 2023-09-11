#pragma once
#include <regex>

enum tokenType {
    keywords,
    massiveDecl,
    identifier,
    flags,
    integer,
    internals_starts,
    internals_ends,
    logical_operation,
    operation,
    paramsStart,
    paramsEnd
};
