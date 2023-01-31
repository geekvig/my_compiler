#include <fstream>
#include <iostream>
#ifndef MY_COMPILER_H
#define MY_COMPILER_H

enum class compile_status {
    COMPILER_FAILED_WTIH_ERRORS,
    COMPILER_FILE_COMPILED_OK
};

struct compile_process_input_file {
    std::ifstream* fp;
    const char* abs_path;
};

struct compile_process {
    int flags; // lets us know how the file is going to be compiled
    compile_process_input_file ifile;
    std::ofstream* ofile;
};

compile_status compile_file (const char* filename, const char* out_filename, int flags);
compile_process* compile_process_create(const char* filename_in, const char* filename_out, int flags);

#endif
