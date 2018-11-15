#include <stdio.h>
void inverse(int n)
{
    if (n == 0)
    {
        return;
    }
    if (n < 0)
    {
        n = -n;
        printf("-");
    }
    printf("%d", n % 10);
    inverse(n / 10);
}
int main(int argc, char const *argv[])
{
    inverse(-10);
    return 0;
}
