//1、	输入一个正整数n（1<n≤6），再读入n阶矩阵a，计算该矩阵除副对角线、最后一列和最后一行以外的所有元素之和（副对角线为从矩阵的右上角至左下角的连线）。
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int static a[6][6];
    int n = 0, i, j, s = 0;
    while (scanf("%d", &n), n <= 0 || n > 6)
        ;

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            // printf("%d\n", a[i][j]);

            if (j != n - 1 && i != n - 1)
            {
                s = s + a[i][j];

                if ((i == 1 && j == n - 2) || (i == 2 && j == n - 3) || (i == 3 && j == n - 4) || (i == 4 && j == n - 5))
                {
                    s = s - a[i][j];
                }
            }
        }
    }
    printf("%d\n", s);
    return 0;
}
