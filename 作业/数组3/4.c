#include <stdio.h>
#include <string.h>
void select_sort(char a[], int n)
{
    int i, j, k, t;
    for (i = 0; i < n - 1; i++)
    {

        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] > a[k])
            {
                k = j;
            }
        }

        t = a[k];
        a[k] = a[i];
        a[i] = t;
    }
    return;
}

int main(int argc, char const *argv[])
{
    char maxc = '\0';
    char a[80];
    int len = 0;
    int s = 0;

    gets(a);
    len = strlen(a);
    select_sort(a, len);

    printf("%s\n", a);
    return 0;
}
