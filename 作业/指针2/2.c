#include <stdio.h>
#include <stdlib.h>
void squeeze(char s[], int c)
{
    int i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}
int main(int argc, char const *argv[])
{
    char ch;
    char *str = (char *)malloc(sizeof(char) * 100);

    if (NULL == str)
    {
        exit(1);
    }

    // scanf("%[^\n]", str);
    gets(str);
    scanf("%c", &ch);
    squeeze(str, ch);

    printf("After deleted,the string is:%s", str);

    return 0;
}
