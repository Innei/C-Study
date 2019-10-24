#include <stdio.h>

int main(int argc, char const *argv[])
{
    //统计n以内的素数
    int n;
    scanf("%d", &n);
    printf("2\n");
    for (int i = 3; i <= n; i += 2)
    {
        int k;
        for (k = 3; k < i; k += 2)
        {
            if (i % k == 0)
            {
                break;
            }
            if (k * k > i)
            {
                break;
            }
        }
        if (k * k > i)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
