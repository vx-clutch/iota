AC_INIT([iota], [1.0], [owestness@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

# AC_DEFINE([FORCE_VERBOSE], [], [Force iota into verbose mode regardless of flags])
AC_DEFINE([COPYRIGHT_YEAR], [2025], [Current copyright year])

platform="$(uname -o) $(uname -r)"
AC_DEFINE_UNQUOTED([PLATFORM], ["$platform"], [Sets the platform that this is being compiled on])

EMAIL="$(git config user.email)"
AC_DEFINE_UNQUOTED([EMAIL], ["$EMAIL"], [Sets the email of the user who compiled this])

AC_PROG_CC
AC_CONFIG_HEADERS([iota/config.h])
AC_CONFIG_FILES([
  Makefile
  iota/Makefile
])
AC_OUTPUT
