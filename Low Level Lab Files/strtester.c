#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main(void) {

    puts("Test for all_letters");
    char *s = "Hello World"; 
    char *s1 = "He11o World"; 
    int all_letters_ = all_letters(s);  
    int not_all_letters = all_letters(s1);
    printf("String: %s\n", s);
    printf("Returns: %d\n", all_letters_);    
    printf("String: %s\n", s1);
    printf("Returns: %d\n\n", not_all_letters);

    puts("Test for num_in_range");
    char *for_range = "yellow";
    int num_in_range_ = num_in_range(for_range, 'f', 'm');
    printf("The String: %s\n", for_range);
    printf("The range %c-%c: ", 'f', 'm');
    printf("%s %d %s\n\n", "There are", num_in_range_, "letters in the range");

    puts("Test for diff");
    char *book = "Book";
    char *back = "Back";
    int diff_ = diff(book, back);
    printf("The Strings: %s, %s\n", book, back);
    printf("%s %d %s\n\n", "The strings differ in", diff_, "ways");

    puts("Test for shorten");
    puts("Before (First Example):");
    char word1[] = "Hello World";
    printf("%s\n", word1);
    puts("After (First example):");
    shorten(word1, 5);
    printf("%s\n\n", word1);
    puts("Before (Second Example):");
    char word2[] = "Hello World";
    printf("%s\n", word2);
    puts("After (Second Example):");
    shorten(word2, 20);
    printf("%s\n\n", word2);

    puts("Test for len_diff");
    char *philly = "Philadelphia";
    char *hello = "Hello";
    int len_diff_ = len_diff(philly, hello);
    printf("The Strings: %s, %s\n", philly, hello);
    printf("%s %d\n\n", "The strings differ in length by", len_diff_);

    puts("Test for rm left space");
    char rm_left_space_[] = "  Hello";
    puts("Before:");
    printf("%s\n", rm_left_space_);
    rm_left_space(rm_left_space_);
    puts("After:");
    printf("%s\n\n", rm_left_space_);

    puts("Test for rm right space");
    char rm_right_space_[] = "Hello  ";
    puts("Before:");
    printf("%s\n", rm_right_space_);
    rm_right_space(rm_right_space_);
    puts("After:");
    printf("%s\n\n", rm_right_space_);

    puts("Test for rm space");
    char rm_space_[] = "  Hello  ";
    puts("Before:");
    printf("%s\n", rm_space_);
    rm_space(rm_space_);
    puts("After:");
    printf("%s\n\n", rm_space_);

    puts("Test for find");
    char *find1 = "Hello ";
    char *sub1 = "l";
    int result1 = find(find1, sub1);
    if (result1 != -1) {
        printf("First occurrence of '%s' in '%s' is at index %d\n", sub1, find1, result1);
    } else {
        printf("'%s' not found in '%s'\n", sub1, find1);
    }
    char *find2 = "Hello";
    char *sub2 = "q";
    int result2 = find(find2, sub2);
    if (result2 != -1) {
        printf("First occurrence of '%s' in '%s' is at index %d\n", sub2, find2, result2);
    } else {
        printf("'%s' not found in '%s', return %d\n\n", sub2, find2, result2);
    }

    puts("Test for *ptr_to");
    char *ptr_to_1 = "Hello ";
    char *ptr_to_sub_1 = "l";
    char *ptr_result_1 = ptr_to(ptr_to_1, ptr_to_sub_1);
    if (ptr_result_1 != NULL) {
        printf("First occurrence of '%s' in '%s' is at address: %p\n", ptr_to_sub_1, ptr_to_1, (void *)ptr_result_1);
    } else {
        printf("'%s' not found in '%s', return NULL\n\n", ptr_to_sub_1, ptr_to_1);
    }
    char *ptr_to_2 = "Hello";
    char *ptr_to_sub_2 = "q";
    char *ptr_result_2 = ptr_to(ptr_to_2, ptr_to_sub_2);
    if (ptr_result_2 != NULL) {
        printf("First occurrence of '%s' in '%s' is at address: %p\n", ptr_to_sub_2, ptr_to_2, (void *)ptr_result_2);
    } else {
        printf("'%s' not found in '%s', return NULL\n\n", ptr_to_sub_2, ptr_to_2);
    }

    puts("Test for is_empty");
    char *is_empty_1 = " ";
    puts("Testing: \" \"");
    int empty_test_1 = is_empty(is_empty_1);
    printf("Returns: %d\n", empty_test_1);
    char *is_empty_2 = "Hello";
    puts("Testing: Hello");
    int empty_test_2 = is_empty(is_empty_2);
    printf("Returns: %d\n\n", empty_test_2);

    puts("Test for str_zip");
    char *str_zip_1 = "Temple";
    char *str_zip_2 = "Hello";
    char *zipped = str_zip(str_zip_1, str_zip_2);
    if (zipped) {
        printf("Result of str_zip(\"%s\", \"%s\"): %s\n\n", str_zip_1, str_zip_2, zipped);
        free(zipped);  
    } else {
        printf("failed to complete task\n\n");
    }

    puts("Test for capitalize");
    char capitalizing[] = "hello world";
    printf("String to capitalize: %s\n", capitalizing);
    capitalize(capitalizing);
    printf("Capitalized string: %s\n\n", capitalizing);
    
    puts("Test for strcmp_ign_case");
    char cmp_ign_case_1[] = "hello";
    char cmp_ign_case_2[] = "goodbye";
    int ign_case_comparison = strcmp_ign_case(cmp_ign_case_1, cmp_ign_case_2);
    printf("Test 1: Result comparing %s and %s: %d\n", cmp_ign_case_1, cmp_ign_case_2, ign_case_comparison); 
    char cmp_ign_case_3[] = "Hello";
    char cmp_ign_case_4[] = "hello";
    int ign_case_comparison_2 = strcmp_ign_case(cmp_ign_case_3, cmp_ign_case_4);
    printf("Test 2: Result comparing %s and %s: %d\n\n", cmp_ign_case_3, cmp_ign_case_4, ign_case_comparison_2); 


    puts("Test for take_last");
    char take_last_1[] = "hello";
    printf("Before: %s\n", take_last_1);
    take_last(take_last_1, 3);
    printf("After: %s\n", take_last_1); 
    char take_last_2[] = "hello";
    printf("Before: %s\n", take_last_2);
    take_last(take_last_2, 6);
    printf("After: %s\n\n", take_last_2); 

    puts("Test for dedup");
    char duplicates[] = "hello";
    char *removed_duplicates = dedup(duplicates);
    if (removed_duplicates != NULL) {
        printf("Original string: %s\n", duplicates);   
        printf("String after deduplication: %s\n\n", removed_duplicates);  
        free(removed_duplicates);
    } else {
        printf("Memory allocation failed.\n\n");
    }

    puts("Test for pad");
    char* to_pad_1 = "hello";
    int d1 = 6;
    char* padded_str_1 = pad(to_pad_1, d1);
    if (padded_str_1 != NULL) {
        printf("Padded string (\"%s\", %d): \"%s\"\n", to_pad_1, d1, padded_str_1);
        free(padded_str_1);
    }
    char* to_pad_2 = "hello";
    int d2 = 5;
    char* padded_str_2 = pad(to_pad_2, d2);
    if (padded_str_2 != NULL) {
        printf("Padded string (\"%s\", %d): \"%s\"\n\n", to_pad_2, d2, padded_str_2);
        free(padded_str_2); 
    }

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

    puts("Test for repeat");
    char *repeating = "hello";
    int times = 3;
    char separator = '-';
    char *repeated = repeat(repeating, times, separator);
    if (repeated != NULL) {
        printf("Repeated string: \"%s\"\n\n", repeated);
        free(repeated);  
    } else {
        printf("Error in repeating the string.\n\n");
    }


    puts("Test for replace");
    char* replacing = "Steph is the X";
    char* pattern = "X";
    char* rep = "best";
    char* replaced = replace(replacing, pattern, rep);
    if (replaced != NULL) {
        printf("Modified string: \"%s\"\n\n", replaced);
        free(replaced);  
    } else {
        printf("Error in replacing the string.\n\n");
    }

    puts("Test for str_connect");
    char* connecting[] = {"Hello", "world", "Hello", "world"};
    int n = 4;
    char connect_separator = '-';
    char* connected = str_connect(connecting, n, connect_separator);
    if (connected != NULL) {
        printf("Resulting string: \"%s\"\n\n", connected);
        free(connected);  
    } else {
        printf("Error in string concatenation.\n\n");
    }

    puts("Test for rm_empties");
    char* empties[] = {"Hello", "World", " ", " ", "Steph", NULL};
    rm_empties(empties);
    printf("Modified array: ");
    for (int i = 0; empties[i] != NULL; i++) {
        printf("%s ", empties[i]);
    }
    printf("\n\n");

    puts("Test for str_chop_all");
    char *chopping = "Hello/world/hello/world";
    char chop = '/';
    char **chopped = str_chop_all(chopping, chop);
    if (chopped != NULL) {
      printf("Resulting tokens: ");
      int first = 1;
      for (int i = 0; chopped[i] != NULL; i++) {
         if(!first) {
            printf(", ");
         }
         first = 0;
         printf("%s", chopped[i]);
      }
      printf("\n");
      for (int i = 0; chopped[i] != NULL; i++) {
         free(chopped[i]);
      }
      free(chopped);
    } else {
        printf("Error in splitting the string.\n");
    }
    
    return 0;
}