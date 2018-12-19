#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    char str[50] = "\0";
    int c = 0, t = 0, pos = 0;
    int len = 0;
    int s[10] = {0};
    scanf("%[^\n]", str);

    len = strlen(str);

    for (int i = 0; i <= len; i++)
    {

        if (isalpha(str[i]))
        {
            t++;
            //printf("%d  ", t);
        }
        if (str[i] == ' ' || str[i] == '\0')
        {
           // printf("%d", t);
            if (c < t)
            {
                c = t;
                pos = i -c;
               // printf("pos = %d,c = %d", pos, c);
            }
            t = 0;
        }
    }
   // printf("pos = %d,c = %d", pos, c);
    printf("The longest is:");
    
    for(int i = pos; i < pos + c; i++)
    {
        putchar(str[i]);
    }
    
    return 0;
}
