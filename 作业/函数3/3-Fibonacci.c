#include <stdio.h>

double fib(int n)
{

    double fi = 1, fi1 = 1, s = 0;

    if (n == 1)
        return 1;

    for (int i = 3; i <= n; i++)
    {
        s = fi + fi1;
        fi = fi1;
        fi1 = s;
    }
    return s;
}
int main(int argc, char const *argv[])
{
    int m, n, t, k = 1;
    while (printf("Input m,n:"), scanf("%d%d", &m, &n), m <= 0 || n <= 0)
        ;

    if (m > n)
    {
        t = m, m = n, n = t;
    }

    while (fib(k) < m)
    {
        k++;
    }

    while (fib(k) <= n)
    {
        printf("%.0f ", fib(k));
        k++;
    }
    printf("\n");
    return 0;
}
