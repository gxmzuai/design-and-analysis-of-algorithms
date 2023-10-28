#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

// 动态规划解决投资问题。目标是在有限的资本下获取最大的利润。

// 动态规划函数来计算最大的投资收益。
// 参数:
// m - 总投资金额
// n - 可投资的项目数量
// f - 二维数组，表示每个投资项目对于各个投资金额能获得的收益
// path - 用于跟踪投资决策的二维数组
int maxInvestment(int m, int n, int f[][6], int path[][6]) {
  // dp[i][j]表示在有j单位的投资金额，只考虑前i个投资项目时能获得的最大利润。
  int dp[5][6] = {0};

  // 初始化DP表，当没有投资项目时，收益都为0
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }

  // 使用三层循环来填充DP表。
  // 外层循环遍历所有的投资项目。
  // 中间的循环遍历所有可能的投资金额。
  // 内层循环遍历当前项目内各种投资金额的组合。
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int x = 0; x <= j; x++) {
        if (dp[i][j] < dp[i - 1][j - x] + f[i][x]) {
          dp[i][j] = dp[i - 1][j - x] + f[i][x];
          path[i][j] = x; // 记录投资决策
        }
      }
    }
  }

  // 输出DP表
  cout << "DP Array: " << endl;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      cout << setw(5) << dp[i][j] << " ";
    }
    cout << endl;
  }

  // 返回最大利润
  return dp[n][m];
}

// 回溯函数
void trace(int m, int n, int path[][6]) {
  int w = m;
  for (int i = n; i > 0; i--) {
    cout << "Invest in project " << i << ": " << path[i][w] << " w." << endl;
    w -= path[i][w];
  }
}

int main() {
  // m代表可用于投资的总金额
  int m = 5;
  // n代表可投资的项目数量
  int n = 4;

  // f[i][j]表示第i个投资项目在j单位的投资下能带来的收益。
  int f[5][6] = {{0, 0, 0, 0, 0, 0}, // 占位，使索引从1开始
                 {0, 11, 12, 13, 14, 15},
                 {0, 0, 5, 10, 15, 20},
                 {0, 2, 10, 30, 32, 40},
                 {0, 20, 21, 22, 23, 24}};

  // 初始化为0
  // path[i][j]的含义：当我们考虑前i个项目，并有j单位的投资金额时，我们应该在第i个项目上投资多少金额
  int path[5][6] = {0};

  // 调用动态规划函数
  int result = maxInvestment(m, n, f, path);

  // 输出最大利润
  cout << "Max Profit:" << result << endl;

  // 输出Path数组
  cout << "Path Array: " << endl;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      cout << setw(5) << path[i][j] << " ";
    }
    cout << endl;
  }

  // 输出投资决策
  cout << "Investment decisions:" << endl;
  trace(m, n, path);
  return 0;
}
