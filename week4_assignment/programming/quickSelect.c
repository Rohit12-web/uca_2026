#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Your partition scheme, unchanged in logic:
// picks a[L] as pivot, places smaller elements before it,
// returns the pivot's final sorted position
int partition(int a[], int L, int R) {
    int p = L;
    int x = L;
    int i = L + 1;

    for (; i <= R; i++) {
        if (a[i] < a[p]) {
            swap(a, i, ++x);
        }
    }

    swap(a, p, x);
    return x; // pivot's final index
}

// Quickselect: rearranges a[] so the first k elements (a[0..k-1])
// are the k smallest, using the SAME partition scheme as above
void quickSelect(int a[], int L, int R, int k) {
    if (L >= R)
        return;

    int pivotIndex = partition(a, L, R);
    int countLeft = pivotIndex - L + 1; // elements <= pivot from L to pivotIndex

    if (countLeft == k) {
        return; // exactly k elements found on the left side (including pivot)
    } else if (countLeft > k) {
        quickSelect(a, L, pivotIndex - 1, k);
    } else {
        quickSelect(a, pivotIndex + 1, R, k - countLeft);
    }
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    if (!a) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter K (number of smallest elements to find): ");
    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("Invalid K value\n");
        free(a);
        return 1;
    }

    quickSelect(a, 0, n - 1, k);

    printf("The smallest %d elements are: ", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}
