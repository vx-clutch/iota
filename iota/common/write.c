#include "write.h"

#include <stdio.h>
#include <stdarg.h>
#include "../syslog/error.h"

int
write(char *path, char *src, ...)
{
  va_list args;
  va_start(args, src);
  FILE *fp;
  fp = fopen(path, "w");
  if (!fp) pfatalf("Failed to open %s.", path);
  fprintf(fp, src, args);
  va_end(args);
  return 0;
}
