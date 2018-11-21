//3、	输入一个正整数n（1<n≤10），再输入n个整数，将最小值与第一个数交换，最大值与最后一个数交换，然后输出交换后的n个数（设最大值和最小值都是唯一的，且数组下标从0开始）。
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[10];
    int n, max, min, t;
    while (scanf("%d", &n), n < 1 || n > 10)
        ;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    min = a[0];
    max = a[0];

    for (int i = 0; i < n; i++)
    {

        if (min > a[i])
        {
            min = a[i];
        }

        if (max < a[i])
        {
            max = a[i];
        }
    }
    t = max;
    max = a[n - 1];
    a[n - 1] = t;

    t = min;
    min = a[0];
    a[0] = t;

    for (int i = 0; i < n; i++)
    {
        printf("%5d", a[i]);
    }

    return 0;
}
