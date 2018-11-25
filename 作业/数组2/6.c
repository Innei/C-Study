//6、	将二维数组a（5行6列）各行中的最大值找出并存放到一维数组b（5个元素）中下标值与行号对应的元素内。要求数组a的每行每列元素值由随机函数（rand函数，参见训练5.2教材第165页至166页）产生，且为0~20的整数。
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int a[5][6], max, b[5] = {0};
    srand(time(NULL));
    unsigned int MAX = 20;
    //int RAND = rand() % MAX; // 框定范围

    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j < 6; j++)
        {
            a[i][j] = rand() % MAX;
        }
    }
    max = a[0][0];
    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j < 6; j++)
        {

            if (max < a[i][j])
            {
                max = a[i][j];
            }
            if (j == 4)
            {

                b[i] = max;
                max = 0;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", b[i]);
    }

    return 0;
}
