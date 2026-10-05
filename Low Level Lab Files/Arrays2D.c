#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Khai Thach
9/28/2024
CIS 2107
Lab 5 2D Arrays

Problem: Creating and manipulating 2D Arrays

*/

int main(int argc, const char * argv[]) {

    unsigned int columns;
    unsigned int rows;

    puts("\nLet's create a 2Dim Array!\n");

    // Assigns number of rows
    printf("\tHow many rows? ");
    scanf("%u", &rows);

    puts("");

    // Assigns number of columns
    printf("\tHow many columns? ");
    scanf("%u", &columns);

    puts("");

    // Initiating a 2D array
    int array[rows][columns];
    
    // Assigning values to each cell of the array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            // Inputs values directly into each cell
            printf("\tEnter [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
    
    // Function call for the sum of each row
    puts("");
    rowSum(rows, columns, array);

    // Function call for the sum of each column
    puts("");
    columnSum(rows, columns, array);
    
    // Function call to check if the 2D array is square-shaped
    puts("");
    isSquare(rows, columns);

    // Prints out the 2D array
    puts("\nHere is a 2Dim array!");
    
    displayOutputs(rows,columns,array);

    // Function call to find the biggest number in the 2D array
    max(rows,columns,array);

    puts("\n\tThat's 2D arrays for you! Thanks for checking it out :)\n\n");
    exit(0);

}

int max(int rows, int cols, int array[rows][cols]) {
    // Placeholder to find the biggest number in the 2D array
    int biggest = array[0][0];

    // Iterates through each cell of the 2D array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // For each cell of the 2D array, check if it's bigger than the first element
            if (biggest < array[i][j]) {
                biggest = array[i][j]; // Assigns the bigger element as the new max
            }
        }
    }

    printf("\nThe max value in your array is: %d\n\n", biggest);

}

void rowSum(int rows, int cols, int array[rows][cols]) {
    

    for (int i = 0; i < cols; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            // Adds each element of the row
            sum += array[i][j];
        }

        printf("Sum of row %d = %d\n", i + 1, sum);
    }

}

void columnSum(int rows, int cols, int array[rows][cols]) {
    

    for (int j = 0; j < cols; ++j) {
        int sum = 0;
        for (int i = 0; i < rows; ++i) {
            // Adds each element of the column
            sum += array[i][j];
        }
        printf("Sum of column %d = %d\n", j + 1, sum);
    }

    

}

int isSquare(int rows, int cols) {
    // Checks to see if the rows and columns are the same, in order to be sure the array is a square
    if (rows == cols) {
        puts("This is a square array.\n");
    } else {
        puts("This is not a square array.\n");
    }

}

void displayOutputs(int rows, int cols, int array[rows][cols]) {

    for (int i = 0; i < rows; ++i) {
        printf("[");
        for (int j = 0; j <cols; ++j) {
            // Displays the specific index of each element in the 2D array
            printf("%d",array[i][j]);
            // Places commas after each element is printed and excludes leading comma
            if ( j < cols - 1) {
                printf(", ");
            }
        } 
        puts("]");
    }

}
