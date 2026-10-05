/*
* Name: Khai Thach
* Section: 3
* Lab: CIS2107_Lab08_Manual
* Goal: To design and implement functions taking pointers as arguments
to process characters and strings.
*/

#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char
*s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char
*s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);


int main() {
//random generator
srand(time(NULL));

//test for upperLower
const char test[] = "This iS A Test";

upperLower(test);

//test for convertStrtoInt
printf("\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

//test for convertStrtoFloat
printf("\n\nThe sum of 4 strings is: %.2f\n\n", convertStrtoFloat("3.5", "4.5",
"5.5", "6.5"));

//test for compareStr
compareStr("Test1", "Test2");

//test for comparePartialStr
comparePartialStr("Test1", "Test2", 4);

//test for randomize
randomize();

//test for tokenize number
char str[] = "(267) 436-6281";

tokenizeTelNum(str);

//test for reverse
char line[] = "Hello world";
reverse(line);

//test for countSubstr
char *line1 = "helloworldworld";
char *substring = "world";

printf("\nNumber of Substrings %s inside %s: %d\n", substring, line1,
countSubstr(line1, substring));

//test for countChar
char w = 'w';

printf("\nNumber of character %c inside %s: %d\n\n", w, line1, countChar(line1,
w));

//test for countAlpha
char str1[] = "Hello it's me.";

countAlpha(str1);

//test for countWords
char countstring[] = "hello world!";

printf("\n\nNumber of words in string is: %d\n\n", countWords(countstring));

//test for startsWithB
char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};

startsWithB(series);

//test for endsWithed
endsWithed(series);

}


// 1.(Displaying Strings in Uppercase and Lowercase)
void * upperLower (const char * s) {

    // Arrays to store a line of text 
    char lowerCase[100];
    char upperCase[100];

    // Loops through the string until it reaches the string terminator
    for (int i = 0; s[i] != '\0'; i++) {
        
        // Adds the indexed character into both arrays 
        lowerCase[i] = tolower(s[i]);
        upperCase[i] = toupper(s[i]);
    }

    // Adding the string terminator
    lowerCase[strlen(s)] = '\0';
    upperCase[strlen(s)] = '\0';

    // Prints the string in lowercase and uppercase
    printf("\"%s\" \"%s\"\n", upperCase, lowerCase);
    

}


// 2.(Converting Strings to Integers for Calculations)
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {

    // Turning strings into integers using ASCII to integer function within <stdlib.h>
    int num1 = atoi(s1);
    int num2 = atoi(s2);
    int num3 = atoi(s3);
    int num4 = atoi(s4);

    // Calculates the sum of the four values
    int sum = num1 + num2 + num3 + num4;

    // Return the sum as a float (note: using double for accuracy during calculation)
    return (int)sum;
    
}


//3.(Converting Strings to Floating Point for Calculations)
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char
*s4) {

    // Turning strings into floats using ASCII to float function within <stdlib.h>
    float num1 = atof(s1);
    float num2 = atof(s2);
    float num3 = atof(s3);
    float num4 = atof(s4);

    // Calculate the sum of the four values
    float sum = num1 + num2 + num3 + num4;

    // Return the sum as a float (note: using double for accuracy during calculation)
    return (float)sum;
    
}


//4.(Comparing Strings)
void compareStr(const char *s1, const char *s2) {

    // Use strcmp to compare the two strings
    int result = strcmp(s1, s2);
    
    // Output the comparison result based on strcmp return value
    if (result < 0) {

        
        printf("%s < %s\n", s1, s2);
    
    } else if (result > 0) {
    
        printf("%s > %s\n", s1, s2);
    
    } else {
    
        printf("%s = %s\n", s1, s2);
    
    }

    puts("");
}


//5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n) {

    // Use strncmp to compare the first n characters of the two strings
    int result = strncmp(s1, s2, n);
    
    // Output the comparison result based on strncmp return value
    printf("Comparison of first %d chars: ", n);
   
    if (result < 0) {
   
        printf("%s < %s\n", s1, s2);  // s1 is less than s2
   
    } else if (result > 0) {
   
        printf("%s > %s\n", s1, s2);  // s1 is greater than s2
   
    } else {
   
        printf("%s = %s\n", s1, s2);  // s1 is equal to s2
   
    }

    puts("");

}


//6.(Random Sentences)
void randomize(void) {
    
    // Seed the random number generator
    srand((unsigned)time(NULL));

    // Define the arrays for articles, nouns, verbs, and prepositions
    char *article[] = {"the", "a", "one", "some", "any"};
    char *noun[] = {"boy", "girl", "dog", "town", "car"};
    char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[] = {"to", "from", "over", "under", "on"};

    // Define the number of words in each array
    int numArticles = sizeof(article) / sizeof(article[0]);
    int numNouns = sizeof(noun) / sizeof(noun[0]);
    int numVerbs = sizeof(verb) / sizeof(verb[0]);
    int numPrepositions = sizeof(preposition) / sizeof(preposition[0]);

    // Buffer to store the sentence (make sure it's large enough)
    char sentence[200];

    // Generate 20 random sentences
    for (int i = 0; i < 20; i++) {
       
        // Randomly select words from each array
        int articleWord = rand() % numArticles;
        int nounWord = rand() % numNouns;
        int verbWord = rand() % numVerbs;
        int prepositionWord = rand() % numPrepositions;
        int article2Word = rand() % numArticles;
        int noun2Word = rand() % numNouns;

        // Construct the sentence by concatenating words, starting with an empty string
        sentence[0] = '\0';  

        // Concatenate the words to form the sentence
        strcat(sentence, article[articleWord]);
        strcat(sentence, " ");
        
        strcat(sentence, noun[nounWord]);
        strcat(sentence, " ");
        
        strcat(sentence, verb[verbWord]);
        strcat(sentence, " ");
        
        strcat(sentence, preposition[prepositionWord]);
        strcat(sentence, " ");
        
        strcat(sentence, article[article2Word]);
        strcat(sentence, " ");
        
        strcat(sentence, noun[noun2Word]);
        // Ends the final sentence with a period.
        strcat(sentence, ".");

        // Capitalize the first letter of the final sentence 
        sentence[0] = toupper(sentence[0]);

        // Print the sentence
        puts(sentence);
        
    }

    puts("");

}


