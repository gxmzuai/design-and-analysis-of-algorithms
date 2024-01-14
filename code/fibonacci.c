#include <stdio.h>

long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("请输入要计算的斐波那契数列项数：");
    scanf("%d", &n);

    long long result = fibonacci(n);
    printf("斐波那契数列的第%d项是：%lld\n", n, result);

    return 0;
}
