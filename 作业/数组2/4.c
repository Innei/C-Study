//4、	输入2个正整数m和n（1≤m≤6，1≤n≤6），然后输入矩阵a（m行n列）中的元素，计算和输出所有元素的平均值，再统计和输出大于平均值的元素的个数。
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int static a[6][6];
    int n = 0, m, i, j, s = 0, count = 0;
    float avg;
    while (scanf("%d%d", &m, &n), n <= 0 || n > 6)
        ;
    for (i = 0; i < m; i++)
    {

        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            s = s + a[i][j];
        }
    }
    avg = (float)s / (m * n);
    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {

            if (a[i][j] > avg)
            {
                count++;
            }
        }
    }
    printf("avg = %f,count = %d", avg, count);
    return 0;
}