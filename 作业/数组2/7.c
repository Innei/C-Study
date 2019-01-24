//7、	对5×5矩阵的下半三角形（主对角线的下方）各元素中的值乘以2，
//      要求数组a的每行每列元素值由随机函数产生，且为0~20的整数。

#include <stdio.h>
#include <stdlib.h>
#define RAND rand() % 20
int main(int argc, char const *argv[])
{
    int a[5][5] = {0};
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            a[i][j] = RAND;
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    printf("之后\n");
    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            a[i][j] = 2 * a[i][j];
          //  printf("%3d", a[i][j]);
        }
   //     printf("\n");
    }

for(int i = 0; i < 5; i++)
{
    
    for(int j = 0; j < 5; j++)
    {
        printf("%3d", a[i][j]);
    }
    printf("\n");
}

return 0;
}
