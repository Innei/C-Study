/*
3、	编写一个函数，利用参数传入一个3位数number，找出101至number之间所有满足下列两个条件的数：它是完全平方数，又有两位数字相同，如144、676等，函数返回找出这样的数据的个数，并编写主函数。例如，number为150时，函数返回值为2。
*/
#include <stdio.h>
int function(int x)
{
    int t1, t2, t3, multiple = 100;
    for (int i = 10; i <= 32; i++)
    {

        if (i * i == x)
        {

            t1 = x / multiple % 10;
            t2 = x / multiple / 10 % 10;
            t3 = x / multiple / 100 % 10;

            if (t1 == t2 || t1 == t3 || t2 == t3)
            {
                return 1;
            }
        }
    }
    return 0;
}
int statistics(int x)
{
    int count = 0;
    for (int i = 101; i <= x; i++)
    {

        if (function(i))
        {
            count++;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int number;
    printf("Enter a num:\n");
    scanf("%d", &number);
    printf("%d\n", statistics(number));
    return 0;
}
