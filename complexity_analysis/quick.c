#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_SIZE 8000
#define STEP_SIZE 4000
#define ITERATIONS 8

// Quick Sort

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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

    quickSort(arr, 0, n - 1);

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

        printf("Quick,Random,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        // Ascending

        generateAscending(original, size);
        copyArray(original, temp, size);

        printf("Quick,Ascending,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        // Descending

        generateDescending(original, size);
        copyArray(original, temp, size);

        printf("Quick,Descending,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        free(original);
        free(temp);
    }

    return 0;
}
