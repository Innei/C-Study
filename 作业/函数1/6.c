#include <stdio.h>

double fact(int n)
{
    int i;
    double p = 1;
    
    for( i = 1; i <=n; i++)
    {
        p *= i;
    }
    return p;
}
double cal(int k, int n)
{
    double res;
    res = fact(n) / (fact(n - k) * fact(k));
    return res;
}
int main(int argc, char const *argv[])
{
    int k, n;
A:
    printf("输入n:\n");
    scanf("%d", &n);
    if (n < 0)
    {
        goto A;
    }
    
    for( k = 1; k <= n; k++)
    {
        printf("cal(%d,%d) = %.0f\n", k, n, cal(k, n));
    }

    return 0;
}
