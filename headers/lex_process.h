#pragma once

#include "token.h"

class lex_process;

typedef char (*LEX_PROCESS_NEXT_CHAR) (lex_process* process);
typedef char (*LEX_PROCESS_PEEK_CHAR) (lex_process* process);
typedef void (*LEX_PROCESS_PUSH_CHAR) (lex_process* process, char c);

struct lex_process_functions {
    LEX_PROCESS_NEXT_CHAR next_char;
    LEX_PROCESS_PEEK_CHAR peek_char;
    LEX_PROCESS_PUSH_CHAR push_char;
};

enum class lex_status {
    LEXICAL_ANALYSIS_OK,
    LEXICAL_ANALYIS_INPUT_ERROR
};


class lex_process {

public:
    Pos pos;
    compile_process* compiler;
    int current_expression_count;
    lex_process_functions* function;
    std::vector<token> token_vec;
    void* priv; //private stuff to this process

public:
    
    lex_process(compile_process* compiler, lex_process_functions* functions, void* priv);
    ~lex_process();

    void* get_priv ();

    std::vector<token> get_lex_process_tokens();
    void push_token(token tkn);


};



