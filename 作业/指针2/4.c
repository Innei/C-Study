#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *month[] = {"January", "Feb.", "March", "April", "May", "June", "July",
                     "August", "Sept.", "Oct.", "Nov.", "Dec."};

    int m;
    scanf("%d", &m);
    if (m < 1 || m > 12)
    {
        printf("Error.\n");
    }

    else
    {
        printf("%s\n", month[m - 1]);
    }

    return 0;
}
