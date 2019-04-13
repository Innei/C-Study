#include "简易通讯录(链表).h"

int main(int argc, char const *argv[])
{
    PNODE pHead = NULL;
    pHead = init_record();
    prt(pHead);
    return 0;
}

void insert_record(PNODE pHead)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    printf("学号: ");
    scanf("%d", &pNew->id);
    printf("姓名: ");
    scanf("%s", pNew->name);
    fflush(stdin); // 清空缓冲区
    getchar();
sex:
    printf("性别: ");
    fflush(stdin); // 清空缓冲区
    scanf("%c", &pNew->sex);
    if (pNew->sex != 'F' && pNew->sex != 'M')
    {
        fflush(stdin); // 清空缓冲区
        printf("输入有误\n");
        goto sex;
    }
    printf("生日: ");
    printf("年: ");
    scanf("%d", &pNew->birth.year);
    printf("月: ");
    scanf("%d", &pNew->birth.month);
    printf("日: ");
    scanf("%d", &pNew->birth.day);
    printf("手机: ");
    scanf("%s", pNew->phone);

    FILE *fp = fopen("record.txt", "a+");
    if (fp != NULL)
    {
        if (count == 0)
        {
            fprintf(fp, " %d ;  %s ;  %c ;  %d ; %d ; %d ;  %s ;", pNew->id, pNew->name, pNew->sex, pNew->birth.year, pNew->birth.month, pNew->birth.day, pNew->phone);
        }
        else
            fprintf(fp, "\n %d ;  %s ;  %c ;  %d ; %d ; %d ;  %s ;", pNew->id, pNew->name, pNew->sex, pNew->birth.year, pNew->birth.month, pNew->birth.day, pNew->phone);
    }
    else
    {
        printf("写文件失败!\n");
    }
    fclose(fp);
    if (pHead->pNext->pNext)
    {
        pNew->pNext = pHead->pNext->pNext;
    }
    else
    {
        pNew->pNext = NULL;
    }

    pHead->pNext = pNew;
    count++;
}
PNODE init_record(void)
{
    PNODE pHead = NULL;

    FILE *fp = fopen("record.txt", "r");
    if (fp == NULL || getc(fp) == EOF)
    {
        pHead = (PNODE)malloc(sizeof(NODE));
        return pHead;
    }

    else
    {
        pHead = (PNODE)malloc(sizeof(NODE));
        PNODE pTail = pHead;
        char s[100];
        while (!feof(fp)) //循环读取每一行，直到文件尾
        {
            fgets(s, 100, fp); //将fp所指向的文件一行内容读到strLine缓冲区

            PNODE pNew = (PNODE)malloc(sizeof(NODE));

            char *pch;
            pch = strtok(s, " ;");
            pNew->id = ToUInt(pch);
            pch = strtok(NULL, " ;");
            strcpy(pNew->name, pch);
            pch = strtok(NULL, " ;");
            pNew->sex = pch[0];
            pch = strtok(NULL, " ;");
            // birth
            pNew->birth.year = ToUInt(pch);
            pch = strtok(NULL, " ;");
            pNew->birth.month = ToUInt(pch);
            pch = strtok(NULL, " ;");
            pNew->birth.day = ToUInt(pch);
            pch = strtok(NULL, " ;");

            strcpy(pNew->phone, pch);
            pch = strtok(NULL, " ;");

            pTail->pNext = pNew;
            pNew->pNext = NULL;
            pTail = pNew;
            count++;
        }
        fclose(fp);
    }
    return pHead;
}

void prt(PNODE pHead)
{
    if (count == 0)
    {
        printf("没有记录!\n");
        return;
    }
    int i = 1;
    PNODE p = pHead->pNext;
    while (p)
    {
        printf("第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d-%d-%d ; 手机: %s ;\n", i, p->id, p->name, p->sex, p->birth.year, p->birth.month, p->birth.day, p->phone);
        i++;
        p = p->pNext;
    }
}

