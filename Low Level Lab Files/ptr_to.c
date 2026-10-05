#include "string.h"
#include <stdio.h>
#include <stdlib.h>

char *ptr_to(char *h, char *n) {
    int i = 0;
    int j = 0;

    while (h[i] != '\0') {
        j = 0;  
       
        while (h[i + j] != '\0' && n[j] != '\0' && h[i + j] == n[j]) {
            j++;
        }

        if (n[j] == '\0') {
            return &h[i];  
        }
        i++;
    }
    return NULL;  
}

