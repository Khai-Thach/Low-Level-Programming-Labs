#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Khai Thach
9/6/2024
CIS 2107
Lab 02 Paycheck/Revenue
Problem: Write a C program called revenue to calculate the revenue from 
a sale based on the unit price and quantity of a product input by the user.
 */

int main() {

    double price;
    double quantity;
    double cost;
    double discount;
    double discountAmount;
    double total;

    printf("  Welcome to \"Temple\" store\n\n");

    // input item price
    printf("\tEnter item price: ");
    scanf("%lf", &price);

    // checks validity of item price input
    if (price <= 0) {
        printf("\n\tThis is not a valid item price.\n\tPlease run the program again\n\n");
        printf("\n  Thank You for using \"Temple\" store\n");
        exit(1);
    }
    
    // input quantity
    printf("\tEnter quantity: ");
    scanf("%lf", &quantity);

    // checks validity of quantity input
    if (quantity <= 0 ) {
        printf("\n\tThis is not a valid quantity order.\n\tPlease run the program again\n\n");
        printf("  Thank You for using \"Temple\" store\n");
        exit(1);
    }

    // handles decimal cases
    double integer;
    double fraction = modf(quantity, &integer);
    if (fraction != 0.0) {
        printf("\n\tThis is not a valid quantity order.\n\tPlease run the program again\n\n");
        printf("  Thank you for using \"Temple\" store\n");
        exit(1);
    }
    
    // results results after user input
    printf("\n\tThe item price is: %.1f\n", price);
    printf("\tThe order is: %.0f item(s)\n", quantity);

    // calculates cost before discount
    cost = price * quantity;
    printf("\tThe cost is: $%.2f\n", cost);

    // conditions of discount percentage
    if (quantity >= 1 && quantity <= 49) {
        discount = 0.0;
        printf("\tThe discount is: %.1f%%\n", discount);

    } else if (quantity >= 50 && quantity <= 99) {
        discount = 10.0;
        printf("\tThe discount is: %.1f%%\n", discount);

    } else if (quantity >= 100 && quantity <= 149) {
        discount = 15.0;
        printf("\tThe discount is: %.1f%%\n", discount);

    } else if (quantity >= 150) {
        discount = 25.0;
        printf("\tThe discount is: %.1f%%\n", discount);
    
    }

    // discount calculation
    discountAmount = quantity * (discount/10);
    printf("\tThe discount amount is: $%.1f\n", discountAmount);

    total = cost - discountAmount;
    printf("\tThe total is: $%.1f\n", total);
    
    // end of program
    printf("\n  Thank You for using \"Temple\" store\n");
    exit(0);

}