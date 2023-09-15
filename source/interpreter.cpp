#include "interpreter.hpp"

bool compare(uint16_t *first, std::wstring second, int size){
    if (size != second.size())
    {
        return false;
    }
    else {
        for (size_t i = 0; i < size; i++)
        {
            if (first[i] != (uint16_t)second[i])
            {
                return false;
            }
        }
        return true;
    }
}

void interpreter::initInterpretation(marxVM* runtime)
{
    while (true)
    {
        std::vector<u1> data;
        std::wstring info;
        std::getline(std::wcin,info);
        data = std::vector<u1>(info.begin(),info.end());
        lexMachine machine(data);
        uint16_t exitcall[5] = {130,155,137,146,136}; // Thanks for this HACKFIX to CPP Legacy standartization committee!
        uint16_t createcall[7] = {145,142,135,132,128,146,156};
        uint16_t wherecall[3] = {131,132,133};
        uint16_t selectcall[7] = {130,155,129,144,128,146,156};
        uint16_t popcall[5] = {145,129,144,142,145};
        uint16_t iosavecall[6] = {135,128,143,136,145,156};
        uint16_t ioloadcall[9] = {135,128,131,144,147,135,136,146,156};
        std::vector<token> tokens = machine.returnTokens();
        for (size_t i = 0; i < tokens.size(); i++)
        {
            if (compare(exitcall,info,5))
            {
                exit(0);
            }
            if (compare(createcall,info,7))
            {
                createOpcode op = createOpcode();
                op.execute(runtime);
            }
            else if (compare(wherecall,info,3))
            {
                whereOpcode op = whereOpcode();
                i++;
                op.pushArgs(tokens[i].internals);
                i++;
                op.pushArgs(tokens[i].internals);
                i++;
                op.pushArgs(tokens[i].internals);
            }
            else if (compare(selectcall,info,7))
            {
                selectOpcode op = selectOpcode();
                for (size_t j = i; j < tokens.size(); j++)
                {
                    op.pushArgs(tokens[j].internals);
                }
                op.execute(runtime);
            }
            else if (compare(popcall,info,5))
            {
                popOpcode op = popOpcode();
                op.execute(runtime);
            }
            else if (compare(iosavecall,info,6))
            {
                iosaveOpcode op = iosaveOpcode();
                op.pushArgs(tokens[i+1].internals);
                op.execute(runtime);
            }
            else if (compare(ioloadcall,info,9))
            {
                ioloadOpcode op = ioloadOpcode();
                op.pushArgs(tokens[i+1].internals);
                op.execute(runtime);
            }
        } 
    } 
}

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
