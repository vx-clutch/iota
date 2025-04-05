// Copyright (C) 2025 TiredWithJoy (  )
// See end of file for extended copyright information.

#ifndef OPT_H
#define OPT_H

#include <stdint.h>
#include <stdio.h>

typedef enum
{
  DEFAULT = 0,
  C,       
  CPP,    
  PYTHON,
  COUNT,
} lang_t;

typedef struct
{
  uint8_t __parsed;
  uint8_t verbose;
  uint8_t debug;
  uint8_t git;
  uint8_t l_bsd;
  uint8_t l_gpl;
  uint8_t l_mit;
  uint8_t no_build;
  uint8_t no_markdown;
  char *name;
  lang_t language;
} __options;

#define _SIZE__ABSOLUTE_PATH 1024
static char absolute_path[_SIZE__ABSOLUTE_PATH];

static char *
tostring(lang_t src)
{
  if (src == C) return "C";
  if (src == CPP) return "CPP";
  if (src == PYTHON) return "PYTHON";
  if (src == DEFAULT) return "DEFAULT";
  return NULL;
}

extern __options options;
extern char absolute_path[];

#endif

/* iota is an opinionated init tool.
 * Copyright (C) 2025 TiredWithJoy
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
