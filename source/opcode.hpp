#pragma once
#include <vector>
#include <string>

class opcode
{
private:
    std::vector<std::wstring> args;

public:
    virtual void execute() = 0;
    std::vector<std::wstring> getArgs() const;
};