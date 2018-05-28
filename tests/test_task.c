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
        const char input[] = "\tfff\t\t";
        const char pattern[] = "    fff        ";
        char *output = detab(input);
        int k = 1;
        COMPARATOR(k, output, pattern);
        ck_assert(1 == k);
        free(output);

    }
END_TEST

START_TEST (test_entab)
    {
        const char input[] = "        f";
        const char pattern[] = "\t\tf";
        char *output = entab(input);
        int k = 1;
        COMPARATOR(k, output, pattern);
        ck_assert(k == 1);
        free(output);
    }
END_TEST

START_TEST (test_enter1)
    {
        const char input[] = "hellomydearfriend";
        const char output[] = "hello\nmydea\nrfrie\nnd";
        int n = 5;
        int k = 1;
        COMPARATOR(k, enter(n, input), output);
        ck_assert(1 == k);

    }
END_TEST

START_TEST (test_enter2)
    {
        const char input[] = "";
        const char output[] = "";
        int n = 1;
        int k = 1;
        COMPARATOR(k, enter(n, input), output);
        ck_assert(1 == k);

    }
END_TEST

START_TEST (test_enter3)
    {
        const char input[] = "i\n";
        const char output[] = "i\n";
        int n = 1;
        int k = 01;
        COMPARATOR(k, enter(n, input), output);
        ck_assert(1 == k);

    }
END_TEST

START_TEST (test_flush)
    {
        const char input1[] = "#include <stdio.h>\n"
                              "main()\n"
                              "{\n"
                              "\t\tint x,y,m;\t\t\t\t/* 定义整型变量x，y，m */\n"
                              "\t\tprintf(\"Please input x and y\\n\");\t/* 输出提示信息 */\n"
                              "\t\tscanf(\"%d%d\",&x,&y);\t\t\t/* 读入两个乘数，赋给x，y变量 */\n"
                              "\t\tm=x*y;\t\t\t\t\t/* 计算两个乘数的积，赋给变量m */\n"
                              "\t\tprintf(\"%d * %d = %d\\n\",x,y,m);\t\t/* 输出结果 */\n"
                              "}";
        const char output1[] = "#include <stdio.h>\n"
                               "main()\n"
                               "{\n"
                               "\t\tint x,y,m;\t\t\t\t\n"
                               "\t\tprintf(\"Please input x and y\\n\");\t\n"
                               "\t\tscanf(\"%d%d\",&x,&y);\t\t\t\n"
                               "\t\tm=x*y;\t\t\t\t\t\n"
                               "\t\tprintf(\"%d * %d = %d\\n\",x,y,m);\t\t\n"
                               "}";
        int k = 1;
        char *out1 = flush(input1);
        COMPARATOR(k, out1, output1);
        ck_assert(1 == k);

        const char input2[] = "#include <stdio.h>\n"
                              "#define MAX 50\n"
                              "/*\n"
                              " * 函数rep实现对s中出现的s1中的字符替换为s2中相应的字符\n"
                              " * */\n"
                              "rep(char *s,char *s1,char *s2)\n"
                              "{\n"
                              "    char *p;\n"
                              "\n"
                              "    for(;*s;s++)\n"
                              "    //顺序访问字符串s中的每个字符\n"
                              "    {\n"
                              "        for(p=s1;*p&&*p!=*s;p++);\n"
                              "        /*\n"
                              "         * 检查当前字符是否在字符串s1中出现\n"
                              "         * */\n"
                              "            if(*p)*s=*(p-s1+s2);/*当前字符在字符串s1中出现，用字符串s2中的对应字符代替s中的字符*/\n"
                              "        }\n"
                              "}";
        const char output2[] = "#include <stdio.h>\n"
                               "#define MAX 50\n"
                               "\n"
                               "rep(char *s,char *s1,char *s2)\n"
                               "{\n"
                               "    char *p;\n"
                               "\n"
                               "    for(;*s;s++)\n"
                               "        {\n"
                               "        for(p=s1;*p&&*p!=*s;p++);\n"
                               "        \n"
                               "            if(*p)*s=*(p-s1+s2);\n"
                               "        }\n"
                               "}";

        char *out2 = flush(input2);
        COMPARATOR(k, out2, output2);
        ck_assert(1 == k);
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
        char s1[] = "abcddddlkm";
        char s2[] = "dhll";
        char *res = squeeze(s1, s2);
        const char pattern[] = "abckm";
        int k = 1;
        COMPARATOR(k, res, pattern);
        ck_assert(k == 1);
        free(res);

        char s1_2[] = "a";
        char s2_2[] = "a";
        char *res_2 = squeeze(s1_2, s2_2);
        const char pattern_2[] = "";
        int k2 = 1;
        COMPARATOR(k2, res_2, pattern_2);
        ck_assert(k2 == 1);
        free(res_2);
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
        int x = 50, p = 3, y = 500, n = 3;
        ck_assert(setbits(x, p, n, y) == 52);
    }
