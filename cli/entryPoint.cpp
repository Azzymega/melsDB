#include <iostream>
#include <vector>
#include "../source/vm.hpp"
#include "../source/interpreter.hpp"

int main() {
    marxVM vm = marxVM();
    interpreter inter = interpreter();
    inter.initInterpretation(&vm);
    return 0;
}