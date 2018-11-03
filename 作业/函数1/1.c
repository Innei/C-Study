#include <stdio.h>
#include <math.h>

double dist(float x1, float y1, float x2, float y2)
{
    double res;
    res = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return res;
}
int main(int argc, char const *argv[])
{
    float x1, x2, y1, y2;
    double res;
    printf("请输入x1,y1 x2,y2:\n");
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
    res = dist(x1, y1, x2, y2);
    printf("res = %.2lf", res);
    return 0;
}
