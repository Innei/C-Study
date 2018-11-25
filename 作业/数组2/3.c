//3、	输入一个正整数n（1≤n≤6）,再输入一个n行n列的矩阵，统计并输出该矩阵中非零元素的数量
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int static a[6][6];
    int n = 0, i, j, s = 0, count = 0;
    while (scanf("%d", &n), n <= 0 || n > 6)
        ;

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);

            if (!a[i][j])
            {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}