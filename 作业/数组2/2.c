//2、	输入一个正整数n（1<n≤6）和n阶矩阵a中的元素,如果a是上三角矩阵，输出“YES”；否则，输出“NO”（上三角矩阵，即主对角线以下的元素都为0，主对角线为从矩阵的左上角至右下角的连线）。
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
        }
    }

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < i; j++)
        {

            if (a[i][j] != 0)
            {
                printf("NO\n");
                break;
            }

            else if (i == n - 1)
            {

                printf("YES\n");
                break;
            }
        }
    }

    return 0;
}
