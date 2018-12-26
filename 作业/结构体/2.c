#include <stdio.h>
struct STUDENT
{
    char name[16];
    int math;
    int english;
    int computer;
    int average;
};
void GetAverage(struct STUDENT *pst) /* 计算平均成绩 */
{
    int sum = 0;
    sum = pst->computer+pst->english+pst->math;
    pst->average = sum / 3;
}
int main()
{
    int i;
    struct STUDENT st[4] = {{"Jessica", 98, 95, 90}, {"Mike", 80, 80, 90}, {"Linda", 87, 76, 70}, {"Peter", 90, 100, 99}};
    for (i = 0; i < 4; i++)
    {
        GetAverage(st+i);
    }
    printf("Name\tMath\tEnglish\tCompu\tAverage\n");
    for (i = 0; i < 4; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\n", st[i].name, st[i].math, st[i].english,
               st[i].computer, st[i].average);
    }
    return 0;
}
