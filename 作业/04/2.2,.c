#include <stdio.h>

int main(int argc, char const *argv[])
{
A:
    int n = 0;
    double sum = 1.0;
    double sig = 1.0;
    printf("enter a num : \n");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("error\n");
        goto A;
    }
    for (int i = 0; i < n; i++)
    {
        sig = 1.0;
        for (int k = 1; k <= i; k++)
        {
            sig = sig * k;
        }
        sum = sum + 1.0 / sig;
    }
    printf("e = %.4lf\n", sum);
    return 0;
}
