# Lab 5 – Starting Sorting

## Q1: Sorting Algorithms

### Selection Sort

**Original Selection Sort Pseudo Code:**
```plaintext
Selection sort(A, N)
for i = 0 to i < N - 1 do
    min = i
    for j = i + 1 to j < N do
        if A[j] < A[min] then
            min = j
        end if
    end for
    temp = A[min]
    A[min] = A[i]
    A[i] = temp
end for
```

**Improvement in Selection Sort:**
One improvement in the selection sort algorithm could be to reduce unnecessary swaps. Instead of swapping within the inner loop whenever a smaller element is found, we can defer the swap to the outer loop and only swap after identifying the minimum element of the remaining array.

**Improved Selection Sort:**
```c
/*
Improved Selection Sort Algorithm
*/
for (i = 0; i < N - 1; ++i) {
    min = i;
    for (j = i + 1; j < N; ++j) {
        if (A[j] < A[min]) {
            min = j;
        }
    }
    // Only swap if min has changed, reducing unnecessary swaps
    if (min != i) {
        temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
}
```

**How it improves efficiency:**  
By reducing the number of swaps to only one per iteration of the outer loop (instead of potentially swapping for every comparison inside the inner loop), we minimize the overhead of the `swap` operation.

---

### Bubble Sort

**Original Bubble Sort Pseudo Code:**
```plaintext
Bubble sort(A, N)
for i = 0 to i < N - 1 do
    for j = 0 to j < N - 1 do
        if A[j] > A[j + 1] then
            swap A[j] and A[j + 1]
        end if
    end for
end for
```

**Improvement in Bubble Sort:**
One common improvement in the Bubble Sort algorithm is to use a flag (`swap`) to detect if a pass through the array made no swaps. If no swaps occur, it means the array is already sorted, and we can terminate early.

**Improved Bubble Sort:**
```c
/*
Improved Bubble Sort Algorithm
*/
i = 0;
do {
    swap = false; // Start by assuming the array is sorted
    for (j = 0; j < N - i - 1; ++j) {  // Reduce the comparison range
        if (A[j] > A[j + 1]) {
            // Swap the elements
            temp = A[j];
            A[j] = A[j + 1];
            A[j + 1] = temp;
            swap = true; // Mark swap as true to indicate sorting is still needed
        }
    }
    ++i;
} while (swap && i < N - 1);
```

**How it improves efficiency:**  
- **Early exit:** If the array becomes sorted before all the passes are complete, the loop terminates early, reducing the number of iterations.
- **Reduced comparison range:** After each pass, the largest element is in its correct position, so we reduce the number of comparisons in each subsequent pass.

**Example with `[1, 2, 4, 3]`:**
- After the first pass, 4 and 3 will swap, but 2 is already sorted. The `swap` flag will allow the algorithm to exit early in the second pass as the array is already sorted.

---

## Q2: Big O Complexity of Algorithms

### a. Iterative GCD Algorithm:
- **Algorithm:** The Euclidean algorithm for GCD involves repeatedly finding the remainder of division until the remainder is zero. The number of iterations depends on how large the numbers are.
- **Big O Complexity:** The Big O of the iterative GCD algorithm is **O(log(min(a, b)))** because with each step, the size of the numbers is reduced significantly due to division. This is more efficient than **O(n)**.

### b. Tree Drawing Algorithm:
- **Algorithm:** Based on the typical implementation of a tree-drawing algorithm (e.g., recursive generation of tree-like structures), the complexity is typically **O(n * log n)**. This is because for each level of recursion (log n levels), we process `n` elements.
- **Big O Complexity:** The Big O is **O(n * log n)** as it's a divide-and-conquer problem.

### c. Rock/Paper/Scissors Algorithm:
- **Algorithm:** Depending on how Rock/Paper/Scissors is implemented, if we are simulating all possible outcomes or iterating through possibilities, the algorithm is likely comparing choices or outcomes.
- **Big O Complexity:** Assuming simple simulations or game matchups between a fixed number of players, the Big O could be **O(1)** if each player chooses once and we determine the winner in constant time. However, if there are multiple rounds or players, it might involve higher complexities like **O(n)** or **O(n^2)**, but typically **O(1)**.

---

## Final Solution:
```c
/*
Q1: Improved Selection Sort
Selection Sort Algorithm
*/
for (i = 0; i < N - 1; ++i) {
    min = i;
    for (j = i + 1; j < N; ++j) {
        if (A[j] < A[min]) {
            min = j;
        }
    }
    if (min != i) {
        temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
}

/*
Q1: Improved Bubble Sort
Bubble Sort Algorithm
*/
i = 0;
do {
    swap = false;
    for (j = 0; j < N - i - 1; ++j) {
        if (A[j] > A[j + 1]) {
            temp = A[j];
            A[j] = A[j + 1];
            A[j + 1] = temp;
            swap = true;
        }
    }
    ++i;
} while (swap && i < N - 1);

/*
Q2: Big O Complexity
a. Iterative GCD algorithm: O(log(min(a, b))) because it reduces the size of the numbers by a factor.
b. Tree-drawing algorithm: O(n * log n) as it divides the work and processes each subpart.
c. Rock/Paper/Scissors algorithm: O(1) for a single round, but it could be O(n) or higher for multiple rounds.
*/