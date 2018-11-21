//1、	输入一个正整数n（1<n≤10），再输入n个整数，按与输入相反的顺序输出这些整数。

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[10];
    int n;
    while (scanf("%d", &n), n < 1 || n > 10)
        ;
        
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        
        for(int i = n-1; i >=0; i--)
        {
            printf("%d\t", a[i]);
        }

        return 0;
}
