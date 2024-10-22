/*
Program description: Program to Display Fibonacci Sequence
Author: Paulina Czarnota
Date: 14/02/22
*/

#include <stdio.h>

int main() 
{
    int i, n;

    // Initialize first and second terms
    int t1 = 0, t2 = 1;

    // Initialize the next term
    int nextTerm = t1 + t2;

    // Get the number of terms from the user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Check if the input is valid
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;  // Exit the program if the input is invalid
    }

    // Display Fibonacci sequence based on the number of terms
    printf("Fibonacci Series: ");

    if (n == 1) {
        // If the user wants only 1 term
        printf("%d\n", t1);
    } 
    else if (n == 2) {
        // If the user wants exactly 2 terms
        printf("%d, %d\n", t1, t2);
    } 
    else {
        // If the user wants more than 2 terms, print the first two terms
        printf("%d, %d, ", t1, t2);

        // Loop to print the next terms from the 3rd to nth
        for (i = 3; i <= n; ++i) 
        {
            printf("%d", nextTerm);
            if (i != n) {
                printf(", ");  // Add a comma except after the last term
            }

            // Update terms for the next iteration
            t1 = t2;
            t2 = nextTerm;
            nextTerm = t1 + t2;
        }
        printf("\n");  // Move to the next line after the sequence
    }

    return 0;
}