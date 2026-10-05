#include "string.h"
#include <stdio.h>
#include <stdlib.h>

char *replace(char *s, char *pat, char *rep) {
    if (s == NULL || pat == NULL || rep == NULL) {
        return NULL;  
    }

    int pat_len = 0;
    while (pat[pat_len] != '\0') {
        pat_len++;
    }

    int rep_len = 0;
    while (rep[rep_len] != '\0') {
        rep_len++;
    }

    int count = 0;
    char *tmp_s = s;
    while (*tmp_s != '\0') {
        int match = 1;
        for (int i = 0; i < pat_len; i++) {
            if (tmp_s[i] != pat[i]) {
                match = 0;
                break;
            }
        }

        if (match) {
            count++;
            tmp_s += pat_len; 
        } else {
            tmp_s++; 
        }
    }

    int total_len = (tmp_s - s) + (count * (rep_len - pat_len));
    char *result = (char *)malloc(total_len + 1);  

    if (result == NULL) {
        return NULL;  
    }

    tmp_s = s;
    char *res_ptr = result;

    while (*tmp_s != '\0') {
        int match = 1;
       
        for (int i = 0; i < pat_len; i++) {
            if (tmp_s[i] != pat[i]) {
                match = 0;
                break;
            }
        }

        if (match) {

            for (int i = 0; i < rep_len; i++) {
                *res_ptr++ = rep[i];
            }
            tmp_s += pat_len;  

        } else {
            *res_ptr++ = *tmp_s++;
        }
    }
    *res_ptr = '\0';  
    return result;
}
