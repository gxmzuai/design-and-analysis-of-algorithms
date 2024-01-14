#include <stdio.h>

// 实现 findSecondMax 函数
int findSecondMax(int arr[], int left, int right, int *secondMax) {
    if (left == right) {
        return arr[left];
    } else {
        int mid = left + (right - left) / 2;
        int secondMaxLeft = -1, secondMaxRight = -1;

        int maxLeft = findSecondMax(arr, left, mid, &secondMaxLeft);
        int maxRight = findSecondMax(arr, mid + 1, right, &secondMaxRight);

        // 比较左右两边的最大值和次大值
        if (maxLeft > maxRight) {
            *secondMax = (secondMaxLeft > maxRight) ? secondMaxLeft : maxRight;
            return maxLeft;
        } else {
            *secondMax = (secondMaxRight > maxLeft) ? secondMaxRight : maxLeft;
            return maxRight;
        }
    }
}

int main() {
    int arr[] = {8, 3, 5, 7, 6, 2, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int secondMax = -1; // 假设所有元素都是非负数

    int max = findSecondMax(arr, 0, n - 1, &secondMax);
    printf("最大元素是：%d\n", max);
    printf("第二大元素是：%d\n", secondMax);

    return 0;
}


