#include <stdio.h>

double cal_power(int x, int n)
{
    double res = 1;
    for (int i = 0; i < n; i++)
    {
        res = res * x;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    double s = 0;
    int x;
    float n;
    printf("输入浮点数x和正整数n:\n");
    scanf("%d%f", &x, &n);
    for (int i = 1; i <= n; i++)
    {
        s = s + 1 / cal_power(x, i);
    }
    printf("res = %lf", s);
    return 0;
}
