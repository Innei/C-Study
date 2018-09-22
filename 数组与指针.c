#include<stdio.h>

int main(int argc, char const *argv[])
{
    int array[] = {1, 2, 3, 4, 5};
    int *p;
    p = &array;
    printf("%p\n", array);
    printf("%d\n", *array);

    printf("%p\n", p);
    printf("%d\n", *p);

    printf("%p\n", p + 1);
    printf("%d\n", *(p + 1)); // int指针 4byte

    char arr[] = "hello,world";
    char *p2 = &arr;
    printf("arr[1] : %p ,arr[2] = %p \n", p2, p2 + 1);  //char指针是一个byte

    return 0;
}
