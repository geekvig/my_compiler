#include "compiler.h"

compile_status compile_file (const char* filename, const char* out_filename, int flags) {
    compile_process* process = compile_process_create(filename, out_filename, flags);
    if (!process) {
        std::cout << " failed process" << std::endl;
        return compile_status::COMPILER_FAILED_WTIH_ERRORS;
    }
    else {
        std::cout << "Compile successfully" << std::endl;
    }
    return compile_status::COMPILER_FILE_COMPILED_OK;
}

