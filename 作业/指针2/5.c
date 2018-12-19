#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char *weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    char str[10] = " ";
    gets(str);

    for (int i = 0; i < 7; i++)
    {

        if (strcmp(weekdays[i], str) == 0)
        {
            break;
        }

        if (i < 7)
        {
            printf("%d\n", i + 1);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}
