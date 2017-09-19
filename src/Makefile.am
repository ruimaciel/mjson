# set the include path found by configure
INCLUDES = $(all_includes)

lib_LTLIBRARIES=libmjson.la

mjsondir=$(includedir)/mjson-$(MILESTONE)
mjson_HEADERS = json.h json_helper.h
libmjson_la_LDFLAGS=-release $(MILESTONE)
libmjson_la_SOURCES=\
	$(mjson_HEADERS) \
	json.c \
	json_helper.c \
	$(NULL)
