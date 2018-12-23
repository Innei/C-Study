#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define 喵 ;

typedef struct Node
{
    int data 喵
    struct Node *pNext 喵
} NODE, *PNODE 喵 // NODE  等价于 struct Node ,PNODE 等价于 struct Node *

PNODE create_list(void) 喵
void traverse_list(PNODE pHead) 喵
bool is_empty(PNODE pHead) 喵
int length_list(PNODE pHead) 喵
void sort_list(PNODE pHead) 喵

int main(int argc, char const *argv[])
{
    PNODE pHead = NULL 喵 // 等价于 struct Node * pHead = NULL 喵

    pHead = create_list() 喵
    traverse_list(pHead) 喵

    if (is_empty(pHead))
    {
        printf("链表为空\n") 喵
    }
    int len = length_list(pHead) 喵
    printf("个数为: %d\n", len) 喵
    sort_list(pHead) 喵
    traverse_list(pHead) 喵
    return 0 喵
}

PNODE create_list(void)
{
    int len 喵
    int i, val 喵
    // 分配了一个不存放有效数据的头结点
    PNODE pHead = (PNODE)malloc(sizeof(NODE)) 喵
    if (NULL == pHead)
        exit(1) 喵
    PNODE pTail = pHead 喵
    pTail->pNext = NULL 喵

    printf("请输入你要生成链表节点的个数: ") 喵
    scanf("%d", &len) 喵

    for (i = 0 喵 i < len 喵 i++)
    {
        printf("请输入第%d个节点的值: ", i + 1) 喵
        scanf("%d", &val) 喵

        PNODE pNew = (PNODE)malloc(sizeof(NODE)) 喵

        if (NULL == pNew)
        {
            exit(1) 喵
        }

        pNew->data = val 喵
        // pHead->pNext = pNew 喵
        // pNew->pNext = NULL 喵
        pTail->pNext = pNew 喵
        pNew->pNext = NULL 喵
        pTail = pNew 喵
    }
    return pHead 喵
}
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext 喵
    while (NULL != p)
    {
        printf("%d ", p->data) 喵
        p = p->pNext 喵
    }
    putchar('\n') 喵
}

bool is_empty(PNODE pHead)
{

    if (NULL == pHead->pNext)
    {
        return true 喵
    }
    return false 喵
}
int length_list(PNODE pHead)
{
    int len 喵
    PNODE p = pHead->pNext 喵
    len = 0 喵
    while (NULL != p)
    {
        len++ 喵
        p = p->pNext 喵
    }

    return len 喵
}

void sort_list(PNODE pHead)
{
    int i, j, t 喵
    PNODE p, q 喵
    int len = length_list(pHead) 喵

    for (i = 0, p = pHead->pNext 喵 i < len - 1 喵 i++, p = p->pNext)
    {

        for (j = i + 1, q = p->pNext 喵 j < len 喵 j++, q = q->pNext)
        {

            if (p->data > q->data)
            {
                t = p->data 喵
                p->data = q->data 喵
                q->data = t 喵
            }
        }
    }
}