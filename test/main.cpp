#include <iostream>
#include <vector>
#include "../source/vm.hpp"
#include "locale.h"
#include <io.h>
#include <fcntl.h>
#include "../source/interpreter.hpp"

// TESTS
int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);
    marxVM vm = marxVM();
    interpreter inter = interpreter();
    inter.initInterpretation(&vm);
    return 0;
}