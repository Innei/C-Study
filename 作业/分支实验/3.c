#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0, b = 0, c = 0;

    while (1)
    {
        printf("Enter a, b, c:\n");
        scanf("%d %d %d", &a, &b, &c);
        if (a + b > c && b + c > a && a + c > b)
        {
            if (a == b || b == c || c == a)
                printf("等腰三角形\n");
            else if (a == b == c)
                printf("等边三角形\n");
            else if (a * a + b * b == c * c || b * b + c * c == a * a || a * a + c * c == b * b)
                printf("RT三角形\n");
            else
                printf("一般三角形\n");
        }
        else
            printf("Error.\n");
    }
    return 0;
}
