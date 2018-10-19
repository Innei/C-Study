#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0;
    long int res = 0;
    int i = 0;
    printf("Enter a num :\n");
    scanf("%d", &a);

    for (i = 1; i <= a; i++)
    {
        res = res + i * i;
    }
    printf("res : %ld\n", res);
    printf("下面用while实现\n");
    res = 0;
    i = 0;
    while (i <= a)
    {
        res = res + i * i;
        i++;
    }
    printf("res : %ld\n", res);
    res = 0;
    i = 0;
    printf("下面用do while实现\n");
    do
    {
        res = res + i * i;
        i++;
        
    } while (i <= a);
    printf("res : %ld\n", res);
    return 0;
}
