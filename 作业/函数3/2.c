#include <stdio.h>
#include <math.h>

double funcos(double e, double x)
{
    int i = 0;
    double s = 0, t = 1;

    while (fabs(t) >= e)
    {
        s = s + t;
        t = -t * pow(x, 2) / ((i + 1) * (i + 2));
        i += 2;
    }
    return s;
}
int main(int argc, char const *argv[])
{
    double e, x, cosx;
    printf("Enter e,x;");
    scanf("%lf%lf", &e, &x);
    cosx=funcos(e,x);
    printf("cos(%lf) = %lf\n", x, cosx);
    return 0;
}
