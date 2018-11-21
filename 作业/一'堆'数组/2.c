//2、	输入一个正整数n（1<n≤10），再输入n个整数，输出最大值及其下标（设最大值唯一，下标从0开始）。
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[10];
    int n, max;
    while (scanf("%d", &n), n < 1 || n > 10)
        ;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    max = a[0];

    for (int i = 0; i < n; i++)
    {

        if (max < a[i])
        {
            max = a[i];
        }
    }

    for (int i = 0; i < n; i++)
    {

        if (max == a[i])
        {
            printf("a[%d]max = %d\n", i, max);
        }
    }

    return 0;
}
