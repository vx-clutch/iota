#include "options.h"
#include "syslog/error.h"
#include <stdbool.h>

char *
tostring(lang_t src, bool getext)
{
  switch (src)
  {
  case C:
    return getext ? "c" : "C";
  case CC:
    return getext ? "cc" : "CC";
  case PYTHON:
    return getext ? "py" : "PYTHON";
  case DEFAULT:
    return getext ? "" : "DEFAULT";
  }
  pfatalf("unrecoverable state in `tostring`");
  __builtin_unreachable();
}