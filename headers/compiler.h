#pragma once
#ifndef MY_COMPILER_H
#define MY_COMPILER_H


#include <fstream>
#include <iostream>
#include <vector>
#include "compile_process.h"
#include "common.h"
#include "lex_process.h"
#include "lex_functions.h"
#include "token.h"



void compiler_error(compile_process* compiler, const char* msg, ...);
void compiler_warning(compile_process* compiler, const char* msg, ...);

lex_status lex(lex_process* process);

compile_status compile_file (const char* filename, const char* out_filename, int flags);

#endif
