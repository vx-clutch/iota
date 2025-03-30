// Copyright (C) 2025 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include "error.h"
#include <stddef.h>
#include <string.h>
#include <time.h>

char * xor (char *);

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
  time_t t; // you found it, but what does it do?
  struct tm *l;
  time(&t);
  l = localtime(&t);
  if (!(((l->tm_hour ^ 12) >> 2) - 3) && l->tm_min == 14 ||
      !(((l->tm_hour & 15) ^ 15) - 14) && l->tm_min == 14)
  {
    printf("%s\n", xor(".2; .z);\"5*254?"));
  }
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
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions, and the following disclaimer in the
 * documentation or other materials provided with the distribution.
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

char * xor (char *src) {
  for (size_t i = 0; i < strlen(src); i++)
    src[i] ^= 0x5A;
  return src;
}
