/*
患者医院看病过程：先排队等候，再看病治疗。在排队的过程中主要重复做两件事情，一是患者到达诊室时，将病历交给护士，排到等候队列中候诊；
二是护士从等候队列中取出下一个患者的病历，该患者进入诊室看病。 
按照“先到先服务”的原则，设计一个算法模拟病人等候就诊的过程。
其中“病人到达”用命令a表示，“护士让下一位患者就诊”用命令n表示，“不再接受病人排队”用命令q表示。
*/
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

void SeeDoctor(QUEUE *Q)
{
  int n;
  int flag = 1;
  while (flag)
  {
    char ch = getchar();
    switch (ch)
    {
    case 'a':
      printf("病历号: \n");
      scanf("%d", &n);
      en_queue(Q, n);
      break;
    case 'n':
      if (!empty_queue(Q))
      {
        out_queue(Q, &n);
        printf("请 %d 的病人就诊\n", n);
      }
      else
      {
        printf("无病人等待就诊\n");
      }
      break;
    case 'q':
      printf("停止挂号, 下列病人依次就诊:\n");
      while (!empty_queue(Q))
      {
        out_queue(Q, &n);
        printf("请 %d 的病人就诊\n", n);
      }
      flag = 0;
      break;
    default:
      printf("无效命令\n");
      break;
    }
    getchar();
  }
}

int main(int argc, char const *argv[])
{
  QUEUE Q;
  init(&Q);
  SeeDoctor(&Q);
  return 0;
}
