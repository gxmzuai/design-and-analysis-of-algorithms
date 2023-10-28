#include <algorithm>
#include <iomanip>
#include <iostream>
#define N 20
using namespace std;

int choices[N][N] = {0}; // 记录物品是否被选中的数组

// 0-1背包问题的实现
// 动态规划的背包问题和0/1背包问题是同一个问题，只是在不同的场景下有不同的叫法。
// 0/1背包问题是指每个物品只能选择放或不放，即每个物品的选择状态是0或1。
// 而背包问题是一个更广泛的概念，可以包括每个物品可以选择放入任意个数的情况。
// 在实际应用中，0/1背包问题是最常见的背包问题，因此动态规划的背包问题通常也指0/1背包问题。

/*
v：物品种类数量
w[]: 重量数组
p[]：价值数组
c：背包总容量
*/

// 动态规划解决背包问题的辅助函数
void PackageHelper(int v, int w[], int p[], int c) {
  // dp[i][j] 表示前i个物品，对于背包容量j能获得的最大价值
  int dp[N][N] = {0}; // DP数组，记录每个状态下的最大价值

  // 动态规划过程
  for (int i = 1; i <= v; i++) {
    for (int j = 1; j <= c; j++) {
      // 若当前物品的重量小于或等于当前背包容量，则可以考虑放入
      if (w[i] <= j) {
        int value1 = dp[i - 1][j];
        int value2 = dp[i - 1][j - w[i]] + p[i];
        // 根据选择物品i与否，更新DP数组
        if (value2 > value1) {
          dp[i][j] = value2;
          choices[i][j] = 1; // 选择物品i
        } else {
          dp[i][j] = value1;
        }
      } else {
        // 若当前物品重量大于背包容量，则不能放入
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // 输出DP数组
  cout << "DP Array: " << endl;
  for (int i = 0; i <= v; i++) {
    for (int j = 0; j <= c; j++) {
      cout << setw(5) << dp[i][j] << " ";
    }
    cout << endl;
  }

  // 输出最大价值
  cout << "Max Value: " << dp[v][c] << endl;
}

// 回溯选择的物品
void trace(int v, int w[], int p[], int c) {
  cout << "Selected items:" << endl;
  int j = c;
  for (int i = v; i > 0; i--) {
    if (choices[i][j]) {
      cout << "Select item " << i << " with weight " << w[i] << ", value "
           << p[i] << "." << endl;
      j -= w[i];
    }
  }
}

int main() {
  // 定义物品的重量和价值
  // 在这个例子中，为了与物品编号对应（从1开始），在数组的开始处加入一个0元素。
  int w[] = {0, 2, 3, 4, 7}; // 物品的重量数组
  int p[] = {0, 1, 3, 5, 9}; // 物品的价值数组

  PackageHelper(4, w, p, 10); // 调用函数，求解背包问题

  trace(4, w, p, 10); // 回溯输出选择的物品

  return 0;
}
