#include "error.h"
#include <stdarg.h>

void
plogf(const char *op, const char *format, ...)
{
  if (!options.verbose) return;
  va_list args;
  va_start(args, format);
  printf(" %s\t");
  vprintf(format, args);
  putchar('\n');
  va_end(args);
}
