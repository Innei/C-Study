#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>

struct Node
{
    int data;
    struct Node *pNext; //指针域
};

struct Node *CreateList(void)
{
    int len;
    int i;
    int val;

    struct Node *pHead = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == pHead)
    {
        printf("分配失败,程序终止\n");
        exit(1); 
    }
    struct Node *pTail = pHead;
    pTail->pNext = NULL;

    printf("请输入生成的链表节点的个数: ");
    scanf("%d", &len);

    for (i = 0; i < len; i++)
    {
        printf("请输入第%d个节点的值: ", i + 1);
        scanf("%d", &val);

        struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));

        if (NULL == pNew)
        {
            printf("分配失败,程序终止\n");
            exit(1);
        }
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}

// bool empty_list(struct Node *p)
// {

//     if (p->pNext == NULL)
//     {
//         return true;
//     }

//     else
//     {
//         return false;
//     }
// }
void TraverseList(struct Node *pHead)
{

    // if (empty_list(p))
    // {
    //     printf("链表为空\n");
    // }

    // else
    // {

    //     while (p != NULL)
    //     {
    //         printf("%4d", p->data);
    //         p = p->pNext;
    //     }
    // }
    // printf("\n");
    struct Node *p = pHead->pNext;

    while (NULL != p)
    {
        printf("%4d", p->data);
        p = p->pNext;
    }
    return;
}
int main(int argc, char const *argv[])
{
    struct Node *pHead;

    pHead = CreateList();
    TraverseList(pHead);

    return 0;
}
