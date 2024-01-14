#include <stdio.h>
#include <string.h>

// 动态规划求解最长公共子序列问题
int lcs(char *A, char *B) {
    int m = strlen(A);
    int n = strlen(B);
    int dp[m+1][n+1];
    int i, j;

    // 初始化边界条件
    for (i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    // 填充 dp 表
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    char A[] = "ABCBDAB";
    char B[] = "BDCABC";

    printf("Length of LCS is %d\n", lcs(A, B));
    return 0;
}
