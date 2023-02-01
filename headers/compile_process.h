#pragma once
#include "common.h"

struct compile_process_input_file {
    std::ifstream* fp;
    const char* abs_path;
};

enum class compile_status {
    COMPILER_FAILED_WTIH_ERRORS,
    COMPILER_FILE_COMPILED_OK
};

class compile_process {

public:  
    Pos pos;
    compile_process_input_file ifile;
    std::ofstream* ofile;
    int flags; // lets us know how the file is going to be compiled

public: 
    compile_status status;

public:
    compile_process(const char* filename_in, const char* filename_out, int flags);


};