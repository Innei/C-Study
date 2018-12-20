#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE; // NODE  等价于 struct Node ,PNODE 等价于 struct Node *

PNODE create_list(void);
void traverse_list(PNODE pHead);
int main(int argc, char const *argv[])
{
    PNODE pHead = NULL; // 等价于 struct Node * pHead = NULL;

    pHead = create_list();
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
        // pHead->pNext = pNew;
        // pNew->pNext = NULL;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while(NULL != p)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
}