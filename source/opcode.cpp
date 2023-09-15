#include "opcode.hpp"

void opcode::pushArgs(std::wstring arg)
{
    this->args.push_back(arg);
}

std::vector<std::wstring> opcode::getArgs() const
{
    return args;
}

void ioloadOpcode::execute(marxVM* runtime)
{
    std::string data(this->args[0].begin(),this->args[0].end());
    runtime->makeIOCall()->openReadStream(data);
    runtime->pushToStack(runtime->makeIOCall()->readTable());
}

void iosaveOpcode::execute(marxVM *runtime)
{
    std::string data(this->args[0].begin(),this->args[0].end());
    runtime->makeIOCall()->openWriteStream(data);
    runtime->makeIOCall()->writeTable(runtime->getTopFromStack());
};

void popOpcode::execute(marxVM *runtime)
{
    runtime->popFromStack();
}

void selectOpcode::execute(marxVM *runtime)
{
    table currentTable = runtime->getTopFromStack();
    table newTable;
    std::vector<int> indexes;
    std::vector<data> types;
    for (size_t i = 0; i < this->args.size(); i++)
    {
        if (args[i]==currentTable.returnTypes(i).returnInternal())
        {
            indexes.push_back(i);
        }
    }
    for (size_t i = 0; i < indexes.size(); i++)
    {
        types.push_back(currentTable.returnTypes(indexes[i]));
    }
    newTable.setTypes(types);
    for (size_t i = 0; i < indexes.size(); i++)
    {
        std::vector<data> internal;
        for (size_t j = 0; j < currentTable.returnInternals().size(); j++)
        {
            internal.push_back(currentTable.returnInternals()[j][i]);
        }
        newTable.addInternals(internal);
    }
    runtime->pushToStack(newTable);
}

void whereOpcode::execute(marxVM *runtime)
{
    table currentTable = runtime->getTopFromStack();
    table newTable;
    newTable.setTypes(currentTable.getTypes());
    int typeIndex;
    for (size_t i = 0; i < currentTable.getTypes().size(); i++)
    {
        if (currentTable.getTypes()[i].returnInternal() == args[0])
        {
            typeIndex = i;
            break;
        }
    }
    for (size_t i = 0; i < currentTable.returnInternals().size(); i++)
    {
        if (this->args[1] == L"==")
        {
            if (currentTable.returnInternals()[i][typeIndex].returnInternal() == this->args[2])
            {
                newTable.addInternals(currentTable.returnInternals()[i]);
            }
        }
        else if (this->args[1] == L">")
        {
            if (std::stoi(currentTable.returnInternals()[i][typeIndex].returnInternal()) > std::stoi(this->args[2]))
            {
                newTable.addInternals(currentTable.returnInternals()[i]);
            }
        }
        else if (this->args[1] == L"<")
        {
            if (std::stoi(currentTable.returnInternals()[i][typeIndex].returnInternal()) < std::stoi(this->args[2]))
            {
                newTable.addInternals(currentTable.returnInternals()[i]);
            }
        }
        else if (this->args[1] == L"<=")
        {
            if (std::stoi(currentTable.returnInternals()[i][typeIndex].returnInternal()) <= std::stoi(this->args[2]))
            {
                newTable.addInternals(currentTable.returnInternals()[i]);
            }
        }
        else if (this->args[1] == L">=")
        {
            if (std::stoi(currentTable.returnInternals()[i][typeIndex].returnInternal()) >= std::stoi(this->args[2]))
            {
                newTable.addInternals(currentTable.returnInternals()[i]);
            }
        }
        else if (this->args[1] == L"!=")
        {
            if (currentTable.returnInternals()[i][typeIndex].returnInternal() != this->args[2])
            {
                newTable.addInternals(currentTable.returnInternals()[i]);
            }
        }
    }
    runtime->pushToStack(newTable);
}

void createOpcode::execute(marxVM *runtime)
{
    runtime->pushToStack(table());
}

void exitOpcode::execute(marxVM *runtime)
{
    exit(0);
}
