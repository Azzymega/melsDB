#pragma once
#include <fstream>
#include <string>
#include "table.hpp"
#include "tableFile.hpp"
#include <iostream>

class iomanager {
private:
    std::ifstream readStream;
    std::ofstream writeStream;
    u2 loadU2();
    u4 loadU4();
    u1 loadU1();
    void closeReadStream();
    void closerWriteStream();
    void outputTable(tableFile* file);
    tableFile* inputTable();
public:
    void openReadStream(std::wstring path);
    void openWriteStream(std::wstring path);
    void writeTable(table selectedTable);
    table readTable();
};