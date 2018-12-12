//定义函数void sort(int a[],int n)，
//用选择法对数组a中的元素升序排列。
//自定义main函数，在主函数中输入n个整数并在其中调用sort函数。

#include <stdio.h>
void sort(int a[], int n)
{
    int i, j, k, t;
    for (i = 0; i < n - 1; i++)
    {

        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }

        t = a[k];
        a[k] = a[i];
        a[i] = t;
    }
    return;
}
int main(int argc, char const *argv[])
{
    int a[10] = {0};
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    
    sort(a, n);
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
}
