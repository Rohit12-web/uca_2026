#include <stdio.h>

long long count = 0;

void merge(int arr[], int left, int mid, int right)
{
    int temp[100000];
    int i, j, k;

    // Count inversions
    i = left;
    j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            i++;
        }
        else
        {
            count += (mid - i + 1);
            j++;
        }
    }

    // Merge the two sorted halves
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main()
{
    int arr[] = {1, 2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printf("Output: %lld\n", count);

    return 0;
}