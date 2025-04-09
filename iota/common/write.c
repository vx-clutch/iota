#include "write.h"

#include "../syslog/error.h"
#include "write.h"
#include <stdarg.h>
#include <stdio.h>

int
iota_write(char *path, char *src, ...)
{
  if (options.dry)
  {
    printf(" CREATE  %s\n", path);
    return 0;
  }
  va_list args;
  va_start(args, src);
  FILE *fp;
  fp = fopen(path, "w");
  if (!fp) pfatalf("Failed to open %s.", path);
  printf(" CREATE  %s\n", path);
  fprintf(fp, src, args);
  fclose(fp);
  va_end(args);
  return 0;
}
