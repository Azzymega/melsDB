#pragma once
#include <stack>
#include "data.hpp"
#include "interpreter.hpp"
class marxVM
{
private:
    std::stack<data> stack;
    interpreter executer;
public:
    marxVM();
    ~marxVM();
    void pushToStack(data info);
    void popFromStack();
    data getTopFromStack();
};