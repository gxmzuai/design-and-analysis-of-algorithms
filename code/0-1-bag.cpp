#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];
// int res = 0;

// int mem[N][N];

// 记忆化搜索
// dfs函数，x是当前考虑的物品编号，spV是背包剩余的容量
// int dfs(int x, int spV){
//     // 如果这个状态已经计算过（即mem[x][spV]不为0），则直接返回之前计算的结果
//     if(mem[x][spV])
//         return mem[x][spV];

//     // 初始化当前状态的价值为0
//     int sum = 0;

//     // 如果所有的物品都已经考虑过（即x > n），则这个状态的价值为0
//     if(x > n){
//         sum = 0;
//     }
//     // 如果当前物品的体积大于背包剩余的容量，那么就不能选择这个物品，只能考虑下一个物品
//     else if(spV < v[x]){
//         sum = dfs(x + 1, spV);
//     }
//     // 如果当前物品的体积小于等于背包剩余的容量，那么可以选择这个物品，也可以不选择
//     // 所以需要比较两种情况的价值，取最大值
//     else if(spV >= v[x]){
//         sum = max(dfs(x + 1, spV), dfs(x + 1, spV - v[x]) + w[x]);
//     }

//     // 记录这个状态的价值，以便以后直接使用
//     mem[x][spV] = sum;

//     // 返回这个状态的价值
//     return sum;
// }
// void dfs(int x, int sumV, int sumW) {
//     if(x > n) {
//         if(sumV <= m && sumW >= res) {
//             res = sumW;
//         }
//         return ;
//     }
    
    //不选
    // dfs(x + 1, sumV, sumW);
    
    //选
//     if(sumV + v[x] <= m)
//         dfs(x + 1, sumV + v[x], sumW + w[x]);
// }

int main() {
    // 读取物品的数量和背包的容量
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++) {
        // 读取第i件物品的体积和价值
        scanf("%d %d", &v[i], &w[i]);
    }

    // int res = dfs(1, m);
    // printf("%d\n", res);
    
    // dfs(1, 0, 0);
    // printf("%d\n", res);

    // 
    for (int i = n; i >= 1;i--){
        for (int j = 0; j <= m;j++){
            if(j >= v[i])
                f[i][j] = max(f[i + 1][j], f[i + 1][j - v[i]] + w[i]);
            else
                f[i][j] = f[i + 1][j];
        }
    }
    printf("%d\n", f[1][m]);
    return 0;
}