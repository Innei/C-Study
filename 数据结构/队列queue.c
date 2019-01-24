#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue
{
    int *pBase;
    int front;
    int rear;
} QUEUE;

void init(QUEUE *pQ)
{
    pQ->pBase = (int *)malloc(sizeof(int) * 6);
    pQ->front = 0;
    pQ->rear = 0;
}
bool full_queue(QUEUE *pQ)
{

    if ((pQ->rear + 1) % 6 == pQ->front)
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
    pQ->rear = (pQ->rear + 1) % 6; // 长度
    return true;
}
void traverse_queue(QUEUE *pQ)
{
    
}

int main(int argc, char const *argv[])
{
    QUEUE Q;

    init(&Q);

    return 0;
}
