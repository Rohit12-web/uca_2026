#include <stdio.h>

typedef struct
{
    int value;
    int index;
} Node;

int result[100000];
Node temp[100000];

void merge(Node arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right)
    {
        if (arr[j].value < arr[i].value)
        {
            temp[k++] = arr[j++];
            rightCount++;
        }
        else
        {
            result[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid)
    {
        result[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(Node arr[], int left, int right)
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
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    Node arr[100000];

    for (int i = 0; i < n; i++)
    {
        arr[i].value = nums[i];
        arr[i].index = i;
        result[i] = 0;
    }

    mergeSort(arr, 0, n - 1);

    printf("Output: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }

    printf("\n");

    return 0;
}