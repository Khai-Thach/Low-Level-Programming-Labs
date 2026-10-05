#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void capitalize(char *s) {
    int in_word = 0;  

    while (*s != '\0') {
        
        if (isspace(*s)) {
            in_word = 0;

        } else {
            
            if (!in_word) {
                
                *s = toupper(*s);  
                
                in_word = 1;
            
            } else {
                *s = tolower(*s);  
            }
        }
        s++;  
    }
}

