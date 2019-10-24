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
void delete_list(PNODE pHead, int pos);
void sort_list(PNODE pHead);
PNODE merge_list(PNODE pHead1, PNODE pHead2);
void insert_list(PNODE pHead, int val);
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
    printf("你要删除的下标: (0-%d) ", len - 1);
    int del;
    scanf("%d", &del);
    delete_list(pHead, del);
    traverse_list(pHead);
    PNODE pNew = merge_list(pHead, pHead); // 这里没有使用排序, 同时对同一个链表进行了合并

    sort_list(pNew); // 排序
    traverse_list(pNew);

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

void delete_list(PNODE pHead, int pos)
{

    if (is_empty(pHead))
    {
        printf("链表为空\n");
        return;
    }
    PNODE p = pHead->pNext;
    PNODE pBefore = pHead;
    int len = length_list(pHead);
    if (pos >= len || pos < 0)
    {
        printf("位置有误\n");
        return;
    }
    for (int i = 0; i < pos; i++)
    {
        pBefore = pBefore->pNext;
        p = p->pNext;
    }
    PNODE temp = p;
    pBefore->pNext = p->pNext;
    free(p);
    return;
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
// 合并
// 排序可以用 sort_list()
PNODE merge_list(PNODE pHead1, PNODE pHead2)
{
    int len1 = length_list(pHead1);
    int len2 = length_list(pHead2);
    int len = len1 + len2;
    PNODE pHead = (PNODE)malloc(len * sizeof(NODE));

    if (NULL == pHead)
        exit(1);
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    PNODE pd1 = pHead1->pNext;
    PNODE pd2 = pHead2->pNext;
    for (int i = 0; i < len1; i++)
    {

        PNODE pNew = (PNODE)malloc(sizeof(NODE));

        if (NULL == pNew)
        {
            exit(1);
        }

        pNew->data = pd1->data;
        pd1 = pd1->pNext;
        // pHead->pNext = pNew ;
        // pNew->pNext = NULL ;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }

    for (int i = len1; i < len; i++)
    {

        PNODE pNew = (PNODE)malloc(sizeof(NODE));

        if (NULL == pNew)
        {
            exit(1);
        }

        pNew->data = pd2->data;
        pd2 = pd2->pNext;
        // pHead->pNext = pNew ;
        // pNew->pNext = NULL ;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}

void insert_list(PNODE pHead, int val)
{
    if (is_empty(pHead))
    {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        pNew->data = val;
        pNew->pNext = NULL;
        pHead->pNext = pNew;

        return;
    }
    PNODE p = pHead->pNext;
    // PNODE r = NULL;
    while (NULL != p)
    {
        if (p->pNext != NULL)
        {
            if (p->data <= val && p->pNext->data > val)
            {

                PNODE pNew = (PNODE)malloc(sizeof(NODE));
                pNew->data = val;
                pNew->pNext = p->pNext;
                p->pNext = pNew;
                break;
            }
        }
        else
        {
            if (p->data <= val)
            {
                PNODE pNew = (PNODE)malloc(sizeof(NODE));
                pNew->data = val;
                pNew->pNext = NULL;
                p->pNext = pNew;

                break;
            }
        }
        p = p->pNext;
    }
}