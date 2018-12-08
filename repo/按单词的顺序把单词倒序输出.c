

// #include <stdio.h>
// #include <string.h>
// int main(int argc, char const *argv[])
// {
//     char str[100];
//     char overTurn[100];
//     char space[] = " ";

//     int len = 0;
//     int i, count = 0, k = 0;
//     gets(str);
//     len = strlen(str);
//     count = len;

//     //  for( i = 0; i < len; i++)
//     //{
//     char *result = NULL;
//     result = strtok(str, space);
//     while (result != NULL)
//     {
//         strcat(result, overTurn);
//         result = strtok(NULL, space);
//     }
//     // }

//     // printf("%s",strtok(str, " "));
//     printf("%s\n", overTurn);
//     return 0;
// }
#include <stdio.h>
#include <string.h>
int main()
{
    char a[] = "";
    char *p = NULL, *q = NULL;
    int i, j, length;
    gets(a);
    length = strlen(a);
    q = &a[length];
    p = &a[length];
    for (i = length - 1; i >= 0; i--)
        if (a[i] == ' ')
        {
            p = &a[i];
            for (j = 1; j <= q - p; j++)
                printf("%c", *(p + j));
            q = p - 1;
            putchar(' ');
        }
    p = &a[0];
    for (j = 0; j <= q - p; j++)
       printf("%c", *(p + j));
    putchar('\n');
    return 0;
}