#pragma once
#include <stack>
#include "opcode.hpp"

class interpreter
{
private:
    std::stack<opcode *> funcStack;

public:
    void appendOpcode(opcode *code);
    opcode *getStackTop();
    void popFromStack();
};