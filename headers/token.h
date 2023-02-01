#pragma once
#include "common.h"

#ifndef TOKEN_H
#define TOKEN_H


enum class TOKEN_TYPE {
    IDENTIFIER,
    KEYWORD,
    OPERATOR,
    SYMBOL,
    NUMBER,
    STRING,
    COMMENT,
    NEWLINE
};


struct token
{
    TOKEN_TYPE type;
    int flags;
    Pos pos;
    union 
    {
        char cval;
        const char* sval;
        unsigned int inum;
        unsigned long lnum;
        unsigned long long llnum;
        void* any;
    };
    bool whitespace; // isthere a white space between this token and the next token 
    const char* between_brackets;
};

#endif