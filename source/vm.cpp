#include "vm.hpp"


void marxVM::pushToStack(table info)
{
    this->stack.push(info);
}

void marxVM::popFromStack()
{
    this->stack.pop();
}

table marxVM::getTopFromStack()
{
    return this->stack.top();
}

iomanager *marxVM::makeIOCall()
{
    return &ioctrl;
}
