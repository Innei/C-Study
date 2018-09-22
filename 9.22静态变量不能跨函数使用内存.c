#include<stdio.h>
void f(int **q)
{
    int i = 5;
    //*q等价于p
    //*q = i; //error 因为*q = i;等价于 p = i ;这样写是错误的
    printf("%d\n", **q);
    *q = &i; //p = &i //error
}
int main(int argc, char const *argv[])
{
    int *p;
    int i =3;
    p = &i;
    f(&p);
    printf("%d\n", *p);  //有问题 . 因为*p指向的i已经被释放. 编译没有报错 但是会造成bug

    return 0;
}
