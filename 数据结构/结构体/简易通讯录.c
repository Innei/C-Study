/**
 * @repos: Simple-telenote
 * @author: yiny
 */

#include "简易通讯录.h"
struct student
{
    int id;
    struct bir
    {
        int year;
        int month;
        int day;
    } birth;

    char name[10], phone[15];
    char sex;
};

int count = 0;
struct student *init_record();
void insert_record(struct student stu[]);
void prt(struct student stu[]);
void myprint();
int *search_record(struct student stu[]);
void del_record(struct student *stu);
int main()
{
    struct student *stu;
    stu = (struct student *)malloc(sizeof(struct student) * 10);
    if (NULL == stu)
    {
        printf("error");
        exit(1);
    }
    stu = init_record();
    // insert_record(stu);
    // insert_record(stu);
    // printf("%s", (stu + count)->name);
    // prt(stu);
    // while (1)
    //     search_record(stu);
    del_record(stu);
    prt(stu);
    return 0;
}

void myprint()
{
    system("cls");
    printf("      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("      |    请输入选项编号（0-7）:      |\n");
    printf("      |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("      |          1:输入（追加）       |\n");
    printf("      |          2:显示（打印）       |\n");
    printf("      |          3:插入             |\n");
    printf("      |          4:删除             |\n");
    printf("      |          5:排序             |\n");
    printf("      |          0:退出             |\n");
    printf("       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void prt(struct student *stu)
{
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
sex:
    printf("性别: ");
    getchar();
    scanf("%c", &(stu + count)->sex);
    if ((stu + count)->sex != 'F' && (stu + count)->sex != 'M')
    {
        printf("输入有误\n");
        goto sex;
    }
    printf("生日: ");
    scanf("%d", &(stu + count)->birth.year);
    scanf("%d", &(stu + count)->birth.month);
    scanf("%d", &(stu + count)->birth.day);
    printf("手机: ");
    scanf("%s", (stu + count)->phone);
    count++;

    FILE *fp = fopen("record.txt", "a+");
    if (fp != NULL)
    {
        fprintf(fp, " %d ;  %s ;  %c ;  %d ; %d ; %d ;  %s ;\n", stu->id, stu->name, stu->sex, stu->birth.year, stu->birth.month, stu->birth.day, stu->phone);
    }
    else
    {
        printf("写文件失败!\n");
    }
    fclose(fp);
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
    return num;
}

struct student *init_record()
{
    struct student *p = (struct student *)malloc(sizeof(struct student) * 10);
    FILE *fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("record.txt", "a+");
        fprintf(fp, "ID  NAME  SEX  BIRTH  PHONE \n");
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
        // FILE *fp = fopen("record.txt", "w+");
        DeleteLine("record.txt", num[n - 1]);
        (stu + num[n - 1] - 1)->birth.day = (stu + count - 1)->birth.day;
        (stu + num[n - 1] - 1)->birth.month = (stu + count - 1)->birth.month;
        (stu + num[n - 1] - 1)->birth.year = (stu + count - 1)->birth.year;
        (stu + num[n - 1] - 1)->id = (stu + count - 1)->id;
        (stu + num[n - 1] - 1)->sex = (stu + count - 1)->sex;
        strcpy((stu + num[n - 1] - 1)->name, (stu + count - 1)->name);
        strcpy((stu + num[n - 1] - 1)->phone, (stu + count - 1)->phone);
        count--;
    }
}