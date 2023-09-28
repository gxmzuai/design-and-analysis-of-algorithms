#include <stdio.h>

// 插入排序函数
void insertionSort(int arr[], int n) {
    int i, j, key;
    // 从数组的第二个元素开始遍历
    for (i = 1; i < n; i++) {
        // 当前待排序的元素
        key = arr[i];
        // 找到 key 应该插入的位置
        j = i - 1;
        // 将比 key 大的元素向后移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // 将 key 插入到正确的位置
        arr[j + 1] = key;
    }
}

// 打印数组函数
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // 初始化一个待排序的数组
    int arr[] = {12, 11, 13, 5, 6};
    // 计算数组长度
    int n = sizeof(arr) / sizeof(arr[0]);

    // 打印原始数组
    printf("Original array: \n");
    printArray(arr, n);

    // 进行插入排序
    insertionSort(arr, n);

    // 打印排序后的数组
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
