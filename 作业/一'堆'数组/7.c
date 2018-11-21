#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, t = 0,count=0;
    static int a[100];
    scanf("%d", &n);

    for (int i = 0; n > 0; i++, n = n / 2)
    {
        a[i] = n % 2;
        count++;
    }

    for(int i = 0; i < count; i++)
    {
        printf("%d", a[i]);
    }
    putchar('\n');
    return 0;
}
