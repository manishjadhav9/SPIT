#include <stdio.h>
#include <limits.h>

void max_min(int arr[], int low, int high, int *max, int *min) {
    if (low == high) {
        *max = *min = arr[low];
        return;
    }

    if (high - low == 1) {
        *max = (arr[low] > arr[high]) ? arr[low] : arr[high];
        *min = (arr[low] < arr[high]) ? arr[low] : arr[high];
        return;
    }

    int mid = (low + high) / 2;
    int max1, min1, max2, min2;

    max_min(arr, low, mid, &max1, &min1);
    max_min(arr, mid + 1, high, &max2, &min2);

    *max = (max1 > max2) ? max1 : max2;
    *min = (min1 < min2) ? min1 : min2;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    max_min(arr, 0, n - 1, &max, &min);

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}
