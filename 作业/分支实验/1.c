#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    float a = 0.0, b = 0.0, c = 0.0, delta = 0.0;
    double x_1 = 0.0, x_2 = 0.0;
A:
    printf("press a, b, c's num:\n");
    scanf("%f %f %f", &a, &b, &c);
    delta = b * b - a * c * 4;
    if (a == 0)
    {
        if (b == 0)
        {

            if (c == 0)
            {
                printf("It is not equation.try again.\n");
                goto A;
            }

            else
            {
                printf("No solution to the equation.Please try again.\n");
                goto A;
            }
        }
        
    }
    if (delta < 0)
    {
        printf("No solution to the equation.Please try again.\n");
        goto A;
    }
    else if (delta == 0)
    {
        x_2 = ((-b) + sqrt(delta)) / 2 * a ;

        printf("x = %f \n", x_1);
    }

    else
    {
        x_1 = ((-b) + sqrt(delta)) / 2 * a ;
        x_2 = ((-b) - sqrt(delta)) / 2 * a ;
        printf("x1 = %f, x2 = %f \n", x_1, x_2);
    }

    return 0;
}
