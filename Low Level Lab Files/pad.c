#include "string.h"
#include <stdio.h>
#include <stdlib.h>


char *pad(char *s, int d) {
    if (s == NULL) {
        return NULL; 
    }

    int len = 0;

    while (s[len] != '\0') {
        len++;
    }

    if (len % d == 0) {
 
        char *result = (char*) malloc(len + 1);
       
        if (result == NULL) {
            return NULL;  
        }

        for (int i = 0; i <= len; i++) {
            result[i] = s[i];
        }
        return result;
    }

    int padding = d - (len % d);

    char *result = (char*) malloc(len + padding + 1);
    
    if (result == NULL) {
        return NULL;  
    }

    for (int i = 0; i < len; i++) {
        result[i] = s[i];
    }

    for (int i = len; i < len + padding; i++) {
        result[i] = ' ';
    }
    result[len + padding] = '\0';
    return result;
}

