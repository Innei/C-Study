#include <stdio.h>

int main(int argc, char const *argv[])
{
    int sorce = 0;
    scanf("%d", &sorce);
    if (sorce >= 90 && sorce <= 100)
    {
        printf("优秀.\n");
    }
    else if (sorce >= 80 && sorce < 90)
        printf("良好.\n");
    else if (sorce >= 70 && sorce < 80)
        printf("中等.\n");
    else if (sorce >= 60 && sorce < 70)
        printf("及格.\n");
    else if (sorce >= 0 && sorce < 60)
        printf("不及格.\n");

    return 0;
}
