#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#define OK 1
#define ERROR 0
typedef int Status;
typedef int QElemType;
typedef struct QNode
{ /* 结点类型*/
  QElemType data;
  struct QNode *next;
} QNode, *QueuePtr;
typedef struct
{                 /* 链队列类型*/
  QueuePtr front; /* 队头指针*/
  QueuePtr rear;  /* 队尾指针*/
} LinkQueue;

Status InitQueue(LinkQueue *Q)
{
  /* 构造一个空队列Q*/
  QueuePtr p;
  p = (QueuePtr)malloc(sizeof(QNode));
  if (!p)
    exit(OVERFLOW);
  /*存储分配失败*/
  p->next = NULL;
  Q->front = p;
  Q->rear = p;
  return OK;
}
Status CreateQueue(LinkQueue *Q, int n)
{
  /* 创建n个元素的队列Q*/
  QueuePtr newnode;
  int i;
  for (i = 1; i <= n; i++)
  {
    newnode = (QueuePtr)malloc(sizeof(QNode));
    if (!newnode)
      exit(OVERFLOW);
    /*存储分配失败*/
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    Q->rear->next = newnode;
    Q->rear = newnode;
  }
  return OK;
}
Status EnQueue(LinkQueue *Q, QElemType e)
{
  /* 插入元素e为Q的新的队尾元素*/
  QueuePtr newNode = (QueuePtr)malloc(sizeof(QNode));
  if (!newNode)
  {
    return ERROR;
  }

  newNode->data = e;
  newNode->next = NULL;
  Q->rear->next = newNode;
  Q->rear = newNode;
  return OK;
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{
  /* 若队列不空，则删除Q的队头元素，
 用 e 返回其值，并返回OK；否则返回ERROR*/
  if (!Q->front->next && !Q->rear->next)
  {
    return 0;
  }
  *e = Q->front->next->data;
  QueuePtr temp = Q->front->next;
  if (!Q->front->next->next)
  {
    Q->front = Q->rear;
    return OK;
  }

  Q->front->next = Q->front->next->next;
  free(temp);
  return OK;
}

Status QueueTraverse(LinkQueue Q)
{
  QueuePtr p;
  p = Q.front;
  printf("\n");
  while (p != Q.rear)
  {
    printf("%d   ", p->next->data);
    p = p->next;
  }
}

int main()
{
  int n, e;
  LinkQueue Q;
  InitQueue(&Q);
  printf("input n=?");
  scanf("%d", &n);
  CreateQueue(&Q, n);
  QueueTraverse(Q);
  EnQueue(&Q, 30);
  QueueTraverse(Q);
  DeQueue(&Q, &e);
  QueueTraverse(Q);
  printf("\ne=%d\n", e);
  return 0;
}
