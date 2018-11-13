// 输入2个正整数m和n，统计并输出m和n之间的素数的个数以及这些素数的和。素数就是只能被1和自身整除的正整数，最小的素数是2。要求定义并调用函数prime(m)判断m是否为素数，当m为素数时返回1，否则返回0。
#include <stdio.h>
#include <math.h>
int prime(int n)
{

    if (n < 2)
        return 0;

    for (int i = 2; i <= (int)sqrt((double)n); i++)
    {

        if (n % i == 0)
            return 0;
    }

    return 1;
}
int main(int argc, char const *argv[])
{
    int m, n;
    long s = 0, num = 0;
    printf("输入两个整数m,n(m<n):\n");
    scanf("%d%d", &m, &n);

    for (int i = m; i <= n; i++)
    {

        if (prime(i))
        {
            s = s + i;
            num++;
          
        }
    }
    printf("素数的个数%ld,总和%ld", num, s);
    return 0;
}
