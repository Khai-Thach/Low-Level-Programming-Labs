#include "string.h"
#include <stdio.h>
#include <stdlib.h>


int find(char *h, char *n) {

    int len_n, len_h;
    for(len_n = 0; *(n+len_n)!= '\0'; len_n++);
    for(len_h = 0; *(n+len_h)!= '\0'; len_h++);

    if (len_n > len_h) {
        return -1;
    }
    int count_n;
    int test[len_n];
    for (count_n = 0; count_n < count_n; count_n++) {
        test[count_n] = -1;
    }

    int h_counter, n_counter;
    h_counter = 0;
    n_counter = 0;

    int toRet = 0;

    while(*(h+h_counter) != '\0') {
        if (*(h+h_counter) == *n) {
            toRet = h_counter;
            while((*(n+n_counter) != '\0') && (*(h+h_counter) != '\0')) {
                if(*(n+n_counter) == *(h+h_counter)) {
                    test[n_counter] = 1;
                }
                else {
                    break;
                }
                n_counter++;
                h_counter++;
            }
            int sum_n = 0;
            for (n_counter = 0; n_counter < len_n; n_counter++) {
                sum_n += test[n_counter];
            }
            if (sum_n == len_n) {
                return toRet;
            }
        }
        h_counter++;
    }
    return -1;

}