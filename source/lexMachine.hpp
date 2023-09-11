#pragma once
#include <vector>
#include <string>
#include "define.hpp"
#include "token.hpp"
#include <regex>

struct constLexData {
    std::wstring keywordRegex = L"ВЫБРАТЬ|ГДЕ|ЗАПИСЬ|ЗАГРУЗ|СБРОС";
    std::wstring integerRegex = L"[0-9]+";
    std::wstring logicRegex = L"&&|\\||\\|==|!=|>=|<=|>|<";
};

class lexMachine
{
private:
    constLexData internalData;
    std::vector<std::wstring> parserOutput;
    std::vector<token> tokenizerOutput;
    void parseBytes(std::vector<u1> bytes);
    void tokenize(std::vector<std::wstring> parserOutput);
public:
    lexMachine(std::vector<u1> bytes);
    ~lexMachine();
    std::vector<token> returnTokens();
};