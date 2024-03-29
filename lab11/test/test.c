#include "../src/lib.h"
#include <check.h>

START_TEST(test_get_num) {
	char* input_data = "42253339774";
	char* expected_values = "223377";
	ck_assert_char_eq(expected_values, input_data);
}
END_TEST

int main(void) {
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("Lab11");

	tcase_add_test(tc_core, test_get_num);
	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}