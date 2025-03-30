// Copyright (C) 2025 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include "bootstrap.h"
#include "../syslog/error.h"
#include "templates.h"
#include <assert.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat st = {0};

#define errh                                                                   \
  if (err) pdebugf("bootstrap", "%d", err);                                    \
  pfatalf("Something went fataly wrong.")

int
bootstrap()
{
  assert(options.name != NULL);
  FILE *fp;
  int err;
  if (stat(options.name, &st) == -1)
  {
    err = mkdir(options.name, 0700);
    errh;
    pdebugf("write", "project root directory");
  }
  else
    pfatalf("Directory with the name %s already debug", options.name);
  err = chdir(options.name);
  errh;
  fp = fopen("AUTHORS", "w");
  fp = fopen("INSTALL", "w");

  if (!options.no_markdown)
  {
    fp = fopen("README.md", "w");
    err = fprintf(fp, "# %s", options.name);
    errh;
    fclose(fp);
    pdebugf("write", "README.md");
  }
  else if (options.no_markdown)
  {
    fp = fopen("README", "w");
    err = fprintf(fp, "%s", options.name);
    errh;
    fclose(fp);
    pdebugf("write", "README");
  }

  err = mkdir(options.name, 0700);
  errh;
  pdebugf("write", "source directory");
  err = chdir(options.name);
  errh;
  pdebugf("change to", options.name);
  switch (options.language)
  {
  case C:
    fp = fopen("main.c", "w");
    err = fprintf(fp, __C_DEFAULT_SORCE_CODE);
    errh;
    break;
  case CPP:
    fp = fopen("main.cc", "w");
    err = fprintf(fp, __CC_DEFAULT_SORCE_CODE);
    errh;
    break;
  case PYTHON:
    fp = fopen("main.py", "w");
    err = fprintf(fp, __PYTHON_DEFAULT_SORCE_CODE);
    errh;
    break;
  case DEFAULT:
    fp = fopen(".keep", "w");
    break;
  default:
    pfatalf("Unrecoverable state");
  }
  fclose(fp);
  /* before returning it is important to set the current working directory back
   * to the root directory of the project because if other function need to
   * write files (aminit.c) they can be certain that they are starting from the
   * right place */
  err = chdir(".."); // sets the current working directory to the root level
  errh;
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
