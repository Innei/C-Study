//有n个人围成一圈，按顺序从1到n编号。
//从第一个人开始报数，报数3的人退出圈子，下一个人从1开始重新报数，
//报数3的人退出圈子。如此循环，直到留下最后一个人。问留下来的人的编号。
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int date;
    struct Node *next;
} Node, *LinkList;

LinkList createlist(int n)
{
    int i;
    LinkList head, pre, p;
    head = pre = (LinkList)malloc(sizeof(Node));
    head->date = 1;
    for (i = 2; i <= n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->date = i;
        pre->next = p;
        pre = p;
    }
    pre->next = head;
    return head;
}
void out_circle(LinkList head)
{
    int n;
    LinkList pre, p;
    p = head;
    n = 1;
    while (p->next != p)
    {
        pre = p;
        p = p->next;
        n++;
        if (n == 3)
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
            n = 1;
        }
    }
    printf("最后留下的是第%d位：\n", p->date);
}
int main()
{
    int n;
    LinkList head;
    printf("输入人数：\n");
    scanf("%d", &n);
    head = createlist(n);
    out_circle(head);
    return 0;
}