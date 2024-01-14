#include <stdio.h>

// 函数来计算最大值
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 0/1背包问题的实现
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int dp[n + 1][W + 1];

    // 构建表格dp[][]
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;//边界条件
            } else if (wt[i - 1] <= w) { //装得下，装或者不装，两者取最大值
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else { //装不下
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int val[] = {2, 5, 8, 1}; // 物品的收益
    int wt[] = {10, 15, 6, 9}; // 物品的重量
    int W = 32; // 背包的最大载重
    int n = sizeof(val) / sizeof(val[0]); // 物品的数量
    printf("最大收益是 %d\n", knapsack(W, wt, val, n));
    return 0;
}

