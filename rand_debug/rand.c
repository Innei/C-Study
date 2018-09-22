#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    unsigned int MAX = pow(2, 20);
    int RAND = rand() % MAX; // 框定范围
    int input = 0;
    // printf("%d\n", RAND);

    while (1)
    {
        printf("enter a num to guess the rand num,press 'q' to exit.\n");
        if (scanf("%d", &input) == 1)
        {
            //printf("%d\n", input);
            if (input == RAND)
            {
                printf("you are right.\n");
            }

            else if (input == 'q')
            {
                return 0;
            }
            else
            {
                printf("error.try again.\n");
            }
        }
        else
        {
            return 0;
        }
    }

    return 0;
}
