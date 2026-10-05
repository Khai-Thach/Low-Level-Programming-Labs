#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int diff (char *s1, char *s2) {
    int i = 0;
    int j = 0;
    int changes = 0;
        
    while (s1[i] != '\0' && s2[j] != '\0') {
        if (s1[i] != s2[j]) {
            changes++;  
        }
        i++;
        j++;
    }
    
    while (s1[i] != '\0') {
        changes++;  
        i++;
    }
    
    while (s2[j] != '\0') {
        changes++;  
        j++;
    }
    return changes;
}


