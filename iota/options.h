#ifndef OPT_H
#define OPT_H

#include <cstdint>
#include <stdio.h>
#include <stdint.h>

enum lang_t {
    C,
    CXX,
    PYTHON,
    DEFAULT,
};

typedef struct 
{
    uint8_t verbose;
    uint8_t debug;
    uint8_t git;
    uint8_t l_bsd;
    uint8_t l_gpl;
    uint8_t l_mit;
    uint8_t no_build;
    uint8_t no_markdown;
    uint8_t name;
    lang_t language;
} __options;

extern __options options;

#endif
