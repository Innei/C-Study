#include <stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int *p;
    int *q;

    int i;
    i = 2;

    p = &i;

    printf("%p\n", p);
    printf("%d\n", *p);
/*
    //swap
    q = p;
    printf("%p\n", q);
    printf("%d\n", *q);
    //
    int *p2;
    int i2;
    p2 = &i2;
    printf("%p\n", p2);
    printf("%d\n", *p2);  //unix 自动初始化变量为0 ????
    printf("%d\n", i2);
*/
    //free
    //q=p  //error
    free(q);
    //free(p);


    return 0;
}
