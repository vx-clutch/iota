// Copyright (C) 2025 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include "parse_args.h"
#include "config.h"
#include "options.h"
#include "syslog/error.h"
#include <getopt.h>
#include <stdio.h>
#include <string.h>

#define langcmp(k, p)                                                          \
  if (strcmp(lang_arg, k))                                                     \
  {                                                                            \
    options.language = p;                                                      \
    found++;                                                                   \
    selected = k;                                                              \
  }

__options options = {
    .verbose = 0,
    .debug = 0,
    .git = 0,
    .l_bsd = 0,
    .l_gpl = 0,
    .l_mit = 0,
    .no_build = 0,
    .no_markdown = 0,
    .name = "",
    .language = DEFAULT,
};

void
print_help();
void
print_version();

int
parse_args(int argc, char **argv)
{
  int opt, option_index = 0;
  struct option long_options[] = {
      {"version", no_argument, 0, 1}, {"help", no_argument, 0, 2},
      {"debug", no_argument, 0, 3},   {"git", no_argument, 0, 4},
      {"Lbsd", no_argument, 0, 5},    {"Lgpl", no_argument, 0, 6},
      {"Lmit", no_argument, 0, 7},    {0, 0, 0, 0}};
  opterr = 0;

  // manual parse for '-no-build' and '-no-markdown'
  for (int i = 1; i < argc; i++)
  {
    pdebugf("manual parse", "%d", i);
    if (argv[i][0] == '-' && strncmp(argv[i], "-no-markdown", 12) == 0)
    {
      plogf(OK "Found -no-markdown");
      options.no_markdown = 1;
      argv[i] = NULL;
    }
    else if (argv[i][0] == '-' && strncmp(argv[i], "-no-build", 9) == 0)
    {
      plogf(OK "Found -no-build");
      options.no_build = 1;
      argv[i] = NULL;
    }
  }

  while ((opt = getopt_long(argc, argv, "v", long_options, &option_index)) !=
         -1)
  {
    plogf(INFO "opt: '%s'", argv[optind - 1]);
    switch (opt)
    {
    case 'v':
      options.verbose = 1;
      break;
    case 1:
      print_version();
      return 0;
    case 2:
      print_help();
      return 0;
    case 3:
      options.debug = 1;
      break;
    case 4:
      options.git = 1;
      break;
    case 5:
      options.l_bsd = 1;
      break;
    case 6:
      options.l_gpl = 1;
      break;
    case 7:
      options.l_mit = 1;
      break;
    case 8:
      options.no_markdown = 1;
      break;
    case 9:
      options.no_build = 1;
      break;
    case '?':
      plogf(FAIL "unrecognized command-line argument '%s'", argv[optind]);
      return 1;
    default:
      plogf(FAIL "unrecognized command-line argument '%s'", argv[optind]);
      return 1;
    }
  }

  options.__parsed = 1;
  plogf(INFO "checking positional arguments.");
  if (optind >= argc)
  {
    pfatalf("no positional arguments.");
    return 1;
  }

  if (argc - optind < 1)
  {
    pfatalf("not enough arguments");
    return 1;
  }

  options.name = argv[optind++];
  char *lang_arg = argv[optind++];
  int found;
  char *selected;

  plogf(INFO "Project name was set to %s", options.name);

  langcmp("c", C);
  langcmp("cpp", CXX);
  langcmp("cxx", CXX);
  langcmp("py", PYTHON);
  langcmp("python", PYTHON);
  if (!found)
    plogf(FAIL "Could not find language using DEFAULT");
  else
    plogf(INFO "Project language was set to %s", selected);
  return 0;
}

void
print_help(void)
{
  printf("Usage: iota [options] file...\n\n");
  printf("Options:\n");
  printf("  --git\t\tInitialize git repository.\n");
  printf("  --help\tPrints out the help and exit.\n");
  printf("  --version\tPrints out the version number and exit.\n");
  printf("  --Lbsd\tAdds the BSD license to the project.\n");
  printf("  --Lgpl\tAdds the GPL license to the project.\n");
  printf("  --Lmit\tAdds the MIT license to the project.\n");
  printf("  --no-build\tDisable build system.\n");
  printf("  --no-markdown\tReplace README.md with a text file version.\n");
  printf("  -v\t\tEnables verbose output.\n");
}

void
print_version()
{
  plogf(INFO "call to print_version");
  printf(
      "vtc (VTC) %s 2024-%d (%s)\nCopyright (C) %d vx-clutch\nThis is free "
      "software; see the source for copying conditions. There is NO\nwarranty; "
      "not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE\n",
      PACKAGE_VERSION, COPYRIGHT_YEAR, PLATFORM, COPYRIGHT_YEAR);
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
