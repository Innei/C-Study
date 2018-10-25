#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    double x, eps, s = 0, t = 0;
    printf("Enter x,eps(eps>0): \n");
    scanf("%lf%lf", &x, &eps);
    for (int i = 0; fabs(t) >= eps; i++)
    {
        s += t;
        t = -t * x / i;
    }
    printf("%lf\n",s);
    return 0;
}
