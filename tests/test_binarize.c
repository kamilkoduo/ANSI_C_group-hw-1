//
// Created by cubazis on 24.05.18.
//
#include <check.h>
#include "binarize.h"


#define COMPARATOR(res, c1, c2) do                    \
	{                                             \
		char i = 0;                           \
		for (;'\0' != (c1)[i];i++)            \
		{                                     \
			if((c1)[i] != (c2)[i])        \
				{                     \
                                        (res) = 0;    \
				}                     \
			else                          \
				{                     \
                                        (res) = 1;    \
				}                     \
		}                                     \
	} while(0)


START_TEST (test_bin_u)
    {
        unsigned long input = 1608637542;
        char* output = "01011111111000011101110001100110";

        char* res = binarize_u(input);
        int k = 1;

        COMPARATOR(k, res, output);
        ck_assert(k == 1);
    }
END_TEST

START_TEST (test_bin_s)
    {
        signed long x = -1608637542;
        char* output = "10100000000111100010001110011010";

        int k = 1;
        char* res = binarize_s(x);
        COMPARATOR(k, res, output);
        ck_assert(k == 1);
    }
END_TEST

Suite* str_suite (void) {
    Suite *suite = suite_create("binarize");
    TCase *tcase = tcase_create("case");
    tcase_add_test(tcase, test_bin_u);
    tcase_add_test(tcase, test_bin_s);
    suite_add_tcase(suite, tcase);
    return suite;
}

int main (int argc, char *argv[]) {
    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;
}