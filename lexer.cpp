#include "headers/compiler.h"
#include <cstring>
#include <string>
#include <memory>

static lex_process* lex_proc;
static token tmp_token;

#define LEX_GETC_IF(s, c, exp) \
    for (c = peekc(); exp; c = peekc()) \
    {                                   \
        (*s) += c;                          \
        nextc();                        \
    }                                   \



static char peekc () {
    return lex_proc->function->peek_char(lex_proc);
}

static char nextc()
{
    char c = lex_proc->function->next_char(lex_proc);
    lex_proc->pos.col += 1;
    if (c == '\n')
    {
        lex_proc->pos.line +=1;
        lex_proc->pos.col = 1;
    }

    return c;
}

static void pushc (char c) {
    return lex_proc->function->push_char(lex_proc, c);
}

static Pos lex_file_position(){
    return lex_proc->pos;
}

token* token_create(token* _token) {
    std::memcpy(&tmp_token, _token, sizeof(token));
    tmp_token.pos = lex_file_position();
    return &tmp_token;
}


std::string read_number_str()
{
    const char* num = NULL;
    std::string s = "";
    char c = peekc();
    LEX_GETC_IF(&s, c, (c >= '0' && c <= '9'));
    std::cout << s << std::endl;
    return s.c_str();
}

unsigned long long read_number()
{
    std::string s = read_number_str();
    std::cout << s << std::endl;
    return stoll(s);
}

token* token_make_number_for_value(unsigned long number)
{
    token temp = token{.type=TOKEN_TYPE::NUMBER,.llnum=number};
    return token_create(&temp);
}

token* token_make_number()
{
    return token_make_number_for_value(read_number());
}

token* read_next_token(){
    token* t = nullptr;
    char c = peekc();
    switch (c)
    {
        NUMERIC_CASE: 
        {
            t = token_make_number();
            break;
        }
        case EOF:
            break;
        case '\0': break;
        default:
            compiler_error(lex_proc->compiler, "Unexpected token");
    }
    return t;
}


lex_status lex(lex_process* process) {
    process->current_expression_count = 0;
    process->pos.filename = process->compiler->ifile.abs_path;
    lex_proc = process;
    token* tkn = read_next_token();
    while (tkn) {
        process->push_token(*tkn);
        tkn = read_next_token();
    }

    return lex_status::LEXICAL_ANALYSIS_OK;
}