/*
1、	按下列要求编写程序：
① 定义函数f(n)计算n×(n+1) ×…×(2n-1)，函数返回值类型是double。
② 定义函数main()，输入正整数n，计算并输出下列算式的值。要求调用函数f(n)计算n×(n+1) ×…×(2n-1)。
*/

#include <stdio.h>

double f(int n)
{
    double res = 1;
    for (int i = n; i <= 2 * n - 1; i++)
    {
        res = res * i;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    double s = 0;
    int n;
    printf("请输入一个整数 n :\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        s = s + 1 / f(i);
    }
    printf("s = %lf", s);
    return 0;
}
