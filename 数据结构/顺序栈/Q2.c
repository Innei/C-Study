#include "stdio.h"
#include "string.h"
#define MaxSize 100
#define OK 1
#define ERROR 0
typedef char SElemType;
typedef int Status;
typedef struct
{
  SElemType data[MaxSize];
  int top; /*栈顶元素的下标，栈空时为-1*/
} SqStack;

Status InitStack(SqStack *s)
{
  s->top = -1;
  return OK;
}

Status StackEmpty(SqStack *s)
{
  if (s->top == -1)
  {
    return 1;
  }

  return 0;
}

SElemType GetTop(SqStack *s)
{
  if (StackEmpty(s))
  {
    return 0;
  }
  else
    return s->data[s->top];
}

Status Push(SqStack *s, SElemType e)
{
  if (s->top >= MaxSize - 1)
  {
    return 0;
  }
  else
  {
    s->data[++s->top] = e;
  }
  return 1;
}

Status Pop(SqStack *s, SElemType *x)
{
  if (!StackEmpty(s))
  {
    *x = s->data[s->top];
    --s->top;
    return 1;
  }
  return 0;
}
Status In(char ch, char set[]) /*判断字符ch是否在集合set中，在返回1，不在返回0*/
{
  for (int i = 0; i < strlen(set); i++)
  {
    if (ch == set[i])
    {
      return 1;
    }
  }
  return 0;
}

char precede(char ch1, char ch2)
/*判断字符ch1和字符ch2的优先级，返回> 、= 或 <，具体见下表*/
{
  char ch;
  ch = '>';
  switch (ch1)
  {
  case '+':
    if (ch2 == '*' || ch2 == '/' || ch2 == '(')
      ch = '<';
    break;
  case '-':
    if (ch2 == '*' || ch2 == '/' || ch2 == '(')
      ch = '<';
    break;
  case '*':
  case '/':
    if (ch2 == '(')
      ch = '<';
    break;
  case '(':
    ch = '<';
    if (ch2 == ')')
      ch = '=';
    if (ch2 == '#')
      ch = '\0';
    break;
  case ')':
    if (ch2 == '(')
      ch = '\0';
    break;
  case '#':
    ch = '<';
    if (ch2 == ')')
      ch = '\0';
    if (ch2 == '#')
      ch = '=';
    break;
  }
  return ch;
}

char Operate(char a, char theta, char b)
/*本函数仅能进行一位数的运算,且运算的结果不能超过一位*/
{
  char ch;
  switch (theta)
  {
  case '+':
    ch = (a - 48) + (b - 48) + 48;
    break;
  case '-':
    ch = (a - 48) - (b - 48) + 48;
    break;
  case '*':
    ch = (a - 48) * (b - 48) + 48;
    break;
  case '/':
    ch = (a - 48) / (b - 48) + 48;
    break;
  }
  return (ch);
}
char EvaluateExperssion()
{ /*算术表达式求值的算符优先算法.设OPTR和OPND分别为运算符栈和运算数栈，*/
  /*OP为运算符集合{+,-,*,/,(,),#}*/
  char c, theta, a, b, x;

  static char op[8] = {'+', '-', '*', '/', '(', ')', '#'};
  SqStack OPTR, OPND;
  InitStack(&OPTR);
  Push(&OPTR, '#');
  InitStack(&OPND);
  c = getchar();
  while (c != '#' || GetTop(&OPTR) != '#')
  {
    if (!In(c, op))
    {
      Push(&OPND, c);
      c = getchar();
    }
    /*不是运算符则进操作数OPND栈*/
    else
      switch (precede(GetTop(&OPTR), c))
      {
      case '<': /*若OPTR栈顶运算符的优先级比当前读入的运算符低*/
        Push(&OPTR, c);
        c = getchar();
        break;
      case '=': /*若OPTR栈顶运算符的优先级比当前读入的运算符相同*/

        Pop(&OPTR, &x);
        c = getchar();
        break;
      case '>': /*若OPTR栈顶运算符的优先级比当前读入的运算符高*/
        Pop(&OPTR, &theta);
        Pop(&OPND, &b);
        Pop(&OPND, &a);
        Push(&OPND, Operate(a, theta, b));

        break;

      default:
        break;
      } // precede函数的值见课件
  }
  return GetTop(&OPND);
}

int main()
{
  printf("%d", EvaluateExperssion() - 48);
  return 0;
}
