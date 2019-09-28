#include "stdio.h"
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

/*算法1：栈的初始化*/
Status InitStack(SqStack *s)
{
    s->top = -1;
    return OK;
} /*InitStack;*/

/*算法2：把S置为空栈*/
void ClearStack(SqStack *s)
{
    s->top = -1;
}

/*算法3：判断S是否为空栈*/
Status StackEmpty(SqStack *s)
{
    if (s->top == -1)
    {
        return 1;
    }

    return 0;
}

/*算法4：取栈顶元素*/
SElemType GetTop(SqStack *s)
{
    if (StackEmpty(s))
    {
        return 0;
    }
    else
        return s->data[s->top];
} /*GetTop*/

/*算法5：压栈操作*/
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

/*算法6：弹栈操作*/
Status Pop(SqStack *s, SElemType *x)
{
    if (!StackEmpty(s))
    {
        *x = s->data[s->top];
        --s->top;
        return 1;
    }
    return 0;

} /*Pop*/

int main(int argc, char const *argv[])
{

    SqStack sq;
    InitStack(&sq);
    printf("入栈 1 2 3 4\n");
    Push(&sq, '1');
    Push(&sq, '2');
    Push(&sq, '3');
    Push(&sq, '4');
    for (int i = 0; i <= sq.top; i++)
    {
        printf("%c\t", sq.data[i]);
    }
    char popElem;
    char *pop = &popElem;
    Pop(&sq, pop);
    printf("出栈元素: %c\n", popElem);
    return 0;
}
