#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_SIZE 8000
#define STEP_SIZE 4000
#define ITERATIONS 8

// Bubble Sort

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
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

    bubbleSort(arr, n);

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

        printf("Bubble,Random,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        // Ascending

        generateAscending(original, size);
        copyArray(original, temp, size);

        printf("Bubble,Ascending,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        // Descending

        generateDescending(original, size);
        copyArray(original, temp, size);

        printf("Bubble,Descending,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        free(original);
        free(temp);
    }

    return 0;
}
