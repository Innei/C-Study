#include <stdio.h>
double s = 1;
double cal_power(float x, int n) // 递归计算幂函数原型
{

    if (n == 1)
        return x;

    s = x * cal_power(x, n - 1);

    return s;
}

double cal_money(int loan, double rate, int month)
{
   
    return (loan * rate * cal_power(1 + rate, month) / (cal_power(1 + rate, month) - 1));
}

int main(int argc, char const *argv[])
{
    double  rate;
    int loan,year = 5;
   // printf("%f", cal_power(3, 3));
    printf("Enter loan, rate:\n");
    scanf("%d%lf", &loan, &rate);
    printf("year\tmoney\n");
    
    for (; year <= 30; year++)
    {
        printf("%5d %5.0lf\n", year, cal_money(loan, rate, year * 12));
    }

    return 0;
}
