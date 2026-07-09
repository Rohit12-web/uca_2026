#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_SIZE 8000
#define STEP_SIZE 4000
#define ITERATIONS 8

// Heap Sort

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (i = n - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
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

    heapSort(arr, n);

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

        printf("Heap,Random,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        // Ascending

        generateAscending(original, size);
        copyArray(original, temp, size);

        printf("Heap,Ascending,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        // Descending

        generateDescending(original, size);
        copyArray(original, temp, size);

        printf("Heap,Descending,%d,%.3lf\n",
               size,
               measureTime(temp, size));

        free(original);
        free(temp);
    }

    return 0;
}
