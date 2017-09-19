#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)

m4_define([PACKAGE_MAJOR_VERSION], [1])
m4_define([PACKAGE_MINOR_VERSION], [7])
m4_define([PACKAGE_PATCH_VERSION], [0])

AC_INIT(json,[PACKAGE_MAJOR_VERSION.PACKAGE_MINOR_VERSION.PACKAGE_PATCH_VERSION])
AM_INIT_AUTOMAKE(json,[PACKAGE_MAJOR_VERSION.PACKAGE_MINOR_VERSION.PACKAGE_PATCH_VERSION])
AC_CONFIG_SRCDIR([src/json.c])
AC_CONFIG_HEADER([config.h])

CXX=no
F77=no

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_LIBTOOL

# Checks for libraries.
AM_PATH_CHECK(,[have_check="yes"],
  AC_MSG_WARN([Check not found; cannot run unit tests!])
  [have_check="no"])
AM_CONDITIONAL(HAVE_CHECK, test x"$have_check" = "xyes")

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([locale.h memory.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset setlocale])

# The pkgconfig file
MILESTONE=PACKAGE_MAJOR_VERSION.PACKAGE_MINOR_VERSION
AC_SUBST([MILESTONE])
AC_CONFIG_FILES([mjson.pc])

AC_CONFIG_FILES([Makefile
		 src/Makefile
		 tests/Makefile])
AC_OUTPUT
