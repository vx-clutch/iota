#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"
#include "syslog/error.h"

static int is_build(lang_t lang) {
  const char *name = tostring(lang);
  return strncmp(name, "build_", 6) == 0;
}

void build(void) {
  for (lang_t lang = 0; lang < LANG_COUNT; ++lang) {
    if (!is_build(lang))
      continue;

    const char *name = tostring(lang) + 6; // Skip "build_"
    const char *content = LANG_SRC[lang];

    FILE *f = fopen(name, "w");
    if (!f) {
      pfatalf("could not open %s for writing", name);
    }

    if (fputs(content, f) == EOF) {
      fclose(f);
      pfatalf("failed to write to %s", name);
    }

    fclose(f);
  }

  int code = system(PRE_BUILD_CMD);
  if (code != 0) {
    pfatalf("pre_build command failed with code %d", code);
  }
}
