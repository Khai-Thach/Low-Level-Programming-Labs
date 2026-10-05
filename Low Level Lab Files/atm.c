#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Khai Thach;
9/15/2024
CIS 2107
Homework 03
Problem: Write a C Program for an ATM machine by implementing functions.
 */

int main() {
    // Prerequisites to start/end the ATM program
    int pin;
    int balance = 5000;
    int attempt = 0;
    int max_attempts = 3;

    // ATM menu selection variables
    int user_choice;
    int check_balance = 1;
    int cash_withdrawal = 2;
    int cash_deposit = 3;
    int exit_atm = 4;

    // holds the number of transaction done overall
    int transactions = 0;

    // global variables that track function data
    int total_withdrawals = 0;
    int total_deposits = 0;
    int print_receipt;

    // welcoming message
    puts("\tWelcome to TU Bank\n");

    // handles pin errors
    while (attempt < max_attempts) {
        printf("Enter Pin: ");
        scanf("%d", &pin);

        if (pin <= 0) {
            puts("Invalid pin.");
            attempt++;

        } else {

            break;
        }

    }
    
    // ends the program when the maximum attempt is reached
    if (attempt == max_attempts) {
            puts("\n\tMultiple invalid pins entered. Ending program.");
            exit(1);
        }
    
    // ATM menu that will continue to appear until the user gives the proper input
    do {   
    
    // ATM menu screen
    puts("\n\tATM Menu");
    puts("1. Check Balance");
    puts("2. Withdraw Cash");
    puts("3. Deposit Cash");
    puts("4. Quit");
    
    printf("\nEnter number choice: ");
    scanf("%d", &user_choice);

        // user choices
        if (user_choice == check_balance) {
            checkBalance(&balance);

        } else if (user_choice == cash_withdrawal) {
            withdrawCash(&balance, &total_withdrawals, &print_receipt);
            transactions++;

        } else if (user_choice == cash_deposit) {
            depositCash(&balance, &total_deposits, &print_receipt);
            transactions++;

        } 

    } while (user_choice != exit_atm);

    
    
    // ending message 
    puts("\n\tThank you for using TU Banking");
    printf("\n\tNumber of transactions made: %d\n", transactions);


    exit(0);


        
 }

// prints out user's balance
 void checkBalance(int *balance) {

    printf("Your balance is: $%d\n", *balance);

 }

// handles withdrawals done by the user
 void withdrawCash(int *balance, int *total_withdrawals, int *print_receipt) {
    
    // declaring variables key to the function
    int withdrawal_amount;
    int max_withdrawal = 1000;
    int withdrawal_attempt = 0;
    int max_withdrawal_attempts = 3;

    // checks if the max total of withdrawals has been made before continuing
    if (*total_withdrawals == max_withdrawal) {
        puts("Daily limit reached.");
        return;
    }

    // loop will end when maximum attempt is reached and when total withdrawal is greater than max withdrawals
    while (withdrawal_attempt < max_withdrawal_attempts && *total_withdrawals < max_withdrawal) {

        // begins user withdrawal input
        printf("\nEnter withdrawal amount ($1,000 limit a day): ");
        scanf("%d", &withdrawal_amount);
        
        // handles wrong inputs
        if (withdrawal_amount > *balance) {
            puts("withdrawal amount exceeds balance.\nEnter again. ");
            return;

        } else if ( withdrawal_amount <= 0) {
            puts("Invalid withdrawal amount.\nEnter again. ");

        } else if (withdrawal_amount % 20 != 0) {
            puts("amount is not a multiple of 20.\nEnter again. ");

        } else if (withdrawal_amount + *total_withdrawals > max_withdrawal) {
            puts("Daily limit reached.\nWithdraw less.");

        } else {
            break;
        }

        // incremenets number of attempts 
        withdrawal_attempt++;
    
    }

    // ends the program when the max attempts is reached
    if (withdrawal_attempt == max_withdrawal_attempts) {
        puts("You have entered multiple wrong inputs. Ending program.");
        exit(1);
    }

    // calculates the user's inputs and stores the changes into the global variables that record the data
    *balance -= withdrawal_amount;
    *total_withdrawals += withdrawal_amount;

    // transaction receipt
    printf("Would you like a receipt for your deposit transaction?\n[1] yes\n[2] no\n");
    scanf("%d", print_receipt);

    // handles invald input
    while (*print_receipt != 1 && *print_receipt != 2) {
        puts("Invalid choice.\nEnter Again.");
        scanf("%d", print_receipt);
    }

    // prints/doesn't print receipt given user's choice
    if(*print_receipt == 1) {
        puts("\t\"Withdrawal Receipt\"");
        printf("\n\tTotal withdrawals: $%d", *total_withdrawals);
        printf("\n\tNew balance: $%d\n", *balance);
    } else if (*print_receipt == 2) {
        puts("\nReturning to menu.");
        return;
    }
    
 }

// handles deposits done by the user
 void depositCash(int *balance, int *total_deposits, int *print_receipt) {
    
    // declaring variables key to the function
    int deposit_amount;
    int max_deposit = 10000;
    int deposit_attempt = 0;
    int max_deposit_attempts = 3;
    
    // checks if the max total of withdrawals has been made before continuing
    if(*total_deposits >= max_deposit) {
        puts("Daily limit reached.");
        return;
    }

    // loop will end when maximum attempt is reached and when total deposit is greater than max withdrawals
    while (deposit_attempt < max_deposit_attempts) {

        printf("\nEnter deposit amount ($10,000 limit a day): ");
        scanf("%d", &deposit_amount);
       
        // handles invalid inputs
        if (deposit_amount < 0) {
            puts("Invalid deposit amount.\nEnter again.");
            deposit_attempt++;

        } else if (deposit_amount + *total_deposits > max_deposit) {
            puts("Daily limit reached.\nDeposit less.");
            deposit_attempt++;
        } else {
            break;
        }
    }

    // if max attempt is reached, end the program
    if(deposit_attempt == max_deposit_attempts) {
        puts("You have entered multiple wrong inputs. Ending program.");
        exit(1);
    } 
    
    // calculates balance based on the user's input and stores the changes in the global variable containing the data
    *balance += deposit_amount;
    *total_deposits += deposit_amount;
    
    // provides the user an option to see their receipt or not 
    printf("Would you like a receipt for your deposit transaction?\n[1] yes\n[2] no\n");
    scanf("%d", print_receipt);

    // handles invalid user input
    while (*print_receipt != 1 && *print_receipt != 2) {
        puts("Invalid choice.\nEnter Again.");
        scanf("%d", print_receipt);
    }

    // prints/doesn't print transaction receipt of the user
    if(*print_receipt == 1) {
        puts("\t\"Deposit Receipt\"");
        printf("\n\ttotal deposit(s): $%d", *total_deposits);
        printf("\n\tNew balance: $%d\n", *balance);
    } else if (*print_receipt == 2) {
        puts("\nReturning to menu.");
        return;
    }
 }