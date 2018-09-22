#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a[5]; // 静态 5*4=20byte
    int len;
    int *pArr;

    //printf("请输入你要存放的元素个数:\n");
    //scanf("%d", &len);
    len = 2;
    pArr = (int *)malloc(sizeof(int) * len);
    for (int count = 0; count <= 3; count++)
    {
        scanf("%d", &pArr[count]);
    }

    printf("%p\t%d\n%p\t%d", pArr, *(pArr), pArr + 1, *(pArr + 1));
    printf("\n%p\t%d\n", pArr + 2, *(pArr + 2));
    printf("%p\t%d\n", pArr + 3, *(pArr + 3)); // 没有实际意义..

    // 静态数组越界
    a[-1] = -1;
    a[0] = 0;
    a[5] = 5;
    printf("%d\t%p\n%d\t%p\n%d\t%p\n\n", a[-1], a[-1], a[0], a[0], a[5], a[5]);  // 不用指针进行输出 地址有问题 但是值没有问题
    
    int *pArr_ = &a;
    printf("%d\t%p\n%d\t%p\n%d\t%p\n", *(pArr_ - 1), pArr_ - 1, *(pArr_), pArr_, *(pArr_ + 5), pArr_ + 5);  // 都没有问题
    // 事实证明指针可以越界 但是没有分配的内存可能导致程序崩溃 .
    free(pArr);
    //realloc(pArr_, 100);

    return 0;
}
