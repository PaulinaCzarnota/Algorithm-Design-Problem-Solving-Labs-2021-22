/*
Program Description: Program that generates ASCII "tree" of user determined size
Author: C21365726 Paulina Czarnota
Date: 07/02/2022
*/

#include <stdio.h>

int main()
{
    int size;

    printf("Enter tree size:\n");
    scanf("%d", &size);

    // loops for each line of the tree
    for (int line = 1; line <= size; ++line)
    {
        // loops for the spaces on each line
        for (int j = 0; j < (size - line); ++j)
        {
            printf(" ");
        }

        // loops for the stars on each line
        for (int j = 0; j < ((2 * line) - 1); ++j)
        {
            printf("*");
        }

        printf("\n"); // goes to the next line of the tree
    }

    // below is for the trunk
    for (int i = 0; i < size - 1; ++i)
    {
        // prints the spaces before the trunk
        printf(" ");
    }

    printf("*\n"); // prints the trunk and moves to the next line
    return 0;
}