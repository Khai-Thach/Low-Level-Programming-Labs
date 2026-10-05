#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int len_diff(char *s1, char *s2) {
    int len1 = 0;

    while (s1[len1] != '\0') {
        len1++;
    }
    
    
    int len2 = 0;
    while (s2[len2] != '\0') {
        len2++;
    }
    
    
    return len1 - len2;
}

