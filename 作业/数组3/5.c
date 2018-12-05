#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    static char a[80];
    static char b[80];
    scanf("%s", a);
    int len = strlen(a);
    int s = 0;
    for(int i = 0; i < len; i++)
    {
        
        if (islower(a[i])) {
            b[s] = a[i];
            s++;
        }
        
    }
    printf("%s",b);
    return 0;
}


