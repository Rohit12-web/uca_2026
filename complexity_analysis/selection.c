#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_SIZE 8000
#define STEP_SIZE 4000
#define ITERATIONS 8

// Selection Sort

void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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

    selectionSort(arr, n);

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

        printf("Selection,Random,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        // Ascending

        generateAscending(original, size);
        copyArray(original, temp, size);

        printf("Selection,Ascending,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        // Descending

        generateDescending(original, size);
        copyArray(original, temp, size);

        printf("Selection,Descending,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        free(original);
        free(temp);
    }

    return 0;
}
