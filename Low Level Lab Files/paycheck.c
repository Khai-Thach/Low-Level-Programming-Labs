#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Khai Thach
9/6/2024
CIS 2107
Homework 02
Problem: Write a C program called paycheck to calculate the paycheck for a Temple employee based on 
the hourlySalary, weeklyTime (working for maximum 40 hours) and overtime (working for more than 40 hours).
 */

int main() {
    printf("  Welcome to \"TEMPLE HUMAN RESOURCES\"\n\n");

    double empNum;
    double hrlySal;
    double wklyTime;
    double netPay;
    const double regTime = 40.0;

    // Input employee number
    printf("\tEnter Employee Number: ");
    scanf("%lf", &empNum); 

    // stops program when given an invalid input
    if (empNum <= 0) {
        printf("\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n");
        printf("\n  Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    }
    
    // handles decimal cases
    double integer;
    double fraction = modf(empNum, &integer);
    if (fraction != 0.0) {
        printf("\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n");
        printf("\n  Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    }

    // Input hourly salary
    printf("\tEnter Hourly Salary: ");
    scanf("%lf", &hrlySal);

    if (hrlySal < 0) {
        printf("\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again\n");
        printf("\n  Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    }

    // Input weekly time
    printf("\tEnter Weekly Time: ");
    scanf("%lf", &wklyTime);

    if (wklyTime <= 0) {
        printf("\n\tThis is not a valid weekly time.\n\tPlease run the program again\n");
        printf("\n  Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    }
    // prints out information after checks
    printf("\t==============================\n");
    printf("\tEmployee #: %.0f\n", empNum);
    printf("\tHourly Salary: $%.1f\n", hrlySal);
    printf("\tWeekly Time: %.1f\n", wklyTime);
    
    // calculates payment
    if (wklyTime > regTime) {
        double overTime = wklyTime - regTime;
        double regPay = hrlySal * regTime;
        double overTimePay = overTime * hrlySal * 1.5;
        netPay = regPay + overTimePay;

        printf("\tRegular Pay: $%.1f\n", regPay);
        printf("\tOvertime Pay: $%.1f\n", overTimePay);
        printf("\tNet Pay: $%.1f\n", netPay);
    } else {
        netPay = hrlySal * wklyTime;
        printf("\tNet Pay: $%.1f\n", netPay);
    }
    
    // end of program
    printf("\t==============================\n");
    printf("  Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");

    exit(0);
}
