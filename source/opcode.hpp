#pragma once
#include <vector>
#include <string>
#include "vm.hpp"

class opcode
{
protected:
    std::vector<std::wstring> args;

public:
    void pushArgs(std::wstring arg);
    virtual void execute(marxVM* runtime) = 0;
    std::vector<std::wstring> getArgs() const;
};

class exitOpcode : public opcode {
public:
    void execute(marxVM* runtime) override;
};

class createOpcode : public opcode {
public:
    void execute(marxVM* runtime) override;
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