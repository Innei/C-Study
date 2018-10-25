#include <stdio.h>

int main(int argc, char const *argv[])
{

    double sum = 1;
    double sig = 1;
    int n = 0;
A:
    printf("enter a num : \n");

    scanf("%d", &n);
    if (n <= 0)
    {
        printf("error\n");
        goto A;
    }
    for (int i = 1; i <= n; i++)
    {
        sig = i * sig;
        sum = sum + 1.0 / sig;
    }
    printf("%.4lf\n", sum);
    return 0;
}
