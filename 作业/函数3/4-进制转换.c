#include <stdio.h>
void dectobin(int n)
{

    if (n <= 0)
    {
        return;
    }

    dectobin(n / 2);
    if (n % 2 == 0)
    {
        printf("0");
        return;
    }
    else if (n % 2 == 1)
    {
        printf("1");
        return;
    }
}
int main(int argc, char const *argv[])
{
    int n = 20;
    dectobin(n);
    return 0;
}
