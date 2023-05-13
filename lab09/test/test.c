#include "../src/lib.h"
#include <check.h>
#include <string.h>

	START_TEST(test_num_to_char) {
	#define DATA_SIZE_num_to_char 3
		int input_data[] = { 1, 22, 9999};
		char* expected_values[] = { "one ", "twenty two ", "nine thousand nine hundred ninety nine "};

		for (int i = 0; i < DATA_SIZE_num_to_char; i++) {
			char* actual_value = num_to_char(input_data[i]);
			ck_assert(strcmp(actual_value, expected_values[i]) == 0);
		}
	}
	END_TEST


	START_TEST(test_ammount) {
	#define DATA_SIZE_ammount 3
		int input_data[] = { 1, 22, 9999};
		int expected_values[] = { 1, 2, 4 };

		for (int i = 0; i < DATA_SIZE_ammount; i++) {
			int actual_value = ammount(input_data[i]);
			ck_assert_int_eq(expected_values[i], actual_value);
		}
	}
	END_TEST


	START_TEST(test_summ) {
	#define DATA_SIZE_summ 3
		int input_data[] = { 1, 22, 9999};
		int expected_values[] = { 1, 4, 36 };

		for (int i = 0; i < DATA_SIZE_summ; i++) {
			int actual_value = summ(input_data[i]);
			ck_assert_int_eq(expected_values[i], actual_value);
		}
	}
	END_TEST

	int main(void)
	{
		Suite *s = suite_create("Programing");
		TCase *tc_core = tcase_create("lab09");

		tcase_add_test(tc_core, test_num_to_char);
		tcase_add_test(tc_core, test_ammount);
		tcase_add_test(tc_core, test_summ);
		suite_add_tcase(s, tc_core);

		SRunner *sr = srunner_create(s);
		srunner_run_all(sr, CK_VERBOSE);
		int number_failed = srunner_ntests_failed(sr);
		srunner_free(sr);

		return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
	}