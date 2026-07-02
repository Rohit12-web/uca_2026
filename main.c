#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {

    int n1 = 40000;
    int n2 = 80000;

    int *arr1 = (int *)malloc(n1 * sizeof(int));
    int *arr2 = (int *)malloc(n2 * sizeof(int));

    if (arr1 == NULL || arr2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < n1; i++)
        arr1[i] = rand();

    for (int i = 0; i < n2; i++)
        arr2[i] = rand();

    clock_t start, end;
    double time1, time2;

    start = clock();
    bubbleSort(arr1, n1);
    end = clock();

    time1 = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    bubbleSort(arr2, n2);
    end = clock();

    time2 = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken for %d elements : %.4f seconds\n", n1, time1);
    printf("Time taken for %d elements : %.4f seconds\n", n2, time2);

    printf("Ratio (Time2 / Time1) = %.2f\n", time2 / time1);

    free(arr1);
    free(arr2);

    return 0;
}

