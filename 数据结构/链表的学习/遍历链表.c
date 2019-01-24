#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE; // NODE  等价于 struct Node ,PNODE 等价于 struct Node *

PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
void sort_list(PNODE pHead);

int main(int argc, char const *argv[])
{
    PNODE pHead = NULL; // 等价于 struct Node * pHead = NULL ;

    pHead = create_list();
    traverse_list(pHead);

    if (is_empty(pHead))
    {
        printf("链表为空\n");
    }
    int len = length_list(pHead);
    printf("个数为: %d\n", len);
    sort_list(pHead);
    traverse_list(pHead);
    return 0;
}

PNODE create_list(void)
{
    int len;
    int i, val;
    // 分配了一个不存放有效数据的头结点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (NULL == pHead)
        exit(1);
    PNODE pTail = pHead;
    pTail->pNext = NULL;

    printf("请输入你要生成链表节点的个数: ");
    scanf("%d", &len);

    for (i = 0; i < len; i++)
    {
        printf("请输入第%d个节点的值: ", i + 1);
        scanf("%d", &val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));

        if (NULL == pNew)
        {
            exit(1);
        }

        pNew->data = val;
        // pHead->pNext = pNew ;
        // pNew->pNext = NULL ;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while (NULL != p)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    putchar('\n');
}

bool is_empty(PNODE pHead)
{

    if (NULL == pHead->pNext)
    {
        return true;
    }
    return false;
}
int length_list(PNODE pHead)
{
    int len;
    PNODE p = pHead->pNext;
    len = 0;
    while (NULL != p)
    {
        len++;
        p = p->pNext;
    }

    return len;
}

void sort_list(PNODE pHead)
{
    int i, j, t;
    PNODE p, q;
    int len = length_list(pHead);

    for (i = 0, p = pHead->pNext; i < len - 1; i++, p = p->pNext)
    {

        for (j = i + 1, q = p->pNext; j < len; j++, q = q->pNext)
        {

            if (p->data > q->data)
            {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
}