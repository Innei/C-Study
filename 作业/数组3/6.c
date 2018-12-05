#include <stdio.h>
int main(int argc, char const *argv[])
{
    char c;
    int i = 0, a[100] = {0};
    while ((c = getchar()) != '\n')

        for (i = 65; i <= 90; i++)
        {

            if (c == i || c == i + 32)
            {
                a[i]++;
            }
        }

    for (i = 65; i <= 90; i++)
    {
        printf("%c:%d\n", i, a[i]);
    }

    return 0;
}
