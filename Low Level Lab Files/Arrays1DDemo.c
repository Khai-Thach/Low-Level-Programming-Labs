#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Khai Thach
9/20/2024
CIS2107
Lab 4 1D Arrays

Problem: Creating and manipulating 1D Arrays

*/

#define RAND_MIN 0
#define RAND_MAX 100
#define SIZE 40

int main(int argc, const char * argv[]) {
    puts("");
    puts("\tWelcome to 1D Arrays! This is an array with random integers");
    puts("");
    int array[SIZE];

    unsigned int tom;
    unsigned int jerry;

    // making a random array
    fillArray(array, SIZE);

    // looking for the biggest integer in the array between index 10 and 19
    puts("\t\tFrom the array, this is the biggest integer");
    findWithRange(array, 10, 19);

    // flips the array into its opposite
    puts("");
    puts("\t\tI will now reverse the array");
    reverseArray(array, SIZE);
    puts("");

    // flips a selected portion of the array into its opposite
    puts("\tI am now reversing the array from index 15 to 24");
    reverseSelectedRangeWithinArray(array, SIZE, 15, 24);

    // testing findSequence Function
    puts("\tWe're going to play a little game of \"Tome & Jerry\"");
    printf("Enter two numbers: ");
    scanf("%d %d", &tom, &jerry);

    int found = findSequence(array, SIZE, tom, jerry);

    if (found != -1) {
        printf("Sequence found at index %d\n", found);
    } else {
        puts("Sequence not found\n");
    }
    
    exit(0);



}

// creates a random array of 40 integers
void fillArray(int array[],int size) {
    
    srand((unsigned) time(NULL));

    // makes sure the array is different every time
    for ( size_t i = 0; i < SIZE; ++i) {
        array[i] = rand() % (RAND_MAX + 1) + RAND_MIN;
    }   

    // prints out the array
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d ", array[i]);

        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    puts("\n");
}

// outputs the biggest integer within the array, given a certain range
void findWithRange(int array[], int low, int high) {
    int biggest = 0;

    // looks through the array and the biggest integer is stored in "biggest"
    for (size_t i = low; i < high; ++i) {
        if (array[i] > biggest) {
            biggest = array[i];
        }
    }
    printf("Max = %d", biggest);
    puts("\n");
}

// reverses the order of the whole array
void reverseArray(int array[], int size) {

    // prints out the original array 
    puts("Original:");

    fillArray(array,SIZE);
    
    // reverses the array
    for (int i = 0; i < size / 2; ++i) {
        
        // puts the array's values into "temp"
        int temp = array[i];

        // changes the original value in the array with it's opposite index
        array[i] = array[size - i - 1];

        // puts the value stored in "temp" and enters it into the array's specific index
        array[size - i - 1] = temp;
    }
    
    // prints out the reversed array
    puts("Reversed:\n");
    for (int i = 0; i < size ; ++i) {
        printf("%4d ", array[i]);

        if ((i + 1) % 10 == 0) {
            puts("\n");
        }
    }
}
// reverses a certain part of the array 
void reverseSelectedRangeWithinArray(int array[], int size, int startRange, int endRange) {
    
    puts("Here is a demo:\n");

    fillArray(array, SIZE);
    
    printf("reversing between %d and %d\n\n", startRange, endRange);

    for (size_t i = startRange; i < (startRange + endRange) / 2; ++i) {
         // puts the array's values into "temp"
        int temp = array[i];
        
        // changes the original value in the array with it's opposite index
        array[i] = array[endRange - (i - startRange) ];
        
        // puts the value stored in "temp" and enters it into the array's specific index
        array[endRange - (i - startRange)] = temp;
    }

    // prints out the partially reversed array
    for (int i = 0; i < size; ++i) {
        printf("%4d ", array[i]);

        if ((i + 1) % 10 == 0) {
            puts("\n");
        }
    }
}
// looks for the index of a given integer, depending on which is first
int findSequence(int array[], int size, int tom, int jerry) {
    
    for (int i = 0; i < size - 1; ++i) {
        // finds the index of the first index after iterating through the array
        if (array[i] == tom) {
            
            return i;
        // finds the index of the second integer after iterating through the array
        } else if (array[i] == jerry) {
            
            return i;
        }
        
    }
    // if neither integers are found, return -1
    return -1;
}




