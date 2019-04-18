#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    unsigned long int id;

    struct bir
    {
        int year;
        int month;
        int day;
    } birth;
    char name[10], phone[15];
    char sex;

    struct student *pNext;
} NODE, *PNODE;
int count = 0;
PNODE init_record();
void insert_record(PNODE pHead);
void prt(PNODE pHead);
void myprint();
int *search_record(PNODE pHead);
void del_record(PNODE pHead);
void sort_record(PNODE pHead);
void sort_after_init(PNODE pHead);
unsigned long ToUInt(char *str)
{
    unsigned long mult = 1;
    unsigned long re = 0;
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
    {
        re = re + ((int)str[i] - 48) * mult;
        mult = mult * 10;
    }
    return re;
}

void DeleteLine(char *filepath, int n, int line)
{
    char buf[4096];                  //每读取一行，都将内容放到该数组中
    FILE *fp = fopen(filepath, "r"); //filepath里是原内容

    FILE *fpt = fopen("temp.txt", "w"); //将filepath文件第n行内容删除后存入temp.txt中
    int i = 0;
    while (!feof(fp))
    {
        i++;

        if (i == n)
        {

            fgets(buf, sizeof(buf), fp); //移动文件指针
        }
        else
        {
            // if (i == line - 1)
            // {
            // 	fgets(buf, sizeof(buf), fp);
            // 	fprintf(fpt, "%s\b\0", buf);
            // 	continue;
            // }
            fgets(buf, sizeof(buf), fp);
            fprintf(fpt, "%s", buf);
        }
    }
    fclose(fp);
    fclose(fpt);

    fpt = fopen("temp.txt", "r");

    //清空filepath文件
    fp = fopen(filepath, "wb");
    fclose(fp);

    //
    fp = fopen(filepath, "a");
    for (int i = 1; i < line && !feof(fpt); i++)
    {
        if (line - 1 == i && n == line)
        {
            char t[4096];

            fgets(buf, sizeof(buf), fpt);
            strcpy(t, buf);
            t[strlen(t) - 1] = '\0';
            fprintf(fp, "%s", t);
            continue;
        }
        fgets(buf, sizeof(buf), fpt);
        fprintf(fp, "%s", buf);
    }

    fclose(fp);
    fclose(fpt);

    //
    remove("temp.txt");
}



void sort_after_init(PNODE pHead)
{

    FILE *fp = fopen("record.txt", "w");
    int i = 1;
    PNODE p = pHead->pNext;
    if (fp != NULL)
    {
        while (p)
        {
            if (i == 1)
                fprintf(fp, " %lu ;  %s ;  %c ;  %d ; %d ; %d ;  %s ;", p->id, p->name, p->sex, p->birth.year, p->birth.month, p->birth.day, p->phone);
            else
                fprintf(fp, "\n %lu ;  %s ;  %c ;  %d ; %d ; %d ;  %s ;", p->id, p->name, p->sex, p->birth.year, p->birth.month, p->birth.day, p->phone);
            i++;
            p = p->pNext;
        }
    }
    else
    {
        printf("写文件失败!\n");
    }
    fclose(fp);
}