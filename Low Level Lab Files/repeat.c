#include "string.h"
#include <stdio.h>
#include <stdlib.h>


int my_strlen(char *s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

void my_strcpy(char *dest, char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  
}

char *repeat(char *s, int times, char sep) {
    if (s == NULL || times <= 0) {
        return NULL;  
    }

    int len = my_strlen(s);  
    int total_len = len * times + (times - 1); 

    char *result = (char *)malloc(total_len + 1);  
    if (result == NULL) {
        return NULL;  
    }

    char *res_ptr = result;  

    for (int i = 0; i < times; i++) {
        my_strcpy(res_ptr, s); 
        res_ptr += len;        

        if (i < times - 1) {
            *res_ptr = sep;  
            res_ptr++;       
        }
    }
    *res_ptr = '\0';  
    return result;
}

