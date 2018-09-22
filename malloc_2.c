#include <stdio.h>
#include <stdlib.h>
void f(int *q)
{
    //  p = 200;  error
    //  q = 200;  error
    *q = 200;
    free(q);  // free后的堆内存，原地址数据对不对，得看运气。。。
              // 运气好，系统还没把内存挪作他用，就还是原来的数据。。
              // 运气不好就会各种报错，或错误数据。。。
}
int main(int argc, char const *argv[])
{
    int *p = (int *)malloc(sizeof(4));
    *p = 10;

    printf("%d\n%p\n", *p,p); // 10

    f(p);
    printf("%d\n%p\n", *p,p); //200
    return 0;
}
