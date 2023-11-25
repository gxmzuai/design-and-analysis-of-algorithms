#include <stdio.h>
#include <string.h>

#define N 4 // 定义棋盘大小及皇后数量

int attack[N][N]; // 记录攻击位置的数组
char queen[N][N]; // 记录皇后位置的数组

// 打印解决方案
void printSolution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c ", queen[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 设置或清除攻击标记
void setAttack(int row, int col, int value)
{
    for (int i = 0; i < N; i++)
    {
        attack[row][i] = value;
        attack[i][col] = value;
        if (row + i < N && col + i < N)
            attack[row + i][col + i] = value;
        if (row - i >= 0 && col - i >= 0)
            attack[row - i][col - i] = value;
        if (row + i < N && col - i >= 0)
            attack[row + i][col - i] = value;
        if (row - i >= 0 && col + i < N)
            attack[row - i][col + i] = value;
    }
    attack[row][col] = !value; // Reset the position of the queen
}

// 递归函数来解决N-皇后问题
int solveNQUtil(int row)
{
    if (row == N)
    {
        printSolution();
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        if (!attack[row][i])
        {
            setAttack(row, i, 1);
            queen[row][i] = 'Q';

            if (solveNQUtil(row + 1))
                return 1;
                // 回溯
                setAttack(row,i, 0);
            queen[row][i] = '.';
        }
    }

    return 0;
}

// 初始化棋盘并解决N-皇后问题
int solveNQ()
{
    memset(attack, 0, sizeof(attack));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            queen[i][j] = '.';
        }
    }

    if (!solveNQUtil(0))
    {
        printf("没有解决方案\n");
        return 0;
    }
    return 1;
}

int main()
{
    solveNQ();
    return 0;
}
