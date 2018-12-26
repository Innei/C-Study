#include <stdio.h>

typedef struct STU
{
    char name[10];
    int id;
    int score;
} S, *pS;

int main(int argc, char const *argv[])
{
    struct STU *st;
    int n, sum = 0;
    scanf("%d", &n);
    st = (pS)malloc(sizeof(S) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %d", &st[i].id, st[i].name, &st[i].score);
        sum += (st + i)->score;
    }
    printf("%lf", (double)sum / n);

    return 0;
}
