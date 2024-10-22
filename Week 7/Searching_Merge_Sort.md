# Lab 6 – Starting Searching and Reviewing Merge Sort

## Part I: Starting Searching

### 1. Algorithm to Find Maximum and Minimum in an Unordered Array

```plaintext
int[] getMaxMin(int A[], int n)
{
    int max = A[0]; // Initialize max to the first element
    int min = A[0]; // Initialize min to the first element
    for (i = 1 to n-1) // Loop through the array
    {
        if (A[i] > max) // Check if current element is greater than max
            max = A[i]; // Update max
        else if (A[i] < min) // Check if current element is less than min
            min = A[i]; // Update min
    }
    // By convention, let ans[0] = maximum and ans[1] = minimum
    int ans[2] = {max, min}; // Store max and min in an array
    return ans; // Return the array
}
```

### 2. Big O Analysis

The Big O of this algorithm is **O(n)**. This is because we make a single pass through the array, performing two comparisons at each step. Therefore, the total number of comparisons in the worst case is \(2 \cdot (n - 1) = 2n - 2\), which simplifies to **O(n)**.

### 3. Implementation in C

```c
#include <stdio.h>

int main()
{
    int Nums[1000]; // Array to hold numbers
    int i;
    int n; // Size of the array
    int min;
    int max;

    printf("Enter size of the array: ");
    scanf("%d", &n); // Input size of the array

    printf("Enter elements in array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &Nums[i]); // Input array elements
    }

    min = max = Nums[0]; // Initialize min and max
    for (i = 1; i < n; i++)
    {
        if (min > Nums[i]) // Check for new minimum
            min = Nums[i];
        if (max < Nums[i]) // Check for new maximum
            max = Nums[i];
    }
    printf("Minimum of array is: %d\n", min); // Output minimum
    printf("Maximum of array is: %d\n", max); // Output maximum

    return 0;
}
```

### 4. Algorithm to Search for a Particular Number in an Ordered Array

```plaintext
int FindArray(int a[], int size, int item)
{
    int i;
    for (i = 0 to size - 1) // Loop through the array
    {
        if (a[i] == item) // Check if current element matches the item
            return i; // Return position if found
    }
    return -1; // Return -1 if not found
}
```

### 5. Big O Analysis

The Big O of this algorithm is **O(n)**. In the worst case, we may need to look at every element in the array, leading to a linear time complexity.

### 6. Implementation in C

```c
#include <stdio.h>
#define MAX 20

void readArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &a[i]); // Input array elements
    }
}

int findElement(int a[], int size, int item)
{
    int i, pos = -1; // Initialize position to -1
    for (i = 0; i < size; i++)
    {
        if (a[i] == item) // Check if current element matches the item
        {
            pos = i; // Update position
            break; // Exit loop if found
        }
    }
    return pos; // Return position or -1 if not found
}

int main()
{
    int arr[MAX]; // Array to hold elements
    int n, item, pos;

    printf("Enter size of an Array: ");
    scanf("%d", &n); // Input size of the array

    printf("Enter elements of the Array:\n");
    readArray(arr, n); // Read array elements

    printf("Enter an item to find: ");
    scanf("%d", &item); // Input item to find

    pos = findElement(arr, n, item); // Search for the item
    if (pos == -1)
        printf("%d does not exist in the array.\n", item);
    else
        printf("%d found at position %d.\n", item, pos); // Output position

    return 0;
}