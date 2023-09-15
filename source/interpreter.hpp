#pragma once
#include <stack>
#include "opcode.hpp"
#include "lexMachine.hpp"
#include "vm.hpp"

class interpreter
{
private:
    std::stack<opcode *> funcStack;

public:
    void initInterpretation(marxVM* vm);
    void appendOpcode(opcode *code);
    opcode *getStackTop();
    void popFromStack();
};