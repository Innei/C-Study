#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 0, y = 0;

    for (x = 0; x <= 35; x++)
    {
        y = 35 - x;

        if (2 * x + 4 * y == 94)
        {
            printf("笼中有%d鸡,%d兔\n", x, y);
        }
    }

    return 0;
}
