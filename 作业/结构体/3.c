#include <stdio.h>
enum FLAG
{
    positive = 1,
    negative = -1
};
float f(float *x, int n, enum FLAG flag)
{
    float y;
    int i;
    y = x[0];
    for (i = 1; i < n; i++)
        if (flag * x[i] > flag * y)
            y = x[i];
    return y;
}
int main()
{
    float a[6] = {3, 5, 9, 4, 2.5, 1}, b[5] = {3, -2, 6, 9, 1};
    printf("%.2f\n", f(a, 6, positive) - f(b, 5, negative));
    return 0;
}
