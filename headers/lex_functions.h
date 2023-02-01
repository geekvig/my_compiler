#pragma once


char compile_process_next_char(lex_process* lex_process);
char compile_process_peek_char(lex_process* lex_process);
void compile_process_push_char(lex_process* lex_process, char c);
