#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#define OK 1
#define ERROR 0
typedef int Status;
typedef int QElemType;
#define MAXQSIZE 100 /*最大队列长度*/
typedef struct
{
  QElemType data[MAXQSIZE];
  int front; /* 头指针，若队列不空，指向队列头元素*/
  int rear;  /* 尾指针，若队列不空，指向队列尾元素 的下一个位置*/
} SqQueue;
Status InitQueue(SqQueue *Q)
{
  /* 构造一个空队列Q*/
  Q->front = Q->rear = 0;
  return OK;
}

Status QueueEmpty(SqQueue *Q)
{ /*判空*/
  if (Q->rear == Q->front)
  {
    return 1;
  }

  return 0;
}
Status QueueFull(SqQueue *Q)
{ /*判满*/
  if ((Q->rear + 1) % MAXQSIZE == Q->front)
  {
    return 1;
  }

  return (0);
}

Status EnQueue(SqQueue *Q, QElemType e)
{ /* 插入元素e为Q的新的队尾元素*/
  if (QueueFull(Q))
    return 0;
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear + 1) % MAXQSIZE; // 长度
  return 1;
}

Status DeQueue(SqQueue *Q, QElemType *e)
{ /* 若队列不空，则删除Q的队头元素，
   用e返回其值，并返回OK;  否则返回ERROR*/

  if (QueueEmpty(Q))
  {
    return 0;
  }
  *e = Q->data[Q->front];
  Q->front = (Q->front + 1) % MAXQSIZE;

  return 1;
}
void ClearQueue(SqQueue *Q)
{ /*清空队列*/
  Q->rear = Q->front = 0;
}

Status CreateQueue(SqQueue *Q, int n)
{
  /* 创建n个元素的队列Q*/
  int i;
  QElemType x;
  for (i = 1; i <= n; i++)

  {
    scanf("%d", &x);
    if (!EnQueue(Q, x))
      return ERROR;
  }
  return OK;
}

Status QueueTraverse(SqQueue Q)
{
  int index;
  index = Q.front;
  printf("\n");
  while ((index) % MAXQSIZE != Q.rear)
    printf("%d  ", Q.data[index++]);
}

int main()
{
  int n, e;
  SqQueue Q;
  InitQueue(&Q);
  scanf("%d", &n);
  CreateQueue(&Q, n);
  QueueTraverse(Q);
  EnQueue(&Q, 30);
  QueueTraverse(Q);
  DeQueue(&Q, &e);
  QueueTraverse(Q);
  printf("\ne=%d\n", e);
}