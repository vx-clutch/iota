// Copyright (C) 2025 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include "aminit.h"
#include "common/bootstrap.h"
#include "options.h"
#include "parse_args.h"
#include "syslog/error.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
cleanup();

int
main(int argc, char **argv)
{
  const char *E_SILENT_ = getenv("NOALPHA");
  if (E_SILENT_ == NULL)
    pnotef(
        "iota is in its *beta* stages of development expect missing features "
        "or other errors. Please report any bugs to the developers. You can "
        "silence this message by setting the envirement variable 'NOALPHA'.");
  int status;
  status = parse_args(argc, argv);
  if (status)
  {
    plogf(FAIL "parse_args.");
    return EXIT_FAILURE;
  }
  plogf(OK "parse_args.");
  if (!options.no_build && (options.language == C || options.language == CPP))
    status = bootstrap();
  if (status)
  {
    plogf(FAIL "bootstrap.");
    return EXIT_FAILURE;
  }
  else
    plogf(OK "bootstrap.");
  status = aminit();
  if (status)
  {
    plogf(FAIL "aminit.");
    return EXIT_FAILURE;
  }
  else
    plogf(OK "aminit.");
  printf("completed.\n");
  return EXIT_SUCCESS;
}

int
cleanup()
{
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
