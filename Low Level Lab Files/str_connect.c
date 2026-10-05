#include "string.h"
#include <stdio.h>
#include <stdlib.h>

char *str_connect(char **strs, int n, char c) {
    if (strs == NULL || n <= 0) {
        return NULL;  
    }

    int total_len = 0;
     
    for (int i = 0; i < n; i++) {
        if (strs[i] == NULL) {
            return NULL;  
        }
        int len = 0;
        while (strs[i][len] != '\0') {
            len++;  
        }
        total_len += len;  
        if (i < n - 1) {
            total_len++;  
        }
    }
 
    char *result = (char *)malloc(total_len + 1);
    if (result == NULL) {
        return NULL;  
    }

    
    int idx = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (strs[i][j] != '\0') {
            result[idx++] = strs[i][j++];  
        }
        if (i < n - 1) {
            result[idx++] = c; 
        }
    }
    result[idx] = '\0';  
    return result;  
}

