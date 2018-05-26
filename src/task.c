//
// Created by cubazis on 25.05.18.
//

#include "task.h"

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
char *entab(const char input[]) {
    int i = 0;
    int size=0;
    STRING_LEN(size, input);
    STRING_LEN(i, input);
    int *buf = ALLOCATE_INT(i);
    buf[0] = input[0] == ' ' ? 1 : 0;
    for (int j = 1; j < i; j++) {
        if (input[j] == ' ') {
            buf[j] = buf[j - 1] + 1;
            if (buf[j] == 4 && j >= 3) {
                buf[j] = 0;
                buf[j - 3] = -1;
                size -= 3;
            }
        }
    }
    char *res = ALLOCATE(size);
    int ind = -1;
    for (int j = 0; j < i;) {
        ind++;
        if (buf[j] == -1) {
            res[ind] = '\t';
            j += 4;
        } else {
            res[ind] = input[j];
            j++;
        }
    }
    return res;

}

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

char *enter(int n, const char input[]) {
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
        } else if (input[j] == '\n') {
            res[arr_pointer] = '\n';
            counter = 0;
        } else {
            res[arr_pointer] = input[i];
        }
        arr_pointer++;
    }

    return res;
}

char *squeeze(const char s1[], const char s2[]) {
    int *s2_ = ALLOCATE_INT(256);
    int i = 0;
    STRING_LEN(i, s2);
    for (int j = 0; j < i; j++) {
        s2_[s2[j]] = 1;
    }
    //int i3=0;
    //STRING_LEN(i3,"kekpek");
    int i1 = 0;
    STRING_LEN(i1, s1);
    int size = i1;
    for (int j = 0; j < i1; j++) {
        if (s2_[s1[j]] == 1) {
            size -= 1;
            if (size < 0) {
                size = 0;
            }
        }
    }
    char *res = ALLOCATE(size);
    int ind = 0;
    for (int j = 0; j < i1; j++) {
        if (s2_[s1[j]] != 1) {
            res[ind] = s1[j];
            ind++;
        }

    }
    return res;

}
/** GET FROM task.h */