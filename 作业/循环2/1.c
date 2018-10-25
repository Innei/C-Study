#include <stdio.h>

int main(int argc, char const *argv[])
{
    int sum = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (i % 7 == 0)
        {
            sum = sum + i;
            // printf("i = %d", i);
        }
    }
    printf("sum = %d\n", sum);
    return 0;
}
