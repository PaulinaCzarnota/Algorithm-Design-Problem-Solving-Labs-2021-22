/*
Program description: Program for Tower of Hanoi using Recursion
Author: Paulina Czarnota
Date: 14/02/22
*/

#include <stdio.h>

// Function to solve Tower of Hanoi
// n: number of disks
// source: the starting rod
// dest: the target rod
// spare: the auxiliary rod
void towerOfHanoi(int n, char source, char dest, char spare);

int main(void) 
{
    int n;  // Number of disks to move
    char source = 'A'; // Initial peg (source peg)
    char dest = 'B';   // Destination peg
    char spare = 'C';  // Auxiliary peg (spare peg)

    // Prompt the user for the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Output the sequence of moves
    printf("Here is the sequence of moves for the Tower of Hanoi:\n");
    towerOfHanoi(n, source, dest, spare);  // Call the recursive function

    return 0;  // End the program
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char dest, char spare)
{
    // Base case: If there is only one disk, move it directly from source to destination
    if (n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, source, dest);
        return;  // Exit the function after the move
    }

    // Recursive step:
    // Move the top (n-1) disks from source to spare using destination as auxiliary
    towerOfHanoi(n - 1, source, spare, dest);

    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, dest);

    // Move the (n-1) disks from spare to destination using source as auxiliary
    towerOfHanoi(n - 1, spare, dest, source);
}