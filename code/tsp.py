# 导入必要的库
import itertools  # 用于生成排列组合
import math  # 用于数学运算

# 定义计算两点之间距离的函数
def distance(point1, point2):
    return math.sqrt((point1[0] - point2[0])**2 + (point1[1] - point2[1])**2)

# 定义暴力解决货郎问题的函数
def tsp_bruteforce(points):
    n = len(points)  # 获取点（城市）的数量
    min_distance = float('inf')  # 初始化最短距离为无穷大
    best_path = None  # 初始化最佳路径为 None

    # 遍历所有可能的路径（排列）
    for path in itertools.permutations(range(n)):
        current_distance = 0  # 初始化当前路径的距离为 0

        # 计算当前路径的总距离
        for i in range(n - 1):
            current_distance += distance(points[path[i]], points[path[i + 1]])

        # 加上返回到起始点的距离
        current_distance += distance(points[path[-1]], points[path[0]])

        # 更新最短距离和最佳路径
        if current_distance < min_distance:
            min_distance = current_distance
            best_path = path

    return best_path, min_distance

# 定义一些点（x, y）来表示城市
points = [(0, 0), (1, 2), (2, 4), (3, 1), (4, 3)]

# 调用函数并获取结果
best_path, min_distance = tsp_bruteforce(points)
print(best_path, min_distance)
