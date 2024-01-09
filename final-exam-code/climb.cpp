#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 20;

int n;
int f[N];

// int mem[N];

// dfs暴力
// int dfs(int x){
//     if(x == 1)
//         return 1;
//     if(x == 2)
//         return 2;
//     else
//         return dfs(x - 1) + dfs(x - 2);
// }

// 记忆化搜索
// int dfs(int x){
//     if(mem[x])
//         return mem[x];

//     int sum = 0;
//     if(x == 1)
//         sum = 1;
//     else if(x == 2)
//         sum = 2;
//     else
//         sum = dfs(x - 1) + dfs(x - 2);

//     mem[x] = sum;
//     return sum;
// }

int main(){
    scanf("%d", &n);
    // int res = dfs(n);
    // printf("%d\n",res);
    f[1] = 1, f[2] = 2;
    if( n==1 || n==2)
        printf("%d\n", f[n]);
    else{
        for(int i = 3; i <= n; i++)
            f[i] = f[i - 1] + f[i - 2]; // 这个递推公式也就是dfs的向下递推的公式1:1
        printf("%d\n", f[n]);
    }
    return 0;
}