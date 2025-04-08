#ifndef INIT_H
#define INIT_H

typedef enum {
#define new(src, ...) src
#define lang(name, src) LANG_##name,
  LANG_DEFAULT = 0,
#include "language.objects/clang.lo"
#undef lang
#undef new
  LANG_COUNT,
} lang_t;

static const char *LANG_SRC[LANG_COUNT] = {
    [LANG_DEFAULT] = "",
#define new(_src, ...) _src
#define lang(name, src) [LANG_##name] = src,
#include "language.objects/clang.lo"
#undef lang
#undef new
};

char *tostring(lang_t);

#endif
