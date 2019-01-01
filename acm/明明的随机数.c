#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int n = 0, t, count = 0, s = 1;
    int *p = NULL;
    scanf("%d", &n);
    p = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {

            if (*(p + i) > *(p + j))
            {
                t = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = t;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (*(p + i - 1) != *(p + i) && i > 0)
        {
            s++;
        }
    }

    printf("%d\n", s);
    for (int i = 0; i < n; i++)
    {

        if (*(p + i) != *(p + i + 1))
        {
            count++;

            printf("%d ", *(p + i));
            continue;
        }
        printf("%d ", *(p + i));
        count++;
        if (*(p + i) == *(p + i + 1))
        {

            for (int j = i + 1; j < n; j++)
            {
                if (*(p + j) == *(p + j - 1))
                    i++;
                else
                    break;
            }

            continue;
        }
    }

    return 0;
}
