#pragma once
#include <stack>
#include "data.hpp"
#include "iomanager.hpp"
#include "table.hpp"

class marxVM
{
private:
    iomanager ioctrl;
    std::stack<table> stack;
public:
    marxVM();
    ~marxVM();
    void pushToStack(table info);
    void popFromStack();
    table getTopFromStack();
    iomanager* makeIOCall();
};