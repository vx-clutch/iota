// Copyright (C) 2025 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include "aminit.h"
#include "options.h"
#include "syslog/error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _GIT_EMAIL
#define _GIT_EMAIL "example@gmail.com"
#endif

int
configure()
{
  FILE *fp;
  fp = fopen("configure.ac", "w"); // while at the root level of the project
  fprintf(fp,
          "AC_INIT([%s], [1.0], [%s])\nAM_INIT_AUTOMAKE([-Wall "
          "-Werror foreign "
          "subdir-objects])\n\nAC_PROG_CC\nAC_CONFIG_HEADERS([%s/"
          "config.h])\nAC_CONFIG_FILES([\n\tMakefile\n\t%s/"
          "Makefile\n])\nAC_OUTPUT",
          options.name, _GIT_EMAIL, options.name, options.name);
  fclose(fp);
  return 0;
}

int
makefile()
{
  FILE *fp;
  fp = fopen("Makefile.am", "w"); // while at the root level of the project
  if (options.no_markdown)
    fprintf(fp, "SUBDIRS = %s/\ndist_doc_DATA = README", options.name);
  else
    fprintf(fp, "SUBDIRS = %s/\ndist_doc_DATA = README.md", options.name);

  const char *suffix = "/Makefile.am";
  size_t len = strlen(options.name) + strlen(suffix) + 1;
  char *path = malloc(len);
  if (!path) pfatalf("Malloc failed");
  strcpy(path, options.name);
  strcat(path, suffix);

  fp = fopen(path, "w");
  pdebugf("fp", path);
  if (!fp)
    pfatalf("could not open file.");
  printf("bin_PROGRAMS = %s\n%s_SOURCES = main.c", options.name,
          options.name);
  free(path);
  fclose(fp);
  return 0;
}

int
aminit()
{
  /* run the autotools commands */

  // autoreconf -i && ./configure
  // these need to be status checks
  configure();
  makefile();
  int status = system("autoreconf -i && ./configure > /dev/null 2>&1");
  if (status == -1) return -1;

  return 0;
}

/* iota is an opinionated init tool.
 * Copyright (C) 2025 vx-clutch
 *
 * The file is part of iota.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions, and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions, and the following disclaimer in the documentation or
 * other materials provided with the distribution.
 * 3. Neither the name of vx-clutch nor the names of its contributors may be
 * used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
