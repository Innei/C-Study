#include <stdio.h>

int main(int argc, char const *argv[])
{
    double peach_Nums = 10000.0,peach = 10000.0;  // 使用int会导致进度丢失产生多个可能值.
                // 倒序计算
    while (peach >= 0)
    {
        peach_Nums = peach;
        for (int i = 1; i <= 9; i++)
        {
            peach_Nums = peach_Nums / 2.0;
            peach_Nums--;
          // printf("peach had %d \n", peach);
 
        }
        
        if (peach_Nums == 1.0 ) {
            printf("桃子可能有: %.0f \n", peach); 
        }

        peach--;
    }

    return 0;
}