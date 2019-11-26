
#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>
#define MAXSIZE 10
#define MaxSize 100
#define OK 1
#define ERROR 0
typedef int Status;
typedef int TElemType;

typedef struct BiTNode
{ /* 结点结构*/
  TElemType data;
  struct BiTNode *lchild, *rchild; /* 左右孩子指针*/
} BiTNode, *BiTree, *SElemType;

typedef struct
{
  SElemType elem[MaxSize];
  int top; /*栈顶元素的下标，栈空时为-1*/
} SqStack;

typedef struct List
{
  int pBase[30];
  int length;
} List, *pList;

void initList(pList p)
{
  p->length = 0;
}

void printList(pList p)
{
  for (int i = 0; i < p->length; i++)
  {
    printf("%d  ", p->pBase[i]);
  }
  return;
}
Status InitStack(SqStack *s) /*栈的初始化*/
{
  s->top = -1;
  return OK;
} /*InitStack;*/

void ClearStack(SqStack *s) /*把S置为空栈*/
{
  s->top = -1;
}

Status StackEmpty(SqStack s) /*判断S是否为空栈*/
{
  return (s.top == -1);
}

SElemType GetTop(SqStack s) /*取栈顶元素*/
{
  return (s.elem[s.top]);
} /*GetTop*/

Status Push(SqStack *s, SElemType e) /*压栈操作*/
{
  if (s->top >= MaxSize - 1)
    return ERROR; /*栈满时不再入栈*/
  s->elem[++s->top] = e;
  return OK;
}

Status Pop(SqStack *s, SElemType *e) /*出栈操作*/
{
  if (s->top == -1)
    return ERROR; /*空栈*/
  *e = s->elem[s->top--];
  return OK;
} /*Pop*/

Status in(SqStack s, SElemType e) /*判断e是否在栈s中*/
{
  int i;
  if (StackEmpty(s))
    return 0;
  for (i = 1; i <= s.top; i++)
    if (s.elem[i] == e)
      return 1;
  return 0;
}
typedef struct Queue
{
  struct BiTNode *pBase;
  int front;
  int rear;
} QUEUE;

void init(QUEUE *pQ)
{
  pQ->pBase = malloc(sizeof(struct BiTNode) * MAXSIZE);
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
bool en_queue(QUEUE *pQ, struct BiTNode val)
{
  if (full_queue(pQ))
    return false;
  pQ->pBase[pQ->rear] = val;
  pQ->rear = (pQ->rear + 1) % MAXSIZE; // 长度
  return true;
}

bool empty_queue(QUEUE *pQ)
{

  if (pQ->front == pQ->rear)
  {
    return true;
  }
  return false;
}
bool out_queue(QUEUE *pQ, struct BiTNode *pVal)
{

  if (empty_queue(pQ))
  {
    return false;
  }
  *pVal = pQ->pBase[pQ->front];

  pQ->front = (pQ->front + 1) % MAXSIZE;

  return true;
}
BiTree CreateBiTree_rc(void) /*用递归的思想来实现*/
{
  /*按先序次序输入二叉树中结点的值(数值),0表示空树*/
  /*构造二叉链表表示的二叉树T*/
  int value;
  BiTree newnode;
  scanf("%d", &value);
  if (value == 0)
    return NULL;
  else
  {
    newnode = (BiTree)malloc(sizeof(BiTNode));
    newnode->data = value;
    newnode->lchild = CreateBiTree_rc();
    newnode->rchild = CreateBiTree_rc();
    return newnode;
  }
}
int FindDepth(BiTree T)
{
  if (!T)
    return 0;
  int a = FindDepth(T->lchild);
  int b = FindDepth(T->rchild);
  return (a > b ? a : b) + 1;
}
void PrintBiTree(BiTree T, int level)
{ /*打印二叉树*/
  if (T == NULL)
  {
    return;
  }

  PrintBiTree(T->rchild, level + 1);
  for (int i = 0; i < level; i++)
    printf("    ");
  printf("%d\n", T->data);

  PrintBiTree(T->lchild, level + 1);
}

void PreOrderTraverse(BiTree T)
{ /*递归前序遍历算法*/
  if (T != NULL)
  {
    printf("%d", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
  }

  return;
}
void InOrderTraverse(BiTree T)
{ /*递归中序遍历算法*/
  if (T != NULL)
  {
    InOrderTraverse(T->lchild);
    printf("%d", T->data);
    InOrderTraverse(T->rchild);
  }

  return;
}

void PostOrderTraverse(BiTree T)
{ /*递归后序遍历算法*/
  if (T != NULL)
  {
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%d", T->data);
  }
  return;
}

void PreOrderTraverse1(BiTree T)
{ /*先序遍历的非递归算法*/
  SqStack s;
  SElemType p;
  InitStack(&s);
  p = T;
  while (p || !StackEmpty(s))
  {
    if (p)

    {
      printf("%d", p->data);
      Push(&s, p);
      p = p->lchild;
    }
    else

    {
      Pop(&s, &p);
      p = p->rchild;
    }
  }
}

void InOrderTraverse1(BiTree T)
{ /*中序遍历的非递归算法*/
  SqStack s;
  SElemType p;
  InitStack(&s);
  p = T;
  while (p || !StackEmpty(s))
  {
    if (p)

    {
      Push(&s, p);
      p = p->lchild;
    }
    else

    {
      printf("%d", p->data);
      Pop(&s, &p);
      p = p->rchild;
    }
  }
}

void PostOrderTraverse1(BiTree T)
{ /*后序遍历的非递归算法*/
  SqStack s;
  int end = 0;
  SElemType p, q;
  InitStack(&s);
  p = T;
  while (p && end == 0)
  {
    while (p)

    {
      Push(&s, p);
      p = p->lchild;
    }
    q = GetTop(s);
    while ((p == q->rchild || !q->rchild) && end == 0)

    {
      Pop(&s, &p);
      printf("%d  ", p->data);
      if (p == T)
        end = 1;
      else
        q = GetTop(s);
    }
    p = q->rchild;
  }
}

void main()
{
  BiTree Bi = CreateBiTree_rc();
  PrintBiTree(Bi, 0);
  printf("前中后序遍历:\n");
  PreOrderTraverse(Bi);
  printf("\n");
  InOrderTraverse(Bi);
  printf("\n");
  PostOrderTraverse(Bi);
  printf("\n");
}
