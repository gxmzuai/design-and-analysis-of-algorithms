#include <stdio.h>

// 确保您的maxmin函数使用指针来替换原有的引用参数
void maxmin(int A[], int *max, int *min, int low, int high) {
    int mid, x1, y1, x2, y2;
    if ((high - low) <= 1) {
        if (A[high] >= A[low]) {
            *max = A[high];
            *min = A[low];
        } else {
            *max = A[low];
            *min = A[high];
        }
    } else {
        mid = (low + high) / 2;
        maxmin(A, &x1, &y1, low, mid);
        maxmin(A, &x2, &y2, mid + 1, high);
        if (x1 > x2) {
            *max = x1;
        } else {
            *max = x2;
        }
        if (y1 < y2) {
            *min = y1;
        } else {
            *min = y2;
        }
    }
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 7};
    int max, min;
    int size = sizeof(arr) / sizeof(arr[0]);

    maxmin(arr, &max, &min, 0, size - 1);

    printf("最大值: %d\n", max);
    printf("最小值: %d\n", min);

    return 0;
}


