#include <stdio.h>

int main()
{
    int n = 9;
    int a[17][17] = {0};
    int t = n;
    int j;
    for (int i = 0; i < n; i++)
    {
        for (j = i; j < 2 * n - 1 - i; j++)
        {
            a[i][j] = t;
            a[j][i] = t;
            a[2 * n - 2 - i][j] = t;
            a[j][2 * n - 2 - i] = t;
        }
        t--;
    }
    for (int i = 0; i < 17; i++)
    {
        for (j = 0; j < 17; j++)
            printf("%d  ", a[i][j]);
        printf("\n");
    }
    return 0;
}
