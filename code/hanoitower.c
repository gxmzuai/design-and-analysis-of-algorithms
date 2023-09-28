#include <stdio.h>

// 汉诺塔递归函数
void hanoi(int n, char A, char B, char C) {
    // 当只有一个盘子时，直接从 A 移动到 C
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", A, C);
        return;
    }
    // 先将 n-1 个盘子从 A 移动到 B，以 C 作为中间塔
    hanoi(n-1, A, C, B);
    // 移动第 n 个盘子从 A 到 C
    printf("Move disk %d from %c to %c\n", n, A, C);
    // 最后将 n-1 个盘子从 B 移动到 C，以 A 作为中间塔
    hanoi(n-1, B, A, C);
}

int main() {
    // 初始化盘子数量为 3
    int n = 3;
    // 输出汉诺塔移动步骤
    printf("Hanoi Tower moves:\n");
    // 调用 hanoi 函数进行汉诺塔问题求解
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
