#include <stdio.h>
#include <math.h>
int factorsum(int x)
{
    int k, sum = 0;

    for (k = 1; k < x / 2; k++)
    {

        if (x % k == 0)
        {
            sum += k;
        }
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    int n, m, temp, c = 0, s = 0, k;
    while (printf("Input m,n:\n"), scanf("%d%d", &m, &n), m <= 0 || n <= 0)
        ;

    if (m > n)
    {
        temp = m;
        m = n;
        n = temp;
    }

    for (k = m; k <= n; k++)
    {

        if (k == factorsum(k))
        {
            c++;
            s += k;
            printf("%d\n", k);
        }
    }
    printf("count = %d,sum = %d", c, s);
    return 0;
}
