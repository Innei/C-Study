#include <stdio.h>

char *str_cat(char *, char *);
int main(int argc, char const *argv[])
{
    char s[80], t[80];
    gets(s);
    gets(t);
    puts(str_cat(s, t));
    return 0;
}
char *str_cat(char *s, char *t)
{
    char *p = s, *q = t;
    while (*p)
        p++;
    while (*q)
    {
        *p = *q;
        p++;
        q++;
    }
    *p = '\0';
    return s;
}
