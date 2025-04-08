#ifndef INIT_H
#define INIT_H

typedef enum {
#define lang(name, src) LANG_##name,
  LANG_DEFAULT = 0,
#include "language.objects/clang.lo"
#undef lang
  LANG_COUNT,
} lang_t;

static const char *LANG_SRC[LANG_COUNT] = {
  [LANG_DEFAULT] = "",
#define lang(name, src) [LANG_##name] = src,
#include "language.objects/clang.lo"
#undef lang
};

char *tostring(lang_t);

#endif
