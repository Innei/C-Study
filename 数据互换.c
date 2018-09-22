#include <stdio.h>

int a = 1;
int b = 2;

void swap(a, b) //全局变量为什么也不行.
{
    int temp = 0;

    temp = a;
    a = b;
    b = temp;
    printf("a = %d , b = %d \n", a, b);
}
void swapextern() //全局变量为什么也不行.
{
    int temp = 0;

    temp = a;
    a = b;
    b = temp;
    printf("a = %d , b = %d \n", a, b);
}
void swapoint_1(int *p, int *q) // 这个是无效的 因为地址只在函数内部修改
{
    int *temp; // 如果要互换 p和q ,temp必须是int * ,不能是int
    temp = p;
    p = q;
    q = temp;
}
//这是正确的 ~~~~~
void swapoint_2(int *p, int *q)
{
    int temp; //如果互换 *p和*q的值 temp必须int

    temp = *p;
    *p = *q;
    *q = temp;
}

int main(int argc, char const *argv[])
{

    swap(a, b);
    printf("a = %d , b = %d \n", a, b);
    swapextern();

    extern int a;
    extern int b;

    printf("a = %d , b = %d \n", a, b);
    //
    a = 1;
    b = 2;
    //

    swapoint_1(&a, &b); //获取指针 的 常见错误 (a , b) (*a , *b) 应该取址
    printf("swapoint_1 : a = %d , b = %d \n", a, b);

    swapoint_2(&a, &b);
    printf("swapoint_2 : a = %d , b = %d \n", a, b);

    return 0;
}
