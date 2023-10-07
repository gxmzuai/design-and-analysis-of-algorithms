# 使用itertools库中的permutations函数生成0到4的所有可能排列
import itertools

n = 5  # 设置n为5，表示有5个点（城市）
print(list(itertools.permutations(range(n))))  # 生成并列出所有可能的排列