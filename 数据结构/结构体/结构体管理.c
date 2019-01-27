#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct number
{
    //  int data;
    int cnt;    // 当前数量
    int len;    //总数量
    int *pBase; // 数组首地址
};

void init_arr(struct number *p, int);
bool is_empty(struct number *p); // 判断为空
bool append_arr(struct number *p, int);
bool insert_arr(struct number *p, int, int);
bool del_arr(struct number *p, int);
//int get();
bool is_full(struct number *p);
void sort_arr(struct number *p); // 升序排列
void show_arr(struct number *p);
void inverse_arr(struct number *p); // 倒置

// int main(int argc, char const *argv[])
// {
//     struct number arr;

//     int len = 6;
//     init_arr(&arr, len);
//     append_arr(&arr, 1);
//     append_arr(&arr, 2);
//     append_arr(&arr, 3);
//     append_arr(&arr, 4);
//     append_arr(&arr, 5);
//     //append_arr(&arr, 6);
//     insert_arr(&arr, 3, 99);
//     del_arr(&arr, 3);
//     inverse_arr(&arr);
//     show_arr(&arr);
//     sort_arr(&arr);
//     show_arr(&arr);
//     return 0;
// }
int main(int argc, char const *argv[])
{
    int n, i;
    struct number ar;
    struct number *arr = &ar;
    arr->pBase = NULL;
start:
    printf("\t\t结构体管理v1.1\n");
    printf("1.建立数组\n");
    printf("2.插入元素\n");
    printf("3.删除元素\n");
    printf("4.倒置数组\n");
    printf("5.排序数组\n");
    scanf("%d", &n);
    putchar('\n');
    switch (n)
    {
    case 1:
    A:
        printf("数组长度为:");
        scanf("%d", &i);
        init_arr(arr, i);

        if (NULL != arr->pBase)
        {
            printf("输入元素值\n");
            int val;
            for (int j = 0; j < i; j++)
            {
                scanf("%d", &val);
                append_arr(arr, val);
            }
            show_arr(arr);
            goto start;
        }
        else
        {
            printf("失败\n");
            exit(-1);
        }
        break;
    case 2:

        if (NULL == arr->pBase)
        {
            printf("请先建立数组\n");
            goto A;
        }

        else
        {
            printf("输入位置和插入的值\n");
            int val, pos;
            scanf("%d %d", &pos, &val);
            insert_arr(arr, pos, val);
            show_arr(arr);
            goto start;
        }
        break;
    case 3:
        if (NULL == arr->pBase)
        {
            printf("请先建立数组\n");
            goto A;
        }

        else
        {
            printf("输入位置\n");
            int pos;
            scanf("%d", &pos);
            del_arr(arr, pos);
            show_arr(arr);
            goto start;
        }
        break;
    case 4:
        if (NULL == arr->pBase)
        {
            printf("请先建立数组\n");
            goto A;
        }

        else
        {
            inverse_arr(arr);
            show_arr(arr);
            goto start;
        }
    case 5:
        if (NULL == arr->pBase)
        {
            printf("请先建立数组\n");
            goto A;
        }

        else
        {
            sort_arr(arr);
            show_arr(arr);
            goto start;
        }
    }

    return 0;
}

bool is_empty(struct number *p)
{

    if (p->cnt == 0)
    {
        // printf("数组为空\n");
        return true;
    }
    else
        return false;
}
bool is_full(struct number *p)
{

    if (p->len == p->cnt)
    {
        return true;
    }

    else
    {
        return false;
    }
}
void init_arr(struct number *p, int len)
{
    p->pBase = (int *)malloc(sizeof(int) * len);

    if (NULL == p->pBase)
    {
        printf("分配失败\n");
        exit(-1); // 意外终止
    }
    else
    {
        p->len = len;
        p->cnt = 0;
    }
}
bool append_arr(struct number *p, int val)
{

    if (is_full(p))
    {
        return false;
    }

    p->pBase[p->cnt] = val;
    p->cnt++;
    return true;
}
bool insert_arr(struct number *p, int pos, int val)
{

    if (is_full(p))
    {
        return false;
    }

    if (pos < 1 || pos > p->len)
    {
        return false;
    }

    for (int i = p->cnt - 1; i >= pos - 1; i--)
    {
        p->pBase[i + 1] = p->pBase[i];
    }
    p->pBase[pos - 1] = val;
    p->cnt++;
    return true;
}
void show_arr(struct number *p)
{

    if (is_empty(p))
    {
        printf("数组为空\n");
    }

    else
    {
        printf("元素有: ");
        for (int i = 0; i < p->cnt; i++)
        {
            printf("%d  ", p->pBase[i]);
        }
    }
    putchar('\n');
}
bool del_arr(struct number *p, int pos)
{

    if (pos > p->cnt)
    {
        printf("删除失败\n");
        return false;
    }

    for (int i = pos - 1; i < p->cnt - 1; i++)
    {
        p->pBase[i] = p->pBase[i + 1];
    }
    p->cnt--; // 删了之后要 个数减1
    return true;
}
void inverse_arr(struct number *p)
{
    int t;
    int i = 0, j = p->cnt - 1;

    while (i < j)
    {
        t = p->pBase[i];
        p->pBase[i] = p->pBase[j];
        p->pBase[j] = t;
        i++;
        j--;
    }
}

void sort_arr(struct number *p)
{
    int i, j, t;

    for (i = 0; i <= p->cnt - 1; i++)
    {

        for (j = i + 1; j <= p->cnt - 1; j++)
        {

            if (p->pBase[i] > p->pBase[j])
            {
                t = p->pBase[i];
                p->pBase[i] = p->pBase[j];
                p->pBase[j] = t;
            }
        }
    }
}