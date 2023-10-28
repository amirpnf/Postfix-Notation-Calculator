#ifndef __LINES_H__
#define __LINES_H__

typedef enum {
    QUIT,
    PRINT,
    CLEAR,
    ALL,
    REVERSE,
    FINISH,
    NONE,
} Response;

int options(char* input);
void line_parser(char* input);

#endif