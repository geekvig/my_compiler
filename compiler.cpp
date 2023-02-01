#include "headers/compiler.h"
#include "stdarg.h"

lex_process_functions compiler_lex_functions {
    .next_char = compile_process_next_char,
    .peek_char = compile_process_peek_char,
    .push_char = compile_process_push_char
};

void compiler_error(compile_process* compiler, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    std::cerr << msg << std::endl;
    va_end(args);
    std::cerr << " on line " << compiler->pos.line << "  col " << compiler->pos.col << "  in file " << compiler->pos.filename << std::endl;
    return;
}


void compiler_warning(compile_process* compiler, const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    std::cerr << msg << std::endl;
    va_end(args);
    std::cerr << " on line " << compiler->pos.line << "  col " << compiler->pos.col << "  in file " << compiler->pos.filename << std::endl;
    return;
}

compile_status compile_file (const char* filename, const char* out_filename, int flags) {
    compile_process* process = new compile_process(filename, out_filename, flags);
    if (!process) {
        return compile_status::COMPILER_FAILED_WTIH_ERRORS;
    }

    lex_process* lex_proc =  new lex_process(process, &compiler_lex_functions, nullptr);
    if (!lex_proc) {
        std::cout << "[Error] Creating Lex Proc" << std::endl;
    }

    if (lex(lex_proc) != lex_status::LEXICAL_ANALYSIS_OK) {
        std::cout << "lexing failed !" << std::endl;
    }
    return compile_status::COMPILER_FILE_COMPILED_OK;
}

