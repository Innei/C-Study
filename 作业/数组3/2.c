#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    char a[80];
    int len;
    int count = 0,c = 0;
    gets(a);
    len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        if (isupper(a[i]))
        {
            c++;
            if (a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')
                count++;
        }
    }
    printf("%d", c - count);
    return 0;
}
