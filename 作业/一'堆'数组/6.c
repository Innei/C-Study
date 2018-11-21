//6、	编写程序，先从键盘输入10个数存放在数组a中，再将a的元素中所有偶数值存放到数组b中。
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[10];
    int b[10], count = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);

        if (a[i] % 2 == 0)
        {
            b[count] = a[i];
            count++;
        }
    }
    for (int i = 0; i < count;i++)
        printf("%d   ", b[i]);
    return 0;
}
