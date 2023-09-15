#include "lexMachine.hpp"

void lexMachine::parseBytes(std::vector<u1> bytes)
{
    std::wstring token;
    for (std::size_t i = 0; i < bytes.size(); i++)
    {
        if (bytes[i] == '"')
        {
            token.push_back(bytes[i]);
            i++;
            for (; i < bytes.size(); i++)
            {
                token.push_back(bytes[i]);
                if (token.at(token.size() - 1) == '"')
                {
                    this->parserOutput.push_back(token);
                    i++;
                    token.clear();
                    break;
                }
            }
        }
        if (bytes[i] == '[' && bytes[i + 1] == ']')
        {
            this->parserOutput.push_back(token);
            token.clear();
            token.push_back(bytes[i]);
            i++;
            token.push_back(bytes[i]);
            this->parserOutput.push_back(token);
            token.clear();
        }
        else if (token.size() > 1 && (bytes[i] == '(' || bytes[i] == '{' || bytes[i] == '[' || bytes[i] == ')' || bytes[i] == '}' || bytes[i] == ']'))
        {
            this->parserOutput.push_back(token);
            token.clear();
            token.push_back((char)bytes[i]);
            this->parserOutput.push_back(token);
            token.clear();
        }
        else if (isspace(bytes[i]) || bytes[i] == ';')
        {
            if (token.empty())
            {
                continue;
            }
            else
            {
                this->parserOutput.push_back(token);
                token.clear();
            }
        }
        else
        {
            token.push_back(bytes[i]);
        }
    }
    parserOutput.push_back(token);
}

void lexMachine::tokenize(std::vector<std::wstring> parserOutput)
{
    std::wregex keywordRegex(this->internalData.keywordRegex);
    std::wregex integerRegex(this->internalData.integerRegex);
    std::wregex logicalRegex(this->internalData.logicRegex);
    for (std::size_t i = 0; i < parserOutput.size(); i++)
    {
        if (std::regex_search(parserOutput[i], logicalRegex))
        {
            this->tokenizerOutput.push_back(token{tokenType::logical_operation, parserOutput[i]});
        }
        else if (std::regex_search(parserOutput[i], keywordRegex))
        {
            this->tokenizerOutput.push_back(token{tokenType::keywords, parserOutput[i]});
        }
        else if (std::regex_search(parserOutput[i], integerRegex))
        {
            this->tokenizerOutput.push_back(token{tokenType::integer, parserOutput[i]});
        }
        else
        {
            this->tokenizerOutput.push_back(token{tokenType::identifier,parserOutput[i]});
        }
    }
}

lexMachine::lexMachine(std::vector<u1> bytes)
{
    this->parseBytes(bytes);
    this->tokenize(this->parserOutput);
}

lexMachine::~lexMachine()
{
}

std::vector<token> lexMachine::returnTokens()
{
    return this->tokenizerOutput;
}
