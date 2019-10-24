#include <stdio.h>

int main()
{
    int a[5][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {4, 5, 6, 5, 4}, {123, 4, 5, 6, 7}};
    int s1 = 0;
    int n = 5;
    int s2 = 0;
    int upsum = 0;
    int downsum = 0;
    for (int i = 0; i < n; i++)
    {
        s1 += a[i][i];
        if (i != n - i - 1)
            s2 += a[i][n - i - 1];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            upsum = upsum + a[i][j];
            downsum = downsum + a[j][i];
        }
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    printf("%d %d %d %d ", s1, s2, upsum, downsum);

    getchar();
    return 0;
}
