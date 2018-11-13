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
    int n, n1, n2, count = 0;

    for (n = 6; n <= 100; n += 2)
    {

        for (n1 = 3; n1 <= n / 2; n1 += 2)
        {
            n2 = n - n1;

            if (prime(n1) && prime(n2))
            {
                count++;
                printf("%4d=%2d+%2d", n, n1, n2);

                if (count % 5 == 0)
                {
                    printf("\n");
                }
            }
        }
    }
    printf("\n");
    return 0;
}
