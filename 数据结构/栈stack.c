#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int data;
    struct Node *pNext;
} NODE, *PNODE;

typedef struct stack
{
    PNODE pTop;
    PNODE pBottom;

} STACK, *PSTACK;

void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));

    if (NULL == pS->pTop)
    {
        printf("失败!");
        exit(1);
    }

    else
    {
        pS->pBottom = pS->pTop;
    }
};
void push(PSTACK pS, int val)
{

    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}
void traverse(PSTACK pS)
{
    PNODE p = pS->pTop;
    while (p != pS->pBottom)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}
bool empty(PSTACK pS)
{

    if (pS->pTop == pS->pBottom)
    {

        return true; /* code */
    }
    else
        return false;
}
bool pop(PSTACK pS, int *pVal)
{
    if (empty(pS))
        return false;

    else
    {
        PNODE r = pS->pTop;
        *pVal = r->data;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;
        return true;
    }
}
void clear(PSTACK pS)
{

    if (empty(pS))
    {
        return;
    }

    PNODE p = pS->pTop;
    PNODE q = p->pNext;
    while (p != pS->pBottom)
    {
        q = p->pNext;
        free(p);
        p = q;
    }
    pS->pTop = pS->pBottom;
}
int main(int argc, char const *argv[])
{
    STACK S;
    int val;
    init(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 2);
    push(&S, 4);
    push(&S, 5);
    push(&S, 6);
    push(&S, 7);
    push(&S, 8);
    traverse(&S);

    if (pop(&S, &val))
    {
        printf("Success:%d\n", val);
    }
    traverse(&S);
    clear(&S);
    traverse(&S);
    return 0;
}
