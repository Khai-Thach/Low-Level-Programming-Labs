#include "string.h"
#include <stdio.h>
#include <stdlib.h>


void rm_space(char *s) {
    int i = 0;
    
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
        i++;
    }

    int j = 0;
    while (s[i] != '\0') {
        s[j] = s[i];
        i++;
        j++;
    }
    
    j--;  
    while (j >= 0 && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')) {
        j--;
    }

    s[j + 1] = '\0';
}