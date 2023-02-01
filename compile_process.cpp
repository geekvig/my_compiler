#include "headers/compiler.h"

compile_process::compile_process(const char* filename_in, const char* filename_out, int flags) {

    std::ifstream* in_file_p = new std::ifstream(filename_in);
    if (!in_file_p) {
        std::cout << "[Error Opening Input File]" << filename_in << std::endl;
    }
    else std::cout << "in file = " << filename_in << std::endl;

    std::ofstream* out_file_p = new std::ofstream(filename_out);
    if (!out_file_p) {
        std::cout << "[Error Opening Output File]" << filename_out << std::endl;

    }
    else std::cout << "out file = " << filename_out << std::endl;

    this->flags = flags;
    this->ifile.fp = std::move(in_file_p);
    this->ofile = std::move(out_file_p);
}

