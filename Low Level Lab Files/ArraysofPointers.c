#include <stdio.h>
#include <stdlib.h>


/*
Khai Thach
9/28/2024
CIS 2107
Lab 5 2D Arrays of Pointers to Functions

Problem: To design and implement array of function pointer
*/

// Function prototypes
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);


int main() {
    // User input dependent variables
    unsigned int students = 0;
    unsigned int exams = 0;
    
    // Array menu selection variables
    unsigned int user_choice_value = 5;
    unsigned int *user_choice = &user_choice_value;
    const int print_grades = 0;
    const int min_grade = 1;
    const int max_grade = 2;
    const int avg_per_student = 3;
    const int end = 4;
    
    puts("\tWelcome to TU Grading Array System!\n");
    // Gets user's input and assigns their values into the variables students and exams
    printf("Enter number of students: ");
    scanf("%d", &students);
    printf("Enter number of exams: ");
    scanf("%d", &exams);

    // Input grades
    int grades[students][exams];
    
    // Gets the user's grade inputs and put it into each cell of the array 
    puts("Enter the grades for each student:\n");
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < exams; j++) {
            printf("Grade for student %d Exam %d: ", i + 1, j + 1);
            scanf("%d", &grades[i][j]);
        }
    }
    
    puts("");

    // Initialize array of 4 pointers to functions 
    void (*processGrades[4])(int, int, int grades[students][exams]) = {printArray, minimum, maximum, average};

    // Process user's choice
    do {

        puts("Enter a choice:");
        puts("\t0   Print the array of grades");
        puts("\t1   Find the minimum grade");
        puts("\t2   Find the maximum grade");
        puts("\t3   Print the average on all tests for each student");
        puts("\t4   End Program");
        printf("\n\tEntry: ");

        scanf("%d", user_choice);

        if (*user_choice < end) {
            
            processGrades[*user_choice](students, exams, grades);
            puts("");

        } else if (*user_choice != end) {
            
            puts("Invalid choice, please try again.");

        }

    } while (*user_choice != end);

    puts("\n\tThank you for using the TU Array Grading System.");
    exit(0);

}


void printArray(int students, int exams, int grades[students][exams]){
    puts("\nThe array is:\n");
    
    // Shows the index of each exam in the array 
    printf("               ");
    for(int j = 0; j < exams; j++) {
        printf("%*s", 2, "");
        printf("[%d]", j);
    }

    // Prints the array out
    for (int i = 0; i < students; i++) {

        printf("\nstudentGrades[%u] ", i);

        for (int j = 0; j < exams; j++) {

            printf("%-5d", grades[i][j]);

        }
    }
    puts("\n");



}


void minimum(int students, int exams, int grades[students][exams]){
    // Takes the first cell of the array as the minimum
    double min = grades[0][0];

    // Looks for any smaller element in the array, replacing minimum's value until there is no smaller number
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < exams; j++) {
            if (grades[i][j] < min) {
                min = grades[i][j];
            }
        }
    }
    // Prints the minimum grade 
    puts("\n");
    printf("Lowest grade: %.2f\n", min);
    puts("\n");


}


void maximum(int students, int exams, int grades[students][exams]){
    // Takes the first cell of the array as the maximum
    double max = grades[0][0];

     // Looks for any bigger element in the array, replacing maximum's value until there is no bigger number
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < exams; j++) {
            if (grades[i][j] > max) {
                max = grades[i][j];
            }
        }
    }
    // Prints the maximum grade 
    puts("\n");
    printf("Highest grade: %.2f\n", max);
    puts("\n");


}


void average(int students, int exams, int grades[students][exams]){
    puts("\n");

    // Goes through the array's rows, to get the average grade of each student.  
    for (int i = 0; i < students; i++) {
        double sum = 0;
        for (int j = 0; j < exams; j++) {
            sum += grades[i][j];
        }
        printf("The average grade for student %d is %.2f\n", i, (float)sum/exams);
    }
    puts("\n");


}

