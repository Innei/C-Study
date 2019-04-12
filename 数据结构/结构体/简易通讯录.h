#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void DeleteLine(char* filepath, int n)
{
	char buf[4096];    //每读取一行，都将内容放到该数组中
	FILE* fp = fopen(filepath, "r");     //filepath里是原内容

	FILE* fpt = fopen("temp.txt", "w");    //将filepath文件第n行内容删除后存入temp.txt中
	int i = 0;
	while (!feof(fp))
	{
		i++;
		if (i == n)
		{
			fgets(buf, sizeof(buf), fp);  //移动文件指针
		}
		else
		{
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
	while (!feof(fpt))
	{
		fgets(buf, sizeof(buf), fpt);
		fprintf(fp, "%s", buf);
	}

	fclose(fp);
	fclose(fpt);

	//
	remove("temp.txt");
	//system("rm temp.txt");   //删除文件temp.txt,使用该命令需要包含<stdlib.h>文件
}