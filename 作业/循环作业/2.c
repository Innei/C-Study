#include <stdio.h>

int main(int argc, char const *argv[])
{
    int add_2 = 3;
    int add_1 = 2;
    double res = 0.5;
    int num = 0;
    printf("Enter a num : \n");
    scanf("%d", &num);
    if (num == 1)
    {
        printf("res = 0.50\n");
        exit(0);
    }
    for (int i = 2; i <= num; i++)
    {
        // getchar();
        res = add_1 / (add_2 + 0.0) + res;
        add_2 = add_2 +  (i );
        
        add_1 += (i - 1);
      //  printf("add 1 is %d ,2 is %d\n", add_1, add_2);
    }
    printf("res = %.2lf \n", res);
    return 0;
}
