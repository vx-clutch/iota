#include "base.h"
#include "../syslog/error.h"
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat st = {0};

#define exists                                                                 \
  if (err != 0)                                                                \
  pfatalf("Failure while trying to either write file or directory")

int
b_write()
{
  FILE *fp;
  int err;
  if (stat(options.name, &st) == -1)
  {
    err = mkdir(options.name, 0700);
    exists;
  }
  else
    pfatalf("Directory with the name %s already exists", options.name);
  err = chdir(options.name);
  exists;
  fp = fopen("AUTHORS", "w");
  fp = fopen("INSTALL", "w");
  if (!options.no_markdown)
  {
    fp = fopen("README.md", "w");
    err = fprintf(fp, "# %s", options.name);
    exists;
  }
  else
    fp = fopen("README", "w");
  err = mkdir(options.name, 0700);
  exists;
  return 0;
}
