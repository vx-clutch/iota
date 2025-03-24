#include "error.h"

void
pnotef(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  fprintf(stderr, "%s%s%s: %snote%s: ", WHITE, PACKAGE_NAME, RESET, BLUE,
          RESET);
  vfprintf(stderr, format, args);
  fprintf(stderr, "\n");
  va_end(args);
}
