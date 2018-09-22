#include <stdio.h>
#include <stdlib.h>

void f(int **q)
{
    *q = (int *)malloc(sizeof(int));
    //molloc需要手动释放
    **q = 5;

}

int main(int argc, char const *argv[])
{
    int *p;

    f(&p);
    printf("%d\n", *p);
    return 0;
}
