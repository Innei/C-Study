#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int RAND = rand();
    int input = 0;
    printf("%d\n", RAND);
    while (1)
    {
        if (scanf("%d", &input) == 1)
        {
            printf("%d\n", input);
            if (input == RAND)
            {
                printf("you are right.");
                /* code */
            }

            else
            {
                printf("error.");
            }

            /* code */
        }
        else {
            continue;
        }
    }
    
    return 0;
}
