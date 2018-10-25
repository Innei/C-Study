#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    double x, eps, s = 0, t = 1, i = 0.0;
    printf("Enter x,eps(eps>0): \n");
    scanf("%lf%lf", &x, &eps);

    while (fabs(t) >= eps)
    {
        s += t;
        i++;
        t = -t * x / i;
    }

    printf("%lf\n", s);
    return 0;
}
