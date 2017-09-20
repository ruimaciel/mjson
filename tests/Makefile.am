TESTS = check_mjson
check_PROGRAMS = check_mjson

check_mjson_SOURCES = check_mjson.c
check_mjson_CFLAGS = -I$(top_srcdir)/src @CHECK_CFLAGS@
check_mjson_LDADD = $(top_builddir)/src/libmjson.la  @CHECK_LIBS@

