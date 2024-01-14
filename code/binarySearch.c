#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid; // 找到目标，返回索引
        else if (arr[mid] < target)
            low = mid + 1; // 在右半部分继续查找
        else
            high = mid - 1; // 在左半部分继续查找
    }

    return -1; // 没有找到目标，返回-1
}

int main() {
    int arr[] = {1, 3, 9, 12, 32, 41, 45, 62, 75, 77, 82, 95, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 82;
    int result = binarySearch(arr, size, target);

    if (result != -1)
        printf("书籍的位置在索引: %d\n", result);
    else
        printf("在数组中未找到该书籍。\n");

    return 0;
}