END_TEST



START_TEST (test_binsearch)
    {
        int in1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        ck_assert(binsearch(2, in1, 9) == 1);
        ck_assert(binsearch(5, in1, 9) == 4);
        ck_assert(binsearch(8, in1, 9) == 7);
        ck_assert(binsearch(10, in1, 9) == -1);

        int in2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        ck_assert(binsearch(2, in2, 10) == 2);
        ck_assert(binsearch(5, in2, 10) == 5);
        ck_assert(binsearch(8, in2, 10) == 8);
        ck_assert(binsearch(13, in2, 10) == -1);
    }
END_TEST

START_TEST (test_escape)
    {
        const char input1[] = "#include <stdio.h>\n";
        const char output1[] = "#include <stdio.h>\\n";
        int k = 1;

        char *out1 = escape(input1);
        COMPARATOR(k, out1, output1);
        ck_assert(1 == k);
        free(out1);


        const char input2[] = "#include \t<stdio.h>\n";
        const char output2[] = "#include \\t<stdio.h>\\n";
        char *out2 = escape(input2);
        COMPARATOR(k, out2, output2);
        ck_assert(1 == k);
        free(out2);

        const char input3[] = "#include \t<stdio.h>\t\n";
        const char output3[] = "#include \\t<stdio.h>\\t\\n";
        char *out3 = escape(input3);
        COMPARATOR(k, out3, output3);
        ck_assert(1 == k);
        free(out3);
    }
END_TEST

START_TEST (test_expand)
    {
        const char in[] = "a-z";
        const char pattern[] = "abcdefghijklmnopqrstuvwxyz";
        char *res = expand(in);
        int k = 1;
        COMPARATOR(k, res, pattern);
        ck_assert(k == 1);
        free(res);


        const char in2[] = "-a-z0-5";
        const char pattern2[] = "-abcdefghijklmnopqrstuvwxyz012345";
        char *res2 = expand(in2);
        int k2 = 1;
        COMPARATOR(k2, res2, pattern2);
        ck_assert(k2 == 1);
        free(res2);

        const char in3[] = "-a-d-u5-9";
        const char pattern3[] = "-abcdefghijklmnopqrstu56789";

        char *res3 = expand(in3);
        int k3 = 1;
        COMPARATOR(k3, res3, pattern3);
        ck_assert(k3 == 1);
        free(res3);
    }
END_TEST

START_TEST (test_itoa)
    {
        int k = 1;
        char *out1 = itoa(-128);
        COMPARATOR(k, out1, "-128");
        ck_assert(k == 1);
        free(out1);

        char *out2 = itoa(128);
        COMPARATOR(k, out2, "128");
        ck_assert(k == 1);
        free(out2);

        char *out3 = itoa(-73);
        COMPARATOR(k, out3, "-73");
        ck_assert(k == 1);
        free(out3);

        char *out4 = itoa(73);
        COMPARATOR(k, out4, "73");
        ck_assert(k == 1);
        free(out4);

        char *out5 = itoa(0);
        COMPARATOR(k, out5, "0");
        ck_assert(k == 1);
        free(out5);
    }
END_TEST

START_TEST (test_itob1)
    {
        int n = 10, b = 2;
        char res[] = "1010";

        int k = 1;
        COMPARATOR(k, itob(n, b), res);
        ck_assert(k == 1);
    }
END_TEST

START_TEST (test_itob2)
    {
        int n = 75, b = 16;
        char res1[] = "4B";
        char res2[] = "4b";

        int k = 1;
        COMPARATOR(k, itob(n, b), res1);
        int temp = k;

        k = 1;
        COMPARATOR(k, itob(n, b), res1);

        ck_assert(k || temp == 1);
    }
END_TEST


START_TEST (test_strrindex1)
    {
        char s[] = "Hello my dear friend";
        char t[] = "dear";
        int output = 9;

        ck_assert(output == strrindex(s, t));
    }
END_TEST


START_TEST (test_strrindex2)
    {
        char s[] = "Hello my dear friend";
        char t[] = "Love";
        int output = -1;

        ck_assert(output == strrindex(s, t));
    }
END_TEST

START_TEST (test_strrindex3)
    {
        char s[] = "Hello my dear my dear, my dear friend";
        char t[] = "my dear";
        int output = 23;

        ck_assert(output == strrindex(s, t));
    }
END_TEST

START_TEST (test_atofe)
    {
        const char s[] = "123.45e-6";
        double res = 123.45 * 0.000001;
        double output = atofe(s);

        ck_assert(abs(res - output) < 1e-9);
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
    tcase_add_test(tcase, test_itob1);
    tcase_add_test(tcase, test_itob2);
    tcase_add_test(tcase, test_strrindex1);
    tcase_add_test(tcase, test_strrindex2);
    tcase_add_test(tcase, test_strrindex3);
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