#include "../src/lib.h"
#include <stdlib.h>
#include <check.h>

START_TEST(test_slov) {
    char* input_data = "I am fan is football club Barcelona";
    int expected_value_get_Min_Length = 1;
    int actual_value_get_Min_Length = get_Min_Length(input_data, (int)strlen(input_data));
    int expected_value_get_Max_Length = 9;
    int actual_value_get_Max_Length = get_Max_Length(input_data, (int)strlen(input_data));

    ck_assert_int_eq(expected_value_get_Min_Length, actual_value_get_Min_Length);
    ck_assert_int_eq(expected_value_get_Max_Length, actual_value_get_Max_Length);
}
END_TEST


int main(void) {
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("Lab13");

	tcase_add_test(tc_core, test_slov);
	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int err = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (err == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}