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

void init_arr(struct number *, int);
bool is_empty(struct number *p); // 判断为空
bool append_arr();
bool insert_arr();
bool del_arr();
int get();
bool is_full();
void sort_arr();
void show_arr();
void inverse_arr(); // 倒置

int main(int argc, char const *argv[])
{
    struct number arr;

    int len = 6;
    init_arr(&arr, len);
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 5);
    //append_arr(&arr, 6);
    insert_arr(&arr, 3, 99);
    del_arr(&arr, 3);
    show_arr(&arr);
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
        return false;
    }

    for (int i = pos - 1; i < p->cnt - 1; i++)
    {
        p->pBase[i] = p->pBase[i + 1];
    }
    p->cnt--;  // 删了之后要 个数减1
    return true;
}