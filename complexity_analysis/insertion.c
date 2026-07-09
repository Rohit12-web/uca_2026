#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_SIZE 8000
#define STEP_SIZE 4000
#define ITERATIONS 8

// Insertion Sort

void insertionSort(int arr[], int n)
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Input Generators

void generateRandom(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        arr[i] = rand();
}

void generateAscending(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        arr[i] = i;
}

void generateDescending(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        arr[i] = n - i;
}

// Copy Array

void copyArray(int source[], int destination[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        destination[i] = source[i];
}

// Measure Execution Time

double measureTime(int arr[], int n)
{
    clock_t start, end;

    start = clock();

    insertionSort(arr, n);

    end = clock();

    return ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
}

int main()
{
    int size;

    srand(time(NULL));

    printf("Algorithm,Input,Size,Time(ms)\n");

    for (size = START_SIZE;
         size <= START_SIZE + STEP_SIZE * (ITERATIONS - 1);
         size += STEP_SIZE)
    {
        int *original = (int *)malloc(size * sizeof(int));
        int *temp = (int *)malloc(size * sizeof(int));

        if (original == NULL || temp == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        // Random

        generateRandom(original, size);
        copyArray(original, temp, size);

        printf("Insertion,Random,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        // Ascending

        generateAscending(original, size);
        copyArray(original, temp, size);

        printf("Insertion,Ascending,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        // Descending

        generateDescending(original, size);
        copyArray(original, temp, size);

        printf("Insertion,Descending,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        free(original);
        free(temp);
    }

    return 0;
}

