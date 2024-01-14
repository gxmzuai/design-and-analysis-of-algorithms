#include <stdio.h>

// 实现 findMax 函数
int findMax(int arr[], int left, int right) {
    // 如果数组只有一个元素，直接返回该元素
    if (left == right) {
        return arr[left];
    } else {
        // 找到中间位置
        int mid = left + (right - left) / 2;

        // 递归地在左半部分和右半部分分别寻找最大值
        int maxLeft = findMax(arr, left, mid);
        int maxRight = findMax(arr, mid + 1, right);

        // 返回两部分中的较大值
        return (maxLeft > maxRight) ? maxLeft : maxRight;
    }
}

int main() {
    int arr[] = {8, 3, 5, 7, 6, 2, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max = findMax(arr, 0, n - 1);
    printf("最大元素是：%d\n", max);

    return 0;
}


