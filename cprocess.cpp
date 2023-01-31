#include "compiler.h"

compile_process* compile_process_create(const char* filename_in, const char* filename_out, int flags) {

    std::ifstream* in_file_p = new std::ifstream(filename_in);
    if (!in_file_p) {
        std::cout << "[Error Opening Input File]" << filename_in << std::endl;
        return nullptr;
    }
    else std::cout << "in file = " << filename_in << std::endl;

    std::ofstream* out_file_p = new std::ofstream(filename_out);
    if (!out_file_p) {
        std::cout << "[Error Opening Output File]" << filename_out << std::endl;
        return nullptr;
    }
    else std::cout << "out file = " << filename_out << std::endl;

    compile_process* process = new compile_process;
    process->flags = flags;
    process->ifile.fp = in_file_p;
    process->ofile = out_file_p;
    return process;
}