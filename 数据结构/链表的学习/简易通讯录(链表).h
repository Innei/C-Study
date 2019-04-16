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

void DeleteLine(char *filepath, int n,int line)
{
    char buf[4096];					 //每读取一行，都将内容放到该数组中
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

//获得未排序数组中最大的一个元素值
int GetMaxVal(int *arr, int len)
{

    int maxVal = arr[0]; //假设最大为arr[0]

    for (int i = 1; i < len; i++) //遍历比较，找到大的就赋值给maxVal
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    return maxVal; //返回最大值
}

//桶排序   参数：数组及其长度
void BucketSort(int *arr, int len)
{
    int tmpArrLen = GetMaxVal(arr, len) + 1;
    int tmpArr[tmpArrLen]; //获得空桶大小
    int i, j;

    for (i = 0; i < tmpArrLen; i++) //空桶初始化
        tmpArr[i] = 0;

    for (i = 0; i < len; i++) //寻访序列，并且把项目一个一个放到对应的桶子去。
        tmpArr[arr[i]]++;

    for (i = 0, j = 0; i < tmpArrLen; i++)
    {
        while (tmpArr[i] != 0) //对每个不是空的桶子进行排序。
        {
            arr[j] = i; //从不是空的桶子里把项目再放回原来的序列中。
            j++;
            tmpArr[i]--;
        }
    }
}
