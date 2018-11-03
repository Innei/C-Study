
#include <stdio.h>
#include <math.h>
int fat(int a, int n)
{
    int i, sum = 0,  b, c;
    for (i = 0; i < n; i++)
    {
        b = pow(10, i);
        c = a * b;
        c = sum + c;
        sum = sum + c;
    }
    return sum;
}
int main(void)
{
    int a, n;
    printf("input");
    scanf("%d%d", &a, &n);
    printf("%d", fat(a, n));
    return 0;
}