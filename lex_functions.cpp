#include "headers/compiler.h"


char compile_process_next_char(lex_process* lex_process) {
    compile_process* compiler = lex_process->compiler;
    compiler->pos.col += 1;
    std::ifstream& ifs = *(compiler->ifile.fp);
    char c; ifs.get(c);
    if (c == '\n') {
        compiler->pos.line += 1;
        compiler->pos.col   = 1;
    }
    return c;
}

char compile_process_peek_char(lex_process* lex_process) {
    compile_process* compiler = lex_process->compiler;
    std::ifstream& ifs = *(compiler->ifile.fp);
    char c; ifs.get(c);
    ifs.unget();
    return c;
}

void compile_process_push_char(lex_process* lex_process, char c) {
    compile_process* compiler = lex_process->compiler;
    std::ifstream& ifs = *(compiler->ifile.fp);
    ifs.putback(c);
}