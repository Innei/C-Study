#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char a[80] = "";
    char b = '\0';
    int len = 0, s = -1;
    scanf("%c", &b);
    scanf("%s", a);
    len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        if (a[i] == b)
            s = i;
    }
    if (s == -1)
        printf("Not Found.\n");
    else
        printf("%d", s + 1);
    return 0;
}