int *search_record(PNODE pHead)
{
    int *num = NULL; // 第几条记录
    int numC = 0;    // 数组计数
    num = (int *)malloc(sizeof(int) * 10);
    int s = 0;
    int birth;
    int b = 0;
    char name[10];
    char sex = ' ';
    char phone[15];
    getchar();
    printf("1）学号查找、2）姓名查找、3）手机查找、4）性别查找、5）生日范围查找\n");
    scanf("%d", &s);
    getchar();
    PNODE p = pHead->pNext;
    switch (s)
    {
    case 1:
        printf("输入学号:\n");
        scanf("%d", &b);
        int i = 1;
        while (p)
        {
            if (p->id == b)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d-%d-%d ; 手机: %s ;\n", i, p->id, p->name, p->sex, p->birth.year, p->birth.month, p->birth.day, p->phone);
                p = p->pNext;
                num[numC] = i + 1;
                numC++;
            }
            i++;
        }

        break;
    case 2:
        printf("输入姓名:\n");
        scanf("%s", name);
        i = 1;
        while (p)
        {
            if (strcmp(p->name, name) == 0)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d-%d-%d ; 手机: %s ;\n", i, p->id, p->name, p->sex, p->birth.year, p->birth.month, p->birth.day, p->phone);
                p = p->pNext;
                num[numC] = i + 1;
                numC++;
            }
            i++;
        }

        break;
    case 3:
        printf("输入手机:\n");
        scanf("%s", phone);
        i = 1;
        while (p)
        {
            if (strcmp(p->phone, phone) == 0)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d-%d-%d ; 手机: %s ;\n", i, p->id, p->name, p->sex, p->birth.year, p->birth.month, p->birth.day, p->phone);
                p = p->pNext;
                num[numC] = i + 1;
                numC++;
            }
            i++;
        }

        break;
    case 4:
        printf("输入性别:\n");
        sex = getchar();
        i = 1;
        while (p)
        {
            if (p->sex == sex)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d-%d-%d ; 手机: %s ;\n", i, p->id, p->name, p->sex, p->birth.year, p->birth.month, p->birth.day, p->phone);
                p = p->pNext;
                num[numC] = i + 1;
                numC++;
            }
            i++;
        }

        break;

    case 5:
        printf("输入生日(年或月或日):\n");
        scanf("%d", &birth);
        i = 1;
        while (p)
        {
            if (p->birth.year == birth || p->birth.month == birth || p->birth.day == birth)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d-%d-%d ; 手机: %s ;\n", i, p->id, p->name, p->sex, p->birth.year, p->birth.month, p->birth.day, p->phone);
                p = p->pNext;
                num[numC] = i + 1;
                numC++;
            }
            i++;
        }

        break;
    default:
        printf("输入错误\n");
        break;
    }
    if (numC == 0)
    {
        printf("无结果\n");
    }

    return num;
}

void del_record(PNODE pHead)
{
    int n = 0;
    printf("删除记录首先要搜索记录, 然后选择你要删除的记录:\n");
    int *num = search_record(pHead);
A:
    printf("你要删除结果中的哪一项: ");
    scanf("%d", &n);
    if (sizeof(num) / sizeof(int) < n)
    {
        printf("输入有误!\n");
        goto A;
    }
    else
    {
        PNODE p = pHead->pNext;
        PNODE r = pHead; // p的前一个节点
        if (count == 1)
        {
            remove("record.txt");
            fopen("record.txt", "a+");
            count--;
        }
        else
        {
            DeleteLine("record.txt", num[n - 1]);
            for (int i = 0; i < num[n - 1] - 1; i++) // 每次指向下一个节点, 如果是第一个节点, 直接从头结点指向下一个节点.
            {
                p = p->pNext;
                r = r->pNext;
            }

            if (p->pNext)
            {
                PNODE t = p;
                r->pNext = p->pNext;
                free(t); // 释放掉原来的p节点
                t = NULL;
            }
            else
            {
                r->pNext = NULL;
            }

            count--;
            prt(pHead);
        }
    }
}
