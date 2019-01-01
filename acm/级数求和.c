#include <stdio.h>

int main(int argc, char const *argv[])
{
    int k = 0;
    int n = 0;
    double sn = 0.0;
A:
    scanf("%d", &k);
    if (k < 16)
    {

        for (n = 1; n < 1835422; n++)
        {
            sn = sn + 1.0 / n;
            //printf("%.8lf\n", sn);
            if (sn > k)
            {
                printf("%d\n", n);
                break;
            }
        }
    }
    else
    {
        printf("error.\n");
        goto A;
    }

    return 0;
}
