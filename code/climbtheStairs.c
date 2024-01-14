#include <stdio.h>

int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }

    int dp[11]; // 因为台阶数量不超过10，我们可以直接定义一个大小为11的数组
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    printf("Enter the number of stairs (up to 10): ");
    scanf("%d", &n);

    if (n > 0 && n <= 10) {
        printf("Number of ways to climb %d stairs: %d\n", n, climbStairs(n));
    } else {
        printf("Invalid number of stairs. Please enter a number from 1 to 10.\n");
    }
    
    return 0;
}
