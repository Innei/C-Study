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
            printf("���ˣ����ٲ£�\n");
        }
        else if (num < ret)
        {
            printf("С�ˣ����ٲ£�\n");
        }
        else
        {
            printf("��ϲ���������ˣ�\n");
            system("pause");
            break;
        }
    }
    return 0;
}

void menu()
{
    printf("**************************\n");
    printf("****** ��������Ϸ!   ******\n");
    printf("******   1:��ʼ��Ϸ  ******\n");
    printf("******   2:�˳���Ϸ  ******\n");
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
        printf("���ǿ�ʼ��!\n");
        game();
        break;
    }
    default:
    {
        printf("�����ټ���!\n");
        return 0;
    }
    }
}
