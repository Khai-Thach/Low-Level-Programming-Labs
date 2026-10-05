#include "string.h"
#include <stdio.h>
#include <stdlib.h>

 char **str_chop_all(char *s, char c) {
    if (s == NULL) {
        return NULL;  
    }

    int capacity = 10;  
    int count = 0;     
    char **tokens = (char **)malloc(capacity * sizeof(char *));  

    if (tokens == NULL) {
        return NULL; 
    }

    char *start = s;  

    while (*s != '\0') {
        if (*s == c) {
            
            if (s != start) {  
                int len = s - start;  
                tokens[count] = (char *)malloc((len + 1) * sizeof(char));  
             
                if (tokens[count] == NULL) {
                    
                    for (int i = 0; i < count; i++) {
                        free(tokens[i]);
                    }
                    free(tokens);
                    return NULL;  
                }
             
                for (int i = 0; i < len; i++) {
                    tokens[count][i] = start[i];  
                }
                tokens[count][len] = '\0';  
                count++;
            }
            start = s + 1; 
        }
        s++;
    }

   
    if (s != start) {
        int len = s - start;
        tokens[count] = (char *)malloc((len + 1) * sizeof(char));
        
        if (tokens[count] == NULL) {
           
            for (int i = 0; i < count; i++) {
                free(tokens[i]);
            }
            free(tokens);
            return NULL;
        }
       
        for (int i = 0; i < len; i++) {
            tokens[count][i] = start[i];
        }
        tokens[count][len] = '\0';
        count++;
    }
    tokens[count] = NULL; 
    return tokens;
 }


 