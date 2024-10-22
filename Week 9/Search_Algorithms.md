# Lab 8 – Implementing Merge Sort & Searching Algorithms
By Paulina Czarnota  
Date: 21/03/2022

## Overview

This repository contains the implementation of the Merge Sort algorithm and various searching algorithms in C. The project is divided into two main parts: Merge Sort and Search Algorithms.

## Part 1 - Merge Sort Algorithm in C

### Description

This C program allows the user to input 8 random numbers, which are stored in an array. It then displays the unsorted array and prints out the sorted array after executing the merge sort algorithm.

### Code Implementation

```c
#include <stdio.h>

#define SIZE 8  // Define the size of the array

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) 
{
    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1; // Size of left subarray
    int n2 = r - q;     // Size of right subarray

    int L[n1], M[n2];   // Temporary arrays for left and right subarrays

    // Copy data to temporary arrays L[] and M[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i = 0, j = 0, k = p;

    // Merge the temporary arrays back into arr[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of M[], if any
    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them, and merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);          // Sort the first half
        mergeSort(arr, m + 1, r);      // Sort the second half

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[SIZE];  // Declare an array of fixed size
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the number of elements in the array

    printf("Input 8 random numbers please: \n");
    
    // Input elements into the array
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]); // Store input numbers in the array
    }

    // Call mergeSort function to sort the array
    mergeSort(arr, 0, size - 1);

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;  // Exit the program
}
```

## Part 2 - Search Algorithms in C

### Description

This part of the program implements a search algorithm that allows the user to search for a particular element in an array and returns the index of the element if found.

### Code Implementation

```c
#include <stdio.h>
#include <stdbool.h>  // Include for boolean data type

// Check if it's safe to place a queen in board[row][col]
bool isSafe(int board[][10], int row, int col, int n)
{
    // Check this row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;  // No conflicts found
}

// Solve N-Queens problem using backtracking
bool nQueen(int board[][10], int col, int n)
{
    if (col >= n) {
        // Print the solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        return true;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;  // Place queen
            if (nQueen(board, col + 1, n)) {
                return true;
            }
            board[i][col] = 0;  // Backtrack
        }
    }
    return false;  // No solution found
}

int main() {
    int n;
    int board[10][10] = {0};  // Initialize the board with zeros
    scanf("%d", &n);  // Input size of the board
    bool check = nQueen(board, 0, n);  // Start solving the N-Queens problem

    if (check == false)
        printf("-1");  // No solution
    else {
        // Print the board with queens placed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d    ", board[i][j]);
            }
            printf("\n");
        }
    }
    return 0;  // Exit the program
}
```

## Part 3 - Recursive Binary Search Algorithm

### Description

This C program implements a recursive binary search algorithm. It searches for a specified number in an array and prints the index where it was found.

### Code Implementation

```c
#include <stdio.h> 

// A recursive binary search function. It returns the location of x in the given array arr[l..r] if present, otherwise -1 
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) 
    { 
        int mid = l + (r - l) / 2;  // Calculate mid index

        // If the element is present at the middle itself 
        if (arr[mid] == x)   
            return mid; 

        // If the element is smaller than mid, then it can only be present in the left subarray 
        if (arr[mid] > x)  
            return binarySearch(arr, l, mid - 1, x); 

        // Else the element can only be present in the right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 

    // Element not present in array 
    return -1; 
} 

int main(void) 
{ 
    int arr[] = {2, 3, 4, 10, 40}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate number of elements
    int x = 10;  // Element to search
    int result = binarySearch(arr, 0, n - 1, x); 

    // Output the result of the search
    (result == -1) ? printf("Element is not present in array") 
                   : printf("Element is present at index %d", result); 
    return 0;  // Exit the program
} 