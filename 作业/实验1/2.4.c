#include <stdio.h>

int main()
{
    int y, m, d;
    int i;
    int sum = 0;
    int date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("输入年月日：");
    scanf("%d %d %d", &y, &m, &d);
    if (y % 4 == 0)
    {
        date[1] = 29;
    }

    for (i = 0; i < m - 1; i++)
        sum += date[i];
    sum += d;
    printf("它是%d年中的第%d天\n", y, sum);
    return 0;
}
