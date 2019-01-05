#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game()
{
    int num = 0;
    int ret = 0;
    srand((unsigned int)time(NULL));
    ret = rand();
    ret = ret % 100;

    while (1)
    {
        scanf("%d", &num);
        if (num > ret)
        {
            printf("大了，请再猜！\n");
        }
        else if (num < ret)
        {
            printf("小了，请再猜！\n");
        }
        else
        {
            printf("恭喜您，猜中了！\n");
            system("pause");
            break;
        }
    }
    return 0;
}

void menu()
{
    printf("**************************\n");
    printf("****** 猜数字游戏!   ******\n");
    printf("******   1:开始游戏  ******\n");
    printf("******   2:退出游戏  ******\n");
    printf("***************************\n");
}

int main()
{
    int ch = 0;
    menu();
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
    {
        printf("我们开始吧!\n");
        game();
        break;
    }
    default:
    {
        printf("我们再见吧!\n");
        return 0;
    }
    }
}
