#include "headers/compiler.h"

lex_process::lex_process(compile_process* compiler, lex_process_functions* functions, void* priv) {
    this->function = functions;
    this->compiler = compiler;
    this->priv = priv;
    this->pos.line = 1;
    this->pos.col  = 1;
}

lex_process::~lex_process() {
    free(this);
}

void* lex_process::get_priv () {
    return priv;
}

std::vector<token> lex_process::get_lex_process_tokens() {
    return token_vec;
}

void lex_process::push_token(token tkn) {
    this->token_vec.push_back(tkn);
}