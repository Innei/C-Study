#include <stdio.h>
int fact(int sum) //递归实现 函数原型
{
    if (sum == 1)
        return 1;
    else
        return sum * fact(sum - 1);
}
int main(int argc, char const *argv[])
{
    double sum = 1;

    int n = 0;

    printf("enter a num : \n");
    scanf("%d", &n);
    sum = fact(n);
    printf("阶乘为%d\n", sum);
    return 0;
}
