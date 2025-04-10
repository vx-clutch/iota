// Copyright (C) 2025 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include "bootstrap.h"
#include "../init.h"
#include "../options.h"
#include "write.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int errno = 0;

int bootstrap() {
  assert(options.name != NULL);
  iota_mkdir(options.name);
  if (!options.dry) chdir(options.name);
  if (options.verbose || options.dry) printf(" CHDIR\t%s\n", options.name);
  
  iota_write("AUTHORS", "");
  iota_write("INSTALL", "");

  if (options.git) system("git init");

  if (!options.no_markdown)
    iota_write("README.md", "# %s", options.name);
  else if (options.no_markdown)
    iota_write("README", "%s", options.name);

  iota_mkdir(options.name);
  if (!options.dry)
    chdir(options.name);

  char *prefix = "main.";
  char *ext = tostring(options.language);
  size_t len = strlen(prefix) + strlen(ext);

  char *path = malloc(len);
  strcpy(path, prefix);
  strcat(path, ext);

  iota_write(path, "%s", LANG_SRC[options.language]);
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
