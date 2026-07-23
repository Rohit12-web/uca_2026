#include <stdio.h>

typedef struct
{
    int value;
    int index;
} Node;

int answer[100000];

void merge(Node arr[], int L, int mid, int R, Node temp[])
{
    int i = L;
    int j = mid + 1;
    int k = L;
    int rightCount = 0;

    while (i <= mid && j <= R)
    {
        if (arr[j].value < arr[i].value)
        {
            temp[k++] = arr[j++];
            rightCount++;
        }
        else
        {
            answer[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid)
    {
        answer[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= R)
        temp[k++] = arr[j++];

    for (i = L; i <= R; i++)
        arr[i] = temp[i];
}

void mergeSort(Node arr[], int L, int R, Node temp[])
{
    if (L >= R)
        return;

    int mid = L + (R - L) / 2;

    mergeSort(arr, L, mid, temp);
    mergeSort(arr, mid + 1, R, temp);
    merge(arr, L, mid, R, temp);
}

int main()
{
    int n;
    scanf("%d", &n);

    Node arr[n], temp[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        answer[i] = 0;
    }

    mergeSort(arr, 0, n - 1, temp);

    for (int i = 0; i < n; i++)
        printf("%d ", answer[i]);

    printf("\n");

    return 0;
}