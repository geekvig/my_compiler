#include <iostream>
#include "compiler.h"

int main() {

    auto ret = compile_file("test.cpp", "test", 0);
    if (ret == compile_status::COMPILER_FILE_COMPILED_OK) {
        std::cout << "Compile clean" << std::endl;
    }
    else {
        std::cout << "Compile failed" << std::endl;
    }

    return 0;
    
}