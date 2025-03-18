#ifndef OPT_H
#define OPT_H

#include <stdio.h>
#include <stdint.h>

typedef struct 
{
    uint8_t verbose;
    uint8_t debug;
} __options;

extern __options options;

#endif