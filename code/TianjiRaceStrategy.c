#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于qsort排序
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// 计算田忌可以赢得的最多银币数
int max_silver_earned(int n, int tianji_speeds[], int king_speeds[]) {
    int silver = 0;  // 用于记录田忌赢得的银币数量
    int tianji_fastest = n - 1, tianji_slowest = 0;  // 田忌马匹的快慢指针
    int king_fastest = n - 1, king_slowest = 0;     // 齐威王马匹的快慢指针

    // 将田忌和齐威王的马的速度值升序排序
    qsort(tianji_speeds, n, sizeof(int), compare);
    qsort(king_speeds, n, sizeof(int), compare);

    // 循环比较田忌和齐威王的马
    while (tianji_slowest <= tianji_fastest) {
        // 如果田忌最快的马比齐威王最快的马快
        if (tianji_speeds[tianji_fastest] > king_speeds[king_fastest]) {
            silver += 200;  // 田忌赢得200银币
            tianji_fastest--;
            king_fastest--;
        }
        // 如果田忌最慢的马能赢过齐威王最慢的马
        else if (tianji_speeds[tianji_slowest] > king_speeds[king_slowest]) {
            silver += 200;  // 田忌赢得200银币
            tianji_slowest++;
            king_slowest++;
        }
        // 如果田忌的马慢于齐威王的马，田忌输掉200银币
        else if (tianji_speeds[tianji_slowest] < king_speeds[king_fastest]) {
            silver -= 200;  // 田忌输掉200银币
            tianji_slowest++;
            king_fastest--;
        }
        // 如果速度相等，平局，银币数不变
        else {
            tianji_slowest++;
            king_fastest--;
        }
    }
    return silver;  // 返回田忌赢得的总银币数
}

int main() {
    int n;
    while (1) {
        printf("请输入马的数量（输入0结束）: ");
        scanf("%d", &n);
        if (n == 0) break;

        int tianji_speeds[n], king_speeds[n];  // 存储田忌和齐威王的马的速度
        printf("请输入田忌的马的速度: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &tianji_speeds[i]);
        }

        printf("请输入齐威王的马的速度: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &king_speeds[i]);
        }

        int silver = max_silver_earned(n, tianji_speeds, king_speeds);
        printf("田忌可以赢得的最多银币数: %d\n", silver);
    }
    return 0;
}
