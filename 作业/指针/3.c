// 在数组中查找指定元素。输入一个正整数n（1<n≤10），然后输入n个整数存入数组a中，
//再输入一个整数x，在数组a中查找x。如果找到，则输出相应的最小下标（下标从0开始），
//否则输出“Not Found”。要求定义并调用函数search(int list[],int n,int x)，
//它的功能是在数组list中查找元素x，
//若找到则返回相应的最小下标，否则返回-1，参数n代表数组list中元素的数量。
#include <stdio.h>
int search(int list[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {

        if (x == *(list + i))
        {
            return i;
        }
        else
            continue;
    }

    return -1;
}
int main(int argc, char const *argv[])
{
    int a[10] = {0};
    int n, x, s;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    scanf("%d", &x);
    s = search(a, n, x);

    if (s == -1)
    {
        printf("Not Found!\n");
    }
    else
        printf("%d", s);
    return 0;
}
