#pragma once

#ifndef COMMON_H
#define COMMON_H

struct Pos {
    int line;
    int col;
    const char* filename;
};

#define NUMERIC_CASE \
    case '0':       \
    case '1':       \
    case '2':       \
    case '3':       \
    case '4':       \
    case '5':       \
    case '6':       \
    case '7':       \
    case '8':       \
    case '9'


#endif
    

