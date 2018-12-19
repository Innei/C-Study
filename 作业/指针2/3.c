#include <stdio.h>
#include <stdlib.h>
void strmcpy(char *s,char *t,int m)
{
    int len = strlen(t);
    int j = 0;
    for(int i = m - 1; i <= len; i++)
    {
        s[j++] = t[i];
    }
    
}
int main(int argc, char const *argv[])
{
    char t[80];
    int n = 0;
    char s[80];
    gets(t);
    scanf("%d",&n);
    strmcpy(s, t, n);
    printf("%s", s);

    return 0;
}
