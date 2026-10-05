#include "string.h"
#include <stdio.h>
#include <stdlib.h>

void rm_right_space(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    
    i--;  
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')) {
        i--;
    }

    
    s[i + 1] = '\0';
}