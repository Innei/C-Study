//4、	输入一个正整数n（1<n≤10），再输入n个整数，将它们从大到小排序后输出。
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[10];
    int n, temp;
    while (scanf("%d", &n), n < 1 || n > 10)
        ;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) //循环输出排序以后的结果
    {
        printf("%d  ", a[i]);
    }

    return 0;
}
