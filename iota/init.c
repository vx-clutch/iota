#include "init.h"
#include "syslog/error.h"

char *
getext(lang_t lang) {
  switch (lang) {
    case LANG_DEFAULT: return "";
    #define lang(name, src) case LANG_##name: return #name;
#include "language.objects/clang.lo"
    #undef lang
    case LANG_COUNT: pfatalf("getext called with LANG_COUNT.");
  }
  pfatalf("unrecoverable state in 'getext'.");
  __builtin_unreachable();
}
