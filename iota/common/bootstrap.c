// Copyright (C) 2025 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include "bootstrap.h"
#include "../syslog/error.h"
#include "templates.h"
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat st = {0};

int
bootstrap()
{
  assert(options.name != NULL);
  FILE *fp;
  int err;
  if (stat(options.name, &st) == -1)
  {
    mkdir(options.name, 0700);
    pdebugf("write", "project root directory");
  }
  else
    pfatalf("directory with the name %s already exists.", options.name);
  chdir(options.name);
  plogf(INFO "idk what happening");
  perrorf(strerror(errno));
  fp = fopen("AUTHORS", "w");
  fp = fopen("INSTALL", "w");

  if (!options.no_markdown)
  {
    fp = fopen("README.md", "w");
    if (!fp) pfatalf("Failed to open README.md for writing");
    fprintf(fp, "# %s", options.name);
    fclose(fp);
    pdebugf("write", "README.md");
  }
  else if (options.no_markdown)
  {
    fp = fopen("README", "w");
    if (!fp) pfatalf("Failed to open README for writing");
    fprintf(fp, "%s", options.name);
    fclose(fp);
    pdebugf("write", "README");
  }

  mkdir(options.name, 0700);
  pdebugf("write", "source directory");
  chdir(options.name);
  pdebugf("change to", options.name);

  char *prefix = "main.";
  char *path = malloc(strlen(prefix) + strlen(tostring(options.language)));
  strcpy(path, prefix);
  if (options.language == PYTHON)
    strcat(path, "py");
  else
    strcat(path, tostring(options.language));
  fp = fopen(path, "w");
  pdebugf("language index", "%d", options.language);
  fprintf(fp, "%s", __SOURCE[options.language]);
  pdebugf("write", "%s source code", tostring(options.language));
  fclose(fp);
  /* before returning it is important to set the current working directory back
   * to the root directory of the project because if other function need to
   * write files (aminit.c) they can be certain that they are starting from the
   * right place */
  chdir(".."); // sets the current working directory to the root level
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
