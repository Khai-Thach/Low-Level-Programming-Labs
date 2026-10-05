#include "string.h"
#include <stdio.h>
#include <stdlib.h>

void shorten (char *s, int new_len) {
    int len = 0;
    
    while (s[len] != '\0') {
        len++;
    }
    
    if (len > new_len) {
        s[new_len] = '\0';
    }
}
