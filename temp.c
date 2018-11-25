#include <stdio.h>
int main(int argc, const char * argv[])
{
unsigned char a[4] = {230, 136, 145};
unsigned char b[4] = {231, 136, 177};
unsigned char c[4] = {228, 189, 160};
printf("%s%s%s", a, b, c);
getchar();
return 0;
}