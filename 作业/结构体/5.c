#include <stdio.h>

struct complex
{
    int a,b;

} x, y, z;

int main(int argc, char const *argv[])
{
    printf("Enter a1,a2,b1,b2:");
    scanf("%d%d%d%d", &x.a, &x.b, &y.a, &y.b);
    z.a=x.a*y.a-x.b*y.b;
    z.b=x.a*y.b+x.b*y.a;
    printf("\n (%d + %di) * (%d+%di) = %d + %di\n", x.a, x.b, y.a, y.b, z.a, z.b);
    return 0;
}
