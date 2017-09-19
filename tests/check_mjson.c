/***************************************************************************
 *   Copyright (C) 2015 by Rui Maciel   *
 *   rui.maciel@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <stdlib.h>
#include <check.h>
#include <json.h>


START_TEST(test_parser_empty_object_document)
{
	struct json_parsing_info parsing_info;

	json_jpi_init(&parsing_info);
	enum json_error error;
	const char * json_document = "{}\n";
	error = json_parse_document (&parsing_info, json_document);

	ck_assert_int_eq(error, JSON_OK);
}
END_TEST


START_TEST(test_parser_logical_document)
{
	struct json_parsing_info parsing_info;

	json_jpi_init(&parsing_info);
	enum json_error error;
	const char * json_document = "{\"foo\":true, \"bar\":false}\n";
	error = json_parse_document (&parsing_info, json_document);

	ck_assert_int_eq(error, JSON_OK);
}
END_TEST


START_TEST(test_parser_numerical_document)
{
	struct json_parsing_info parsing_info;

	json_jpi_init(&parsing_info);
	enum json_error error;
	const char * json_document = "{\"foo\":1, \"bar\":1.0, \"baz\":-1e-10}\n";
	error = json_parse_document (&parsing_info, json_document);

	ck_assert_int_eq(error, JSON_OK);
}
END_TEST


START_TEST(test_parser_string_document)
{
	struct json_parsing_info parsing_info;

	json_jpi_init(&parsing_info);
	enum json_error error;
	const char * json_document = "{\"foo\":\"bar\", \"bar\":\"baz\"}\n";
	error = json_parse_document (&parsing_info, json_document);

	ck_assert_int_eq(error, JSON_OK);
}
END_TEST


START_TEST(test_parser_array_document)
{
	struct json_parsing_info parsing_info;

	json_jpi_init(&parsing_info);
	enum json_error error;
	const char * json_document = "{\"foo\":[1,2,3,4]\n}\n";
	error = json_parse_document (&parsing_info, json_document);

	ck_assert_int_eq(error, JSON_OK);
}
END_TEST


START_TEST(test_parser_object_document)
{
	struct json_parsing_info parsing_info;

	json_jpi_init(&parsing_info);
	enum json_error error;
	const char * json_document = "{\"foo\":{\"bar\":1, \"baz\":2}\n}\n";
	error = json_parse_document (&parsing_info, json_document);

	ck_assert_int_eq(error, JSON_OK);
}
END_TEST


Suite * parser_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Parser");

	/* Core test case */
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_parser_empty_object_document);
	tcase_add_test(tc_core, test_parser_logical_document);
	tcase_add_test(tc_core, test_parser_numerical_document);
	tcase_add_test(tc_core, test_parser_string_document);
	tcase_add_test(tc_core, test_parser_array_document);
	tcase_add_test(tc_core, test_parser_object_document);
	suite_add_tcase(s, tc_core);

	return s;
}


int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = parser_suite();
	sr = srunner_create(s);

	/* test logs */
	srunner_set_log (sr, "test.log");

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

