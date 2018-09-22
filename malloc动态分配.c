/*
        malloc 是 memory allocate(分配)的缩写
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int i = 5;
    int *p = (int *)malloc(4); // p是静态内存 不能用free进行释放
                               // p指向的 内存 是动态内存 可以用 free(p); 进行释放.
                               // 静态内存不能手动释放 只能到程序结束自动释放
    free(p);
    return 0;
}
