#include <stdio.h>

double fun(float x)
{
    double res = 0;
    res = x * x - 6.5 * x + 2;
    return res;
}
int main(int argc, char const *argv[])
{
    printf("  x  \t  y  \n");
    for (float x = -3.0; x <= 3.0; x = x + 0.5)
    {
        printf("%5.2f\t%5.2lf\n", x, fun(x));
    }
    return 0;
}
