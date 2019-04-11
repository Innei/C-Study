#include <stdio.h>
#include <stdlib.h>

struct student
{
    int id, birth;
    char name[10], phone[12];
    char sex;
};

int count = 0;
void insert_record(struct student stu[]);
void prt(struct student stu[]);
void myprint();
void search_record(struct student stu[]);
int main(int argc, char const *argv[])
{
    struct student *stu;
    stu = (struct student *)malloc(sizeof(struct student) * 1);
    if (NULL == stu)
    {
        printf("error");
        exit(1);
    }
    insert_record(stu);
    insert_record(stu);
    printf("%s", (stu + count)->name);
    prt(stu);
    while(1)
    search_record(stu);
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
        printf("第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d ; 手机: %s ;\n", i + 1, (stu + i)->id, (stu + i)->name, (stu + i)->sex, (stu + i)->birth, (stu + i)->phone);
    }
}
void insert_record(struct student *stu)
{
    printf("学号: ");
    scanf("%d", &(stu + count)->id);
    printf("姓名: ");
    scanf("%s", &(stu + count)->name);
sex:
    printf("性别: ");
    getchar();
    scanf("%c", &(stu + count)->sex);
    if ((stu + count)->sex != 'F' && (stu+count)->sex != 'M')
    {
        printf("输入有误\n");
        goto sex;
    }
    printf("生日: ");
    scanf("%s", &(stu + count)->birth);
    printf("手机: ");
    scanf("%s", &(stu + count)->phone);
    count++;
}

void search_record(struct student *stu)
{
    int s = 0;
    printf("1）学号查找、2）姓名查找、3）手机查找、4）性别查找、5）生日范围查找\n");
    scanf("%d", &s);
    switch (s)
    {
    case 1:
        int b;
        scanf("%d", &b);
        for (int i = 0; i < count; i++)
        {
            if ((stu + i)->id == b)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d ; 手机: %s ;\n", i + 1, (stu + i)->id, (stu + i)->name, (stu + i)->sex, (stu + i)->birth, (stu + i)->phone);
            }
        }
        break;
    case 2:
        char *name = NULL;
        scanf("%s", name);
        for (int i = 0; i < count; i++)
        {
            if ((stu + i)->name == name)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d ; 手机: %s ;\n", i + 1, (stu + i)->id, (stu + i)->name, (stu + i)->sex, (stu + i)->birth, (stu + i)->phone);
            }
        }
        break;
    case 3:
        char *phone = NULL;
        scanf("%s", phone);
        for (int i = 0; i < count; i++)
        {
            if ((stu + i)->phone == phone)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d ; 手机: %s ;\n", i + 1, (stu + i)->id, (stu + i)->name, (stu + i)->sex, (stu + i)->birth, (stu + i)->phone);
            }
        }
        break;
    case 4:
        char sex;
        scanf("%c", &sex);
        for (int i = 0; i < count; i++)
        {
            if ((stu + i)->sex == sex)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d ; 手机: %s ;\n", i + 1, (stu + i)->id, (stu + i)->name, (stu + i)->sex, (stu + i)->birth, (stu + i)->phone);
            }
        }
        break;

    case 5:
        int birth;
        scanf("%d", &birth);
        for (int i = 0; i < count; i++)
        {
            if ((stu + i)->birth == birth)
            {
                printf("查找到了第%d条记录: 学号: %d ; 姓名: %s ; 性别: %c ; 生日: %d ; 手机: %s ;\n", i + 1, (stu + i)->id, (stu + i)->name, (stu + i)->sex, (stu + i)->birth, (stu + i)->phone);
            }
        }
        break;
    default:
        printf("输入错误");
        break;
    }
}