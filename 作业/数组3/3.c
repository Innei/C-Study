#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    static char a[80];
    int len = 0;
    gets(a);
    len = strlen(a);
    for (int i = 0; i < len;i++)
    {
        if(isupper(a[i]))
        {
            a[i] = 'Z' - a[i] + 'A';
        }
    }
    printf("%s", a);
    return 0;
}

