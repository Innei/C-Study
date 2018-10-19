#include <stdio.h>

int main(int argc, char const *argv[])
{
    long n = 1;
    while (!(n % 5 == 1 && n % 6 == 5 && n % 7 == 4 && n % 11 == 10))
    {
        n++;
    }
    printf("n = %ld\n", n);
    return 0;
}
