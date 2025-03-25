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
      {"version", no_argument, 0, 1},  {"help", no_argument, 0, 2},
      {"debug", no_argument, 0, 3},    {"git", no_argument, 0, 4},
      {"Lbsd", no_argument, 0, 5},     {"Lgpl", no_argument, 0, 6},
      {"Lmit", no_argument, 0, 7},     {"no-markdown", no_argument, 0, 8},
      {"no-build", no_argument, 0, 9}, {0, 0, 0, 0}};
  opterr = 0;

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

  langcmp("c", C) langcmp("cpp", CXX) langcmp("cxx", CXX) langcmp("py", PYTHON)
      langcmp("python", PYTHON)

          if (!found) plogf(FAIL "Could not find language using DEFAULT");
  else plogf(INFO "Project language was set to %s", selected);
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