//7.(Tokenizing Telephone Numbers)
int tokenizeTelNum(char *num) {
    
    // Tokenizing the input string using spaces and dashes as delimiters
    char *areaCodeToken = strtok(num, " ()");  
    char *firstThree = strtok(NULL, " -");      
    char *lastFour = strtok(NULL, " ");     

    // Converting area code to integer
    int areaCode = atoi(areaCodeToken);

    // Concatenating the rest of the number
    char combineNums[8];
    combineNums[0] = '\0';

    strcat(combineNums, firstThree);
    strcat(combineNums, lastFour);

    // Converting the rest of the number to long
    long lastDigits = atol(combineNums);

    

    // Prints the full number
    printf("%d %ld", areaCode, lastDigits);

    puts("\n");

}


//8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text) {

    // Array to store the tokens
    char *tokens[100];
    int numTokens = 0;

    // Tokenizing the string using space as the delimiter
    char *token = strtok(text, " ");
    
    // Storing tokens in the array
    while (token != NULL) {
       
        tokens[numTokens++] = token;
       
        token = strtok(NULL, " ");
    
    }

    // Prints the tokens in reverse order
    for (int i = numTokens - 1; i >= 0; i--) {
       
        if (i != numTokens - 1) {
       
            printf(" ");  
       
        }
       
        printf("%s", tokens[i]);
    
    }

    puts("");  
}


//9.(Counting the Occurrences of a Substring)
int countSubstr (char * line, char * sub) {

    int total = 0;
    int lineLength = strlen(line);
    int subLength = strlen(sub);

    for (int i = 0; i <= lineLength - subLength; i++) {

        int j = 0;

        while (j < subLength && line[i + j] == sub[j]) {
            
            j++;

        }

        if (j == subLength) {
            total++;
        }
    }

    return total;

}


//10.(Counting the Occurrences of a Character)
int countChar (char *line, char c) {
    // Counter
    int total = 0;

    //Runs until there are no more characters in the string
    while (*line) {

        // Checks for the target character
        if (*line == c) {

            // Increments the number of times the character was found
            total++;
        }
        
        // Go through the string a character at a time
        line++;
    }
    
    // Returns the number of times the character was found
    return total;
    
    puts("");

}


//11.(Counting the Letters of the Alphabet in a String)
void countAlpha(char *string) {

    // Array to store counts for each letter 
    int counts[26] = {0};

    // Loops through each character of the string
    for (int i = 0; string[i] != '\0'; i++) {
        
        // Convert each letter to lowercase for case insensitivity
        char letter = tolower(string[i]);

        // Check if the character is a letter between 'a' and 'z'
        if (letter >= 'a' && letter <= 'z') {
        
            // Increment the count for the corresponding letter
            counts[letter - 'a']++;
        }
    }

    // Print the results in a table format
    printf("Letter | Count\n");
    printf("----------------\n");

    // Loops through the alphabet and prints the counts
    for (char letter = 'a'; letter <= 'z'; letter++) {
        printf("  %c    |   %d\n", letter, counts[letter - 'a']);
    }
}


//12.(Counting the Number of Words in a String)
int countWords(char *string) {
   
   // Counter
    int total = 0;

    // Tokenize the string based on spaces and punctuation 
    char *token = strtok(string, " \t\n\r,;.!?"); 

    while (token != NULL) {
        
        // Counts the number of words that have been tokenized
        total++;  

        // Continue tokenizing the string
        token = strtok(NULL, " \t\n\r,;.!?"); 
   
    }

    // Returns the number of words in the string
    return total;
    puts("");

}


//13.(Strings Starting with "b")
void startsWithB(char *string[]) {

    // Get the number of elements in the array
    int size = strlen(string) - 1;

     // Loops through the array of strings using the provided size
    for (int i = 0; i < size; i++) {
        
        // Check if each word stats with B/b
        if (*string[i] == 'b' || *string[i] == 'B') {

            printf("%s ", string[i]);

        }

    }

    puts("\n");

}


//14.(Strings Ending with "ed")
void endsWithed(char *string[]) {

    int size = strlen(string) - 1;
    
    // Loops through the array of strings using the provided size
    for (int i = 0; i < size; i++) {
        
        // Get the length of each element
        int length = strlen(string[i]);
        
        // Check if the string ends with 'ed'
        if (string[i][length - 2] == 'e' && string[i][length - 1] == 'd') {
            
            printf("%s ", string[i]);

        }
    }

    puts("\n");
}