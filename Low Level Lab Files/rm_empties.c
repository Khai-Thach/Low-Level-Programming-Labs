#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void rm_empties(char **words) {
    if (words == NULL) {
        return;
    }
    int i = 0;
    int j = 0;

    while (words[i] != NULL) {
        int is_empty = 1;
        for (int k = 0; words[i][k] != '\0'; k++) {
            if (!isspace((unsigned char)words[i][k])) {
                is_empty = 0;  
                break;
            }
        }
        if (!is_empty) {
            words[j] = words[i];
            j++;
        }
        i++;
    }
    words[j] = NULL;  
}

