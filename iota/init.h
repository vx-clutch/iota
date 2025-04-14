#ifndef INIT_H
#define INIT_H

#define INCLUDE_LANGUAGES #include "language.objects/clang.lo"

typedef enum
{
#define new(src, ...) src
#define lang(name, src) LANG_##name,
  LANG_DEFAULT = 0,
  INCLUDE_LANGUAGES
#undef lang
#undef new
      LANG_COUNT,
} lang_t;

static const char *LANG_SRC[LANG_COUNT] = {
    [LANG_DEFAULT] = "",
#define new(_src, ...) _src
#define lang(name, src) [LANG_##name] = src,
    INCLUDE_LANGUAGES
#undef lang
#undef new
};

#define new(_src, ...) _src
#define lang(name, src)
#define build(name, src)
#define prebuild(src) src
static const char *PRE_BUILD_CMD =
    INCLUDE_LANGUAGES
    "";
#undef lang
#undef build
#undef prebuild
#undef new

char *tostring(lang_t);

#endif
