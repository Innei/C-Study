#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef struct Queue
{
    int *pBase;
    int front;
    int rear;
} QUEUE;

void init(QUEUE *pQ)
{
    pQ->pBase = (int *)malloc(sizeof(int) * MAXSIZE);
    pQ->front = 0;
    pQ->rear = 0;
}
bool full_queue(QUEUE *pQ)
{

    if ((pQ->rear + 1) % MAXSIZE == pQ->front)
    {
        return true;
    }
    return false;
}
bool en_queue(QUEUE *pQ, int val)
{
    if (full_queue(pQ))
        return false;
    pQ->pBase[pQ->rear] = val;
    pQ->rear = (pQ->rear + 1) % MAXSIZE; // 长度
    return true;
}
void traverse_queue(QUEUE *pQ)
{
    int i = pQ->front;

    while (i != pQ->rear)
    {
        printf("%d ", pQ->pBase[i]);
        i = (i + 1) % MAXSIZE;
    }
    putchar('\n');
    return;
}
bool empty_queue(QUEUE *pQ)
{

    if (pQ->front == pQ->rear)
    {
        return true;
    }
    return false;
}
bool out_queue(QUEUE *pQ, int *pVal)
{
    

    if (empty_queue(pQ))
    {
        return false;
    }
    *pVal = pQ->pBase[pQ->front];
   
    pQ->front = (pQ->front + 1) % MAXSIZE;
    
    return true;
}
int main(int argc, char const *argv[])
{
    QUEUE Q;
    int Val;
    init(&Q);
    en_queue(&Q, 1);
    traverse_queue(&Q);
    en_queue(&Q, 2);
    traverse_queue(&Q);
    en_queue(&Q, 3);
    traverse_queue(&Q);
    en_queue(&Q, 4);
    traverse_queue(&Q);
    en_queue(&Q, 5);
    traverse_queue(&Q);
    en_queue(&Q, 6);
    traverse_queue(&Q);
    en_queue(&Q, 7);
    traverse_queue(&Q);
    en_queue(&Q, 8);
    traverse_queue(&Q);

    if (out_queue(&Q, &Val))
    {
        printf("出队成功, %d\n", Val);
    }

    else
    {
        printf("失败\n");
    }
    traverse_queue(&Q);
    return 0;
}
