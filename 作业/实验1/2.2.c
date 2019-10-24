#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str[100];
    gets(str);
    int len = strlen(str);
    int num = 0, letter = 0, space = 0, other = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(str[i]))
        {
            letter++;
        }
        else if (isdigit(str[i]))
        {
            num++;
        }
        else if (isspace(str[i]))
        {
            space++;
        }
        else
        {
            other++;
        }
    }
    printf("num = %d, letter = %d, space = %d, other = %d", num, letter, space, other);

    return 0;
}
