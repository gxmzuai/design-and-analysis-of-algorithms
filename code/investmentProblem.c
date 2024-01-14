#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int f[4][6] = {
        {0, 11, 12, 13, 14, 15},
        {0,  0,  5, 10, 15, 20},
        {0,  2, 10, 30, 32, 40},
        {0, 20, 21, 22, 23, 24}
    };

    int dp[5][6] = {0}; // 初始化dp数组

    // 第一个循环（1）：遍历所有的项目。
    // 第二个循环（j）：遍历所有的投资额。
    // 第三个循环（k）：这个循环是关键，它遍历每个项目可能的投资金额。
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j <= 5; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + f[i - 1][k]);
            }
        }
    }

    printf("最大收益: %d\n", dp[4][5]);
    return 0;
}
