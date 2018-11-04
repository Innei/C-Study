#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 1;
    printf("%d %d %d %d %d ", i, i++, ++i, i, i = i + 1);
    return 0;
}
