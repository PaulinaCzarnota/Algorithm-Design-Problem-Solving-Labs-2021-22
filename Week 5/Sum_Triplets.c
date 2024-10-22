/*
Program Description: Program that takes the input and prints how many triples summing to 0 there are.
Author: Paulina Czarnota
Date: 21/02/22
*/

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Function to find the number of triples that sum to 0
int countTriplets(int A[], int arr_size, int sum)
{
    int count = 0;  // Variable to store the count of triplets

    // Iterate over the array to fix the first element
    for (int i = 0; i < arr_size - 2; i++) {
        // Iterate over the remaining elements to fix the second element
        for (int j = i + 1; j < arr_size - 1; j++) {
            // Iterate over the remaining elements to fix the third element
            for (int k = j + 1; k < arr_size; k++) {
                // Check if the sum of the three elements is equal to the target sum (0)
                if (A[i] + A[j] + A[k] == sum) {
                    printf("Triplet is %d, %d, %d\n", A[i], A[j], A[k]);
                    count++;  // Increment the count of triplets
                }
            }
        }
    }
    return count;  // Return the total count of triplets
}

int main()
{
    // Declare variables for measuring execution time
    time_t pStart, pEnd;  

    // Record the start time
    pStart = clock();

    // Sample array
    int A[] = { 30, -40, -20, -10, 40, 0, 10, 5 };  
    int sum = 0;  // Target sum to find
    int arr_size = sizeof(A) / sizeof(A[0]);  // Calculate the size of the array

    // Call the function to count triplets that sum to 0
    int triplet_count = countTriplets(A, arr_size, sum);

    // Print the result
    printf("Total number of triplets that sum to 0: %d\n", triplet_count);

    // Record the end time
    pEnd = clock();

    // Calculate and display the elapsed time
    printf("Elapsed time is %1.7lf seconds\n", (double)(pEnd - pStart) / CLOCKS_PER_SEC);

    return 0;
}