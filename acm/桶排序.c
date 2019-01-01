#include <stdio.h>
#include <stdlib.h>
#define RADIX_10 10    //整形排序
#define KEYNUM_31 10     //关键字个数，这里为整形位数
// 找到num的从低到高的第pos位的数据
int GetNumInPos(int num,int pos)
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
		temp *= 10;
    
	return (num / temp) % 10;
}
void RadixSort(int* pDataArray, int iDataNum)
{
	int *radixArrays[RADIX_10];    //分别为0~9的序列空间
	for (int i = 0; i < 10; i++)
	{
		radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));
		radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
	}
	
	for (int pos = 1; pos <= KEYNUM_31; pos++)    //从个位开始到31位
	{
		for (int i = 0; i < iDataNum; i++)    //分配过程
		{
			int num = GetNumInPos(pDataArray[i], pos);
			int index = ++radixArrays[num][0];
			radixArrays[num][index] = pDataArray[i];
		}
        
		for (int i = 0, j =0; i < RADIX_10; i++)    //收集
		{
			for (int k = 1; k <= radixArrays[i][0]; k++)
				pDataArray[j++] = radixArrays[i][k];
			radixArrays[i][0] = 0;    //复位
		}
	}
}

int main(int argc, char const *argv[])
{
    int n = 0;
    int *a = NULL;

    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    RadixSort(a, n);
    // int t;
    // for (int i = 0; i < n - 1; i++)
    // {

    //     for (int j = i + 1; j < n; j++)
    //     {

    //         if (*(a + i) < *(a + j))
    //         {
    //             t = *(a + j);
    //             *(a + j) = *(a + i);
    //             *(a + i) = t;
    //         }
    //     }
    // }
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
    
    return 0;
}
