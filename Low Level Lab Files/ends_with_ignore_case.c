#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ends_with_ignore_case(char *s, char *suff) {
    if (s == NULL || suff == NULL) {
        return 0;  
    }

    int len_s = 0;
    while (s[len_s] != '\0') {
        len_s++;
    }

    int len_suff = 0;
    while (suff[len_suff] != '\0') {
        len_suff++;
    }

    if (len_suff > len_s) {
        return 0;
    }

    for (int i = 0; i < len_suff; i++) {
        if (tolower(s[len_s - len_suff + i]) != tolower(suff[i])) {
            return 0;  
        }
    }

    return 1;  
}

int main() {
    puts("Test for ends_with_ignore_case");
    char* coding_1 = "Coding";
    char* suffix_1 = "ing";
    printf("First example: \"%s\" \"%s\"\n", coding_1, suffix_1);
    int first_ends_with = ends_with_ignore_case(coding_1, suffix_1);
    printf("Returns: %d\n", first_ends_with);
    char* coding_2 = "Coding";
    char* suffix_2 = "ed";
    printf("Second example: \"%s\" \"%s\"\n", coding_2, suffix_2);
    ends_with_ignore_case(coding_2, suffix_2);
    int second_ends_with = second_ends_with = ends_with_ignore_case(coding_2, suffix_2);
    printf("Returns: %d\n\n", second_ends_with);
}
