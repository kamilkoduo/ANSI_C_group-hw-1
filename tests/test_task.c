//
// Created by cubazis on 25.05.18.
//

#include <check.h>
#include "task.h"


START_TEST (test_stub)
    {
        ck_assert(42 == stub());
    }
END_TEST

START_TEST (test_array_changer)
    {
        const char input[] = "abcba";
        const char pattern[] = "abbba";

        /** change 'c' to 'b' */

        char *output = array_changer(input);

        /** initialise k because ck_assert need's it to be sure
         *  that he compare something initialised with 1
         *  because if COMPARATOR will not change it value, k will not have any value
         *  */
        int k = 1;

        /** get k, k, output, pattern
         *  compare output array with pattern array by elements
         *  return 0 if they are not equal
         * */
        COMPARATOR(k, output, pattern);

        /** check statement is true */
        ck_assert(1 == k);

    }
END_TEST

/** YOUT TEST CASES HERE
 *
 *  please use 'test_fname' format for naming tcases
 *  fname is function name
 *
 *  if function name is 'detab' then test case is 'test_detab'
 * */

START_TEST (test_detab)
    {
        const char input[] = "\tabc\tdef\tghi";
        const char pattern[] = "    abc    def    ghi";
        char *output = detab(input);
        int k = 1;
        COMPARATOR(k, output, pattern);
        ck_assert(1 == k);
    }
END_TEST

START_TEST (test_entab)
    {
        const char input[] = "          1234     5          ";
        const char pattern[] = "\t\t  1234\t 5\t\t   ";
        char *output = entab(input);
        int k = 1;
        COMPARATOR(k, output, pattern);
        ck_assert(k == 1);
    }
END_TEST

START_TEST (test_enter1)
    {
        const char input[] =  "hellomydearfriend";
        const char output[] = "hello\nmydea\nrfrie\nnd";
        int n = 5;
        int k = 1;
        COMPARATOR(k, enter(n, input), output);
        ck_assert(1 == k);

    }
END_TEST

START_TEST (test_enter2)
    {
        const char input[] =  "";
        const char output[] = "";
        int n = 1;
        int k = 1;
        COMPARATOR(k, enter(n, input), output);
        ck_assert(1 == k);

    }
END_TEST

START_TEST (test_enter3)
    {
        const char input[] =  "i\n";
        const char output[] = "i\n";
        int n = 1;
        int k = 1;
        COMPARATOR(k, enter(n, input), output);
        ck_assert(1 == k);

    }
END_TEST

START_TEST (test_flush)
    {

    }
END_TEST

START_TEST (test_htoi1)
    {
        const char input[] = "0xA510";
        int output = 42256;
        ck_assert(htoi(input) == output);
    }
END_TEST

START_TEST (test_htoi2)
    {
        const char input[] = "FF";
        int output = 255;
        ck_assert(htoi(input) == output);
    }
END_TEST


START_TEST (test_htoi3)
    {
        const char input[] = "0xabcdef1";
        int output = 180150001;
        ck_assert(htoi(input) == output);
    }
END_TEST


START_TEST (test_htoi4)
    {
        const char input[] = "aDc3Ac3";
        int output = 182205123;
        ck_assert(htoi(input) == output);
    }
END_TEST

START_TEST (test_squeeze)
    {

    }
END_TEST

START_TEST (test_any1)
    {
        const char first_string[] = "Hello World";
        const char second_string[] = "abc";
        ck_assert(any(first_string, second_string) == -1);
    }
END_TEST


START_TEST (test_any2)
    {
        const char first_string[] = "Hello World!";
        const char second_string[] = "abc ";
        ck_assert(any(first_string, second_string) == 5);
   }
END_TEST


START_TEST (test_any3)
    {
        const char first_string[] = "This is my family if you wanna see dis look at me!";
        const char second_string[] = "wxyz";
        ck_assert(any(first_string, second_string) == 9);
    }
END_TEST

START_TEST (test_setbits)
    {

    }
END_TEST

START_TEST (test_binsearch)
    {

    }
END_TEST

START_TEST (test_escape)
    {

    }
END_TEST

START_TEST (test_expand)
    {

    }
END_TEST

START_TEST (test_itoa)
    {

    }
END_TEST

START_TEST (test_itob)
    {

    }
END_TEST

START_TEST (test_strrindex)
    {

    }
END_TEST

START_TEST (test_atofe)
    {

    }
END_TEST


Suite *str_suite(void) {
    Suite *suite = suite_create("Home assignment 1");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_stub);
    tcase_add_test(tcase, test_array_changer);

    tcase_add_test(tcase, test_detab);
    tcase_add_test(tcase, test_entab);
    tcase_add_test(tcase, test_enter1);
    tcase_add_test(tcase, test_enter2);
    tcase_add_test(tcase, test_flush);
    tcase_add_test(tcase, test_htoi1);
    tcase_add_test(tcase, test_htoi2);
    tcase_add_test(tcase, test_htoi3);
    tcase_add_test(tcase, test_htoi4);
    tcase_add_test(tcase, test_squeeze);
    tcase_add_test(tcase, test_any1);
    tcase_add_test(tcase, test_any2);
    tcase_add_test(tcase, test_any3);
    tcase_add_test(tcase, test_setbits);
    tcase_add_test(tcase, test_binsearch);
    tcase_add_test(tcase, test_escape);
    tcase_add_test(tcase, test_expand);
    tcase_add_test(tcase, test_itoa);
    tcase_add_test(tcase, test_itob);
    tcase_add_test(tcase, test_strrindex);
    tcase_add_test(tcase, test_atofe);
    /** YOUT TEST CASES HERE */

    suite_add_tcase(suite, tcase);
    return suite;
}

int main(int argc, char *argv[]) {

    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;
}