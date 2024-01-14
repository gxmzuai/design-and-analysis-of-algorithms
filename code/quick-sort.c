#include <stdio.h>

int l[10]; // 全局数组
int n = 7; // 数组中元素的个数

// 交换函数
void Swap(int i, int j)
{
    int temp = l[i];
    l[i] = l[j];
    l[j] = temp;
}

// 划分函数
// int Partition(int left, int right)
// {
//     int pivot = l[right]; // 选择最右侧的元素作为基准
//     int i = left - 1;
//     for (int j = left; j <= right - 1; j++)
//     {
//         if (l[j] < pivot)
//         {
//             i++;
//             Swap(i, j);
//         }
//     }
//     Swap(i + 1, right);
//     return i + 1;
// }

int Partition(int left, int right)
{
    int pivot = l[left]; // 选择最左侧的元素作为基准
    int i = left;        // 从left开始，而不是left-1

    for (int j = left + 1; j <= right; j++)
    {
        if (l[j] < pivot)
        {
            i++;
            Swap(i, j);
        }
    }
    Swap(i, left);      // 将pivot放到它的最终位置
    return i;           // 返回pivot的位置
}


// 快速排序（重载函数）
void QuickSort(int left, int right)
{
    if (left < right)
    {
        int pi = Partition(left, right);
        QuickSort(left, pi - 1);
        QuickSort(pi + 1, right);
    }
}

// 主函数
int main()
{
    // 初始化数组
    int temp[] = { 4, 2, 5, 1, 7, 6, 1 };
    for(int i = 0; i < n; i++)
    {
        l[i] = temp[i];
    }

    // 打印未排序的数组
    for(int i = 0; i < n; i++)
    {
        printf("%d ", l[i]);
    }
    printf("\n");

    // 进行快速排序
    QuickSort(0,n-1);

    // 打印排序后的数组
    for(int i = 0; i < n; i++)
    {
        printf("%d ", l[i]);
    }
    printf("\n");

    return 0;
}
