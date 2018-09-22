#include<stdio.h>

int main(int argc, char const *argv[])
{
    int i = 10;
    int *p = &i;

    int **q = &p;
    int ***r = &q;

    printf("%d\t%p\t%p\n", ***r, r,p);
    return 0;
}
