#pragma once
#include <vector>
#include <string>
#include "vm.hpp"

class opcode
{
protected:
    std::vector<std::wstring> args;

public:
    virtual void execute(marxVM* runtime) = 0;
    std::vector<std::wstring> getArgs() const;
};

class ioloadOpcode : public opcode {
public:
    void execute(marxVM* runtime) override;
};

class iosaveOpcode : public opcode {
public:
    void execute(marxVM* runtime) override;
}; 

class popOpcode : public opcode {
public:
    void execute(marxVM* runtime) override;    
};

class selectOpcode : public opcode{
public:
    void execute(marxVM* runtime) override;
};

class whereOpcode : public opcode {
public:
    void execute(marxVM* runtime) override;
};