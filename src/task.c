//
// Created by cubazis on 25.05.18.
//

#include "task.h"
#include <math.h>

/** The stub function
 *  just to demonstrate how to work with ck_assert
 *  please look for test case for stub function in test_task.c
 */

int stub(void) {
    return 42;
}

/** The array_changer function
 *  just to demonstrate how to work with returning of array from function
 *
 *  1) C language doesn't have strings
 *  2) array in a C language is just a segment of memory
 *  3) C lang doesn't have ability to pass array as parameter in a function
 *  4) we suppose that you don't know about memory allocation through pointers
 *
 *  so, we provide you simple demo function which change 'c' char in input array
 *  	input parameter: constant array of chars
 *  	output: pointer to memory segment in which resulting array starts
 *
 *  	extra stuff: we provide you three define macros in task.h.
 *  		you can use them in your solutions
 *  		if you don't want to use them please, don't delete them - somebody may use it
 *
 *  please look for test case for array_changer function in test_task.c
 */

char *array_changer(const char c[]) {
    char i = 0, j = 0;
    STRING_LEN(i, c);
    char *b = ALLOCATE(i);

    for (; j < i;) {
        if (b[j] == 'c')
            b[j] = 'b';
        else
            b[j] = c[j];
        j++;
    }
    return b;
}

/** YOUR SOLUTIONS */

char *detab(const char input[]) {
    int size = 0;
    int i = 0;
    //1)Найти конечную длину строки
    STRING_LEN(i, input);
    for (int j = 0; j < i; j++) {
        if (input[j] != '\t') {
            size++;
        } else {
            size += 4;
        }
    }
    char *res = ALLOCATE(size);
    int ind = 0;
    //2)Заполнить строку
    for (int j = 0; j < i; j++) {

        if (input[j] != '\t') {
            res[ind] = input[j];
            ind++;
        } else {
            for (int l = ind; l <= ind + 3; l++) {
                res[l] = ' ';
            }
            ind += 4;
        }
    }
    return res;
}

char* enter(int n, const char input[]) {
    int i = 0, size = 0, counter = 0;

    STRING_LEN(i, input);

    for (int j = 0; j < i; j++) {
        if (counter > n) {
            size++;
            counter = 0;
        } else if (input[j] == '\n') {
            counter = 0;
        } else {
            counter++;
        }
        size++;
    }

    char *res = ALLOCATE(size);
    counter = 0;
    int arr_pointer = 0;
    for (int j = 0; j < i; j++) {
        if (counter > n) {
            res[arr_pointer] = '\n';
            arr_pointer++;
            res[arr_pointer] = input[j];
            counter = 0;
        } else if (input[j] == '\n'){
            res[arr_pointer] = '\n';
            counter = 0;
        } else {
            res[arr_pointer] = input[i];
        }
        arr_pointer++;
    }

    return res;
}


int htoi(const char s[]) {
    int j = 0, i = 0;
    STRING_LEN(i, s);

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        j = 2;
    }

    int res = 0, power = 0;
    for (i--; i >= j; i--) {
        int temp;
        if (s[i] - '0' >= 0 && s[i] - '9' <= 0)
            temp = s[i] - '0';
        else if (s[i] - 'a' >= 0 && s[i] - 'z' <= 0)
            temp = s[i] - 'a' + 10;
        else
            temp = s[i] - 'A' + 10;

        res += pow(16, power) * temp;
        power++;
    }
    return res;
}
/** GET FROM task.h */