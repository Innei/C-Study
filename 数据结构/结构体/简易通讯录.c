/**
 * @repos: Simple-Telenote
 * @author: yiny
 */

#include "简易通讯录.h"

int main()
{
    struct student *stu;
    stu = init_record();
    if (NULL == stu)
    {
        printf("分配失败\n");
        exit(1);
    }
    while (1)
    {
        int n = 0;
        myprint();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insert_record(stu);
            printf("按任意键继续\n");
            getchar();
            // system("pause");
            break;
        case 2:
            prt(stu);
            printf("按任意键继续\n");
            getchar();
            // system("pause");
            break;

        case 3:
            search_record(stu);
            printf("按任意键继续\n");
            getchar();
            // system("pause");
            break;
        case 4:
            del_record(stu);
            printf("按任意键继续\n");
            getchar();
            // system("pause");
            break;
        case 5:
            sort_record(stu);
            printf("按任意键继续\n");
            getchar();
            // system("pause");
            break;
        case 0:
            exit(0);

        default:
            printf("输入有误!\n");
            break;
        }
    }
    
    return 0;
}

void myprint()
{
    system("clear");
    printf("      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("      |    请输入选项编号（0-5）:      |\n");
    printf("      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("      |          1:输入（追加）      |\n");
    printf("      |          2:显示（打印）      |\n");
    printf("      |          3:查找             |\n");
    printf("      |          4:删除             |\n");
    printf("      |          5:排序             |\n");
    printf("      |          0:退出             |\n");
    printf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf(" 请输入: ");
}

void prt(struct student *stu)
{
    if (count == 0)
    {
        printf("没有记录!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d-%d-%d ; 手机: %s ;\n", i + 1, (stu + i)->id, (stu + i)->name, (stu + i)->sex, (stu + i)->birth.year, (stu + i)->birth.month, (stu + i)->birth.day, (stu + i)->phone);
    }
}
void insert_record(struct student *stu)
{
    printf("学号: ");
    scanf("%d", &(stu + count)->id);
    printf("姓名: ");
    scanf("%s", (stu + count)->name);
    fflush(stdin); // 清空缓冲区
    getchar();
sex:
    printf("性别: ");
    fflush(stdin); // 清空缓冲区
    scanf("%c", &(stu + count)->sex);
    if ((stu + count)->sex != 'F' && (stu + count)->sex != 'M')
    {
        fflush(stdin); // 清空缓冲区
        printf("输入有误\n");
        goto sex;
    }
    printf("生日: ");
    printf("年: ");
    scanf("%d", &(stu + count)->birth.year);
    printf("月: ");
    scanf("%d", &(stu + count)->birth.month);
    printf("日: ");
    scanf("%d", &(stu + count)->birth.day);
    printf("手机: ");
    scanf("%s", (stu + count)->phone);

    FILE *fp = fopen("record.txt", "a+");
    if (fp != NULL)
    {
        if (count == 0)
        {
            fprintf(fp, " %d ;  %s ;  %c ;  %d ; %d ; %d ;  %s ;", (stu + count)->id, (stu + count)->name, (stu + count)->sex, (stu + count)->birth.year, (stu + count)->birth.month, (stu + count)->birth.day, (stu + count)->phone);
        }
        else
            fprintf(fp, "\n %d ;  %s ;  %c ;  %d ; %d ; %d ;  %s ;", (stu + count)->id, (stu + count)->name, (stu + count)->sex, (stu + count)->birth.year, (stu + count)->birth.month, (stu + count)->birth.day, (stu + count)->phone);
    }
    else
    {
        printf("写文件失败!\n");
    }
    fclose(fp);
    count++;
}

int *search_record(struct student *stu)
{
    int *num = NULL;
    int numC = 0; // 数组计数
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
    switch (s)
    {
    case 1:
        printf("输入学号:\n");
        scanf("%d", &b);
        for (int i = 0; i < count; i++)
        {
            if ((stu + i)->id == b)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d-%d-%d ; 手机: %s ;\n", i + 1, (stu + i)->id, (stu + i)->name, (stu + i)->sex, (stu + i)->birth.year, (stu + i)->birth.month, (stu + i)->birth.day, (stu + i)->phone);
                num[numC] = i + 1;
                numC++;
            }
        }
        break;
    case 2:
        printf("输入姓名:\n");
        scanf("%s", name);
        for (int i = 0; i < count; i++)
        {
            if (strcmp((stu + i)->name, name) == 0)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d-%d-%d ; 手机: %s ;\n", i + 1, (stu + i)->id, (stu + i)->name, (stu + i)->sex, (stu + i)->birth.year, (stu + i)->birth.month, (stu + i)->birth.day, (stu + i)->phone);
                num[numC] = i + 1;
                numC++;
            }
        }
        break;
    case 3:
        printf("输入手机:\n");
        scanf("%s", phone);
        for (int i = 0; i < count; i++)
        {
            if (strcmp((stu + i)->phone, phone) == 0)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d-%d-%d ; 手机: %s ;\n", i + 1, (stu + i)->id, (stu + i)->name, (stu + i)->sex, (stu + i)->birth.year, (stu + i)->birth.month, (stu + i)->birth.day, (stu + i)->phone);
                num[numC] = i + 1;
                numC++;
            }
        }
        break;
    case 4:
        printf("输入性别:\n");
        sex = getchar();
        for (int i = 0; i < count; i++)
        {
            if ((stu + i)->sex == sex)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d-%d-%d ; 手机: %s ;\n", i + 1, (stu + i)->id, (stu + i)->name, (stu + i)->sex, (stu + i)->birth.year, (stu + i)->birth.month, (stu + i)->birth.day, (stu + i)->phone);
                num[numC] = i + 1;
                numC++;
            }
        }
        break;

    case 5:
        printf("输入生日(年或月或日):\n");
        scanf("%d", &birth);
        for (int i = 0; i < count; i++)
        {
            if ((stu + i)->birth.year == birth || (stu + i)->birth.month == birth || (stu + i)->birth.day == birth)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d-%d-%d ; 手机: %s ;\n", i + 1, (stu + i)->id, (stu + i)->name, (stu + i)->sex, (stu + i)->birth.year, (stu + i)->birth.month, (stu + i)->birth.day, (stu + i)->phone);
                num[numC] = i + 1;
                numC++;
            }
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

struct student *init_record()
{
    struct student *p = (struct student *)malloc(sizeof(struct student) * 10);
    FILE *fp = fopen("record.txt", "r");
    if (fp == NULL || getc(fp) == EOF)
    {
        // fp = fopen("record.txt", "a+");
        // fprintf(fp, "ID  NAME  SEX  BIRTH  PHONE \n");
        return p;
    }

    else
    {
        char s[100];
        while (!feof(fp)) //循环读取每一行，直到文件尾
        {
            fgets(s, 100, fp); //将fp所指向的文件一行内容读到strLine缓冲区
            // printf("%s", s);   //输出所读到的内容
            // 分割字符串

            char *pch;
            pch = strtok(s, " ;");
            (p + count)->id = ToUInt(pch);
            pch = strtok(NULL, " ;");
            strcpy((p + count)->name, pch);
            pch = strtok(NULL, " ;");
            (p + count)->sex = pch[0];
            pch = strtok(NULL, " ;");
            // birth
            (p + count)->birth.year = ToUInt(pch);
            pch = strtok(NULL, " ;");
            (p + count)->birth.month = ToUInt(pch);
            pch = strtok(NULL, " ;");
            (p + count)->birth.day = ToUInt(pch);
            pch = strtok(NULL, " ;");

            strcpy((p + count)->phone, pch);
            pch = strtok(NULL, " ;");
            count++;
            // while (pch != NULL)
            // {
            //     printf("%s\n", pch);
            //     pch = strtok(NULL, " ;");
            // }
        }
        fclose(fp);
    }
    return p;
}

void del_record(struct student *stu)
{
    int n = 0;
    printf("删除记录首先要搜索记录, 然后选择你要删除的记录:\n");
    int *num = search_record(stu);
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
        if (count == 1)
        {
            remove("record.txt");
            fopen("record.txt", "a+");
            count--;
        }
        else
        {
            DeleteLine("record.txt", num[n - 1]);
            (stu + num[n - 1] - 1)->birth.day = (stu + count - 1)->birth.day;
            (stu + num[n - 1] - 1)->birth.month = (stu + count - 1)->birth.month;
            (stu + num[n - 1] - 1)->birth.year = (stu + count - 1)->birth.year;
            (stu + num[n - 1] - 1)->id = (stu + count - 1)->id;
            (stu + num[n - 1] - 1)->sex = (stu + count - 1)->sex;
            strcpy((stu + num[n - 1] - 1)->name, (stu + count - 1)->name);
            strcpy((stu + num[n - 1] - 1)->phone, (stu + count - 1)->phone);
            count--;
            prt(stu);
        }
    }
}

void sort_record(struct student *stu)
{
a:
    printf("1）学号排序、2）姓名排序、3）性别排序、4）手机排序、5）生日排序\n");
    int n = 1, t = 0;
    char st[30] = "";
    scanf("%d", &n); // todo

    int *id = (int *)malloc(sizeof(int) * count);
    char *name[count], *phone[count];
    char *sex = (char *)malloc(sizeof(int) * (count + 1));
    int *birth_year = (int *)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++)
    {
        id[i] = (stu + i)->id;
        name[i] = (char *)malloc(sizeof(char) * strlen((stu + i)->name));
        name[i] = (stu + i)->name;
        phone[i] = (char *)malloc(sizeof(char) * strlen((stu + i)->phone));
        phone[i] = (stu + i)->phone;
        sex[i] = (stu + i)->sex;
        birth_year[i] = (stu + i)->birth.year;
    }

    switch (n)
    {
    case 1:
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (id[i] > id[j])
                {
                    t = (stu + i)->id;
                    (stu + i)->id = (stu + j)->id;
                    (stu + j)->id = t;

                    t = (stu + i)->sex;
                    (stu + i)->sex = (stu + j)->sex;
                    (stu + j)->sex = t;

                    strcpy(st, (stu + i)->name);
                    strcpy((stu + i)->name, (stu + j)->name);
                    strcpy((stu + j)->name, st);

                    strcpy(st, (stu + i)->phone);
                    strcpy((stu + i)->phone, (stu + j)->phone);
                    strcpy((stu + j)->phone, st);

                    t = (stu + i)->birth.day;
                    (stu + i)->birth.day = (stu + j)->birth.day;
                    (stu + j)->birth.day = t;

                    t = (stu + i)->birth.month;
                    (stu + i)->birth.month = (stu + j)->birth.month;
                    (stu + j)->birth.month = t;

                    t = (stu + i)->birth.year;
                    (stu + i)->birth.year = (stu + j)->birth.year;
                    (stu + j)->birth.year = t;
                }
            }
        }

        break;
    case 2:
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (strcmp(name[i], name[j]) > 0)
                {
                    t = (stu + i)->id;
                    (stu + i)->id = (stu + j)->id;
                    (stu + j)->id = t;

                    t = (stu + i)->sex;
                    (stu + i)->sex = (stu + j)->sex;
                    (stu + j)->sex = t;

                    strcpy(st, (stu + i)->name);
                    strcpy((stu + i)->name, (stu + j)->name);
                    strcpy((stu + j)->name, st);

                    strcpy(st, (stu + i)->phone);
                    strcpy((stu + i)->phone, (stu + j)->phone);
                    strcpy((stu + j)->phone, st);

                    t = (stu + i)->birth.day;
                    (stu + i)->birth.day = (stu + j)->birth.day;
                    (stu + j)->birth.day = t;

                    t = (stu + i)->birth.month;
                    (stu + i)->birth.month = (stu + j)->birth.month;
                    (stu + j)->birth.month = t;

                    t = (stu + i)->birth.year;
                    (stu + i)->birth.year = (stu + j)->birth.year;
                    (stu + j)->birth.year = t;
                }
            }
        }
        break;
    case 3:
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (strcmp(phone[i], phone[j]) > 0)
                {
                    t = (stu + i)->id;
                    (stu + i)->id = (stu + j)->id;
                    (stu + j)->id = t;

                    t = (stu + i)->sex;
                    (stu + i)->sex = (stu + j)->sex;
                    (stu + j)->sex = t;

                    strcpy(st, (stu + i)->name);
                    strcpy((stu + i)->name, (stu + j)->name);
                    strcpy((stu + j)->name, st);

                    strcpy(st, (stu + i)->phone);
                    strcpy((stu + i)->phone, (stu + j)->phone);
                    strcpy((stu + j)->phone, st);

                    t = (stu + i)->birth.day;
                    (stu + i)->birth.day = (stu + j)->birth.day;
                    (stu + j)->birth.day = t;

                    t = (stu + i)->birth.month;
                    (stu + i)->birth.month = (stu + j)->birth.month;
                    (stu + j)->birth.month = t;

                    t = (stu + i)->birth.year;
                    (stu + i)->birth.year = (stu + j)->birth.year;
                    (stu + j)->birth.year = t;
                }
            }
        }
        break;
    case 4:
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (sex[i] > sex[j])
                {
                    t = (stu + i)->id;
                    (stu + i)->id = (stu + j)->id;
                    (stu + j)->id = t;

                    t = (stu + i)->sex;
                    (stu + i)->sex = (stu + j)->sex;
                    (stu + j)->sex = t;

                    strcpy(st, (stu + i)->name);
                    strcpy((stu + i)->name, (stu + j)->name);
                    strcpy((stu + j)->name, st);

                    strcpy(st, (stu + i)->phone);
                    strcpy((stu + i)->phone, (stu + j)->phone);
                    strcpy((stu + j)->phone, st);

                    t = (stu + i)->birth.day;
                    (stu + i)->birth.day = (stu + j)->birth.day;
                    (stu + j)->birth.day = t;

                    t = (stu + i)->birth.month;
                    (stu + i)->birth.month = (stu + j)->birth.month;
                    (stu + j)->birth.month = t;

                    t = (stu + i)->birth.year;
                    (stu + i)->birth.year = (stu + j)->birth.year;
                    (stu + j)->birth.year = t;
                }
            }
        }
        break;
    case 5:
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (birth_year[i] > birth_year[j])
                {
                    t = (stu + i)->id;
                    (stu + i)->id = (stu + j)->id;
                    (stu + j)->id = t;

                    t = (stu + i)->sex;
                    (stu + i)->sex = (stu + j)->sex;
                    (stu + j)->sex = t;

                    strcpy(st, (stu + i)->name);
                    strcpy((stu + i)->name, (stu + j)->name);
                    strcpy((stu + j)->name, st);

                    strcpy(st, (stu + i)->phone);
                    strcpy((stu + i)->phone, (stu + j)->phone);
                    strcpy((stu + j)->phone, st);

                    t = (stu + i)->birth.day;
                    (stu + i)->birth.day = (stu + j)->birth.day;
                    (stu + j)->birth.day = t;

                    t = (stu + i)->birth.month;
                    (stu + i)->birth.month = (stu + j)->birth.month;
                    (stu + j)->birth.month = t;

                    t = (stu + i)->birth.year;
                    (stu + i)->birth.year = (stu + j)->birth.year;
                    (stu + j)->birth.year = t;
                }
            }
        }
        break;
    default:
        printf("输入错误\n");
        break;
    }
    prt(stu);
}