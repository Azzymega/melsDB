#include "vm.hpp"

marxVM::marxVM()
{

}

marxVM::~marxVM()
{
    
}

void marxVM::pushToStack(data info)
{
    this->stack.push(info);
}

void marxVM::popFromStack()
{
    this->stack.pop();
}

data marxVM::getTopFromStack()
{
    return this->stack.top();
}
