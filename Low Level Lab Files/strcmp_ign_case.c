#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int strcmp_ign_case(char *s1, char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        char c1 = tolower(*s1); 
        char c2 = tolower(*s2);  

        if (c1 < c2) {  
            return -1;   
            
        } else if (c1 > c2) {  
            return 1;    
        }
        s1++;
        s2++;
    }

    if (*s1 == '\0' && *s2 == '\0') {
        return 0;  
    }

    if (*s1 == '\0') {
        return -1;  
        
    } else {
        return 1;   
    }
}