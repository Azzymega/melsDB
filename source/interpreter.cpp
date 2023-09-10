#include "interpreter.hpp"

void interpreter::appendOpcode(opcode *code)
{
    this->funcStack.push(code);
}

opcode *interpreter::getStackTop()
{
    return this->funcStack.top();
}

void interpreter::popFromStack()
{
    this->funcStack.pop();
}
