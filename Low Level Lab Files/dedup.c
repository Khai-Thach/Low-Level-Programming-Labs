#include "string.h"
#include <stdio.h>
#include <stdlib.h>


char *dedup(char *s) {
    int len = 0;
    
    while (s[len] != '\0') {
        len++;
    }

    char *result = (char*) malloc(len + 1);
   
    if (result == NULL) {
        return NULL;  
    }

    int result_index = 0;  

    for (int i = 0; s[i] != '\0'; i++) {
        
        char current_char = s[i];
        
        int is_duplicate = 0;

        for (int j = 0; j < result_index; j++) {
            
            if (result[j] == current_char) {
                
                is_duplicate = 1;
                
                break;  
            }
        }

        if (!is_duplicate) {
            result[result_index++] = current_char;
        }
    }
    result[result_index] = '\0';
    return result;
}

