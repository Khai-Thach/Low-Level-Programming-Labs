#include <stdio.h>
#include <stdlib.h>

int all_letters(char *s) {
    while (*s != '\0') {

        if ((*s < 'a' || *s > 'z') && (*s < 'A' || *s > 'Z')) {
            return 0;  
        }
        s++;
    }
    return 1;  
}

