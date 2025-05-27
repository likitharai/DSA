#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the array
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Function to perform insertion sort
void insertionSort(int a[], int n) {
    int i, j, key;
    for (j = 1; j < n; j++) {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
}

// Main function
int main() {
    clock_t start, end;
    double CPU_time_used;
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Generating an array of %d random elements...\n", n);
    for (i = 0; i < n; i++) {
        a[i] = rand() % 1000; // Generates random numbers from 0 to 999
    }

    printf("\nOriginal array:\n");
    printArray(a, n);

    start = clock();
    insertionSort(a, n);
    end = clock();

    CPU_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted array:\n");
    printArray(a, n);
    printf("\nCPU time taken for sort: %g seconds\n", CPU_time_used);

    return 0;
}
