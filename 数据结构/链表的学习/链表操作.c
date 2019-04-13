#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE; // NODE  等价于 struct Node ,PNODE 等价于 struct Node *

PNODE mycreate(void);
void myprint(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
void mydelete(PNODE pHead, int val);
void myinsert(PNODE pHead, int val);
int before_val = 0;
int main(int argc, char const *argv[])
{
    PNODE pHead = NULL; // 等价于 struct Node * pHead = NULL ;

    pHead = mycreate();
    myprint(pHead);

    if (is_empty(pHead))
    {
        printf("链表为空\n");
    }
    int len = length_list(pHead);
    printf("个数为: %d\n", len);

    myprint(pHead);

    mydelete(pHead, 1);
    if (is_empty(pHead))
    {
        printf("链表为空\n");
    }
    len = length_list(pHead);
    printf("个数为: %d\n", len);

    myprint(pHead);

    myinsert(pHead, 4);
    len = length_list(pHead);
    printf("个数为: %d\n", len);

    myprint(pHead);
    return 0;
}

PNODE mycreate(void)
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
    s:
        printf("请输入第%d个节点的值: ", i + 1);
        scanf("%d", &val);
        if (i == 0)
        {
            before_val = val;
        }
        if (i != 0 && val < before_val)
        {
            printf("输入有误!\n");
            goto s;
        }
        else
        {
            before_val = val;
        }

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

void myprint(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while (NULL != p)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    putchar('\n');
}

void mydelete(PNODE pHead, int val)
{
    if (is_empty(pHead))
    {
        printf("链表为空\n");
        return;
    }
    PNODE p = pHead->pNext;
    PNODE r = pHead;
    while (NULL != p)
    {
        if (p->data == val)
        {

            r->pNext = p->pNext;
            free(p);
            p = NULL;
            break;
        }
        r = r->pNext;
        p = p->pNext;
    }
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
void myinsert(PNODE pHead, int val)
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