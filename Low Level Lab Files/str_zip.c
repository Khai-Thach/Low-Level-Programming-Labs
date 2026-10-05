#include "string.h"
#include <stdio.h>
#include <stdlib.h>

char *str_zip(char *s1, char *s2) {
    int len1 = 0;
    int len2 = 0;

     while (s1[len1] != '\0') {
        len1++;
    }
    
    while (s2[len2] != '\0') {
        len2++;
    }

    int result_len = len1 + len2;
    char *result = (char*)malloc((result_len + 1) * sizeof(char));
    if (!result) {
        return NULL; 
    }

    int i = 0; 
    int j = 0;
    int k = 0;
    
    while (i < len1 || j < len2) {
        if (i < len1) {
            result[k++] = s1[i++];
        }
        
        if (j < len2) {
            result[k++] = s2[j++];
        }
    }
    result[k] = '\0';
    return result;
}

