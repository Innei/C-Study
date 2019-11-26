#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MAXNODE 20
#define bool int
#define true 1
#define false 0
#define SIZE 60

void strSort(char string[])
{
  int i, j;
  int n = strlen(string);
  char temp;

  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (string[i] > string[j])
      {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
      }
    }
  }
}
void QuickSort(int *arr, int low, int high)
{
  if (low < high)
  {
    int i = low;
    int j = high;
    int k = arr[low];
    while (i < j)
    {
      while (i < j && arr[j] >= k) // 从右向左找第一个小于k的数
      {
        j--;
      }

      if (i < j)
      {
        arr[i++] = arr[j];
      }

      while (i < j && arr[i] < k) // 从左向右找第一个大于等于k的数
      {
        i++;
      }

      if (i < j)
      {
        arr[j--] = arr[i];
      }
    }

    arr[i] = k;

    // 递归调用
    QuickSort(arr, low, i - 1);  // 排序k左边
    QuickSort(arr, i + 1, high); // 排序k右边
  }
}
typedef struct Queue
{
  int *pBase;
  int front;
  int rear;
} QUEUE;

void init(QUEUE *pQ)
{
  pQ->pBase = (int *)malloc(sizeof(int) * SIZE);
  pQ->front = 0;
  pQ->rear = 0;
}
bool full_queue(QUEUE *pQ)
{

  if ((pQ->rear + 1) % SIZE == pQ->front)
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
  pQ->rear = (pQ->rear + 1) % SIZE; // 长度
  return true;
}
void traverse_queue(QUEUE *pQ)
{
  int i = pQ->front;

  while (i != pQ->rear)
  {
    printf("%d ", pQ->pBase[i]);
    i = (i + 1) % SIZE;
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

  pQ->front = (pQ->front + 1) % SIZE;

  return true;
}

typedef struct
{
  unsigned int weight;
  unsigned int parent, lchild, rchild;
} HTNode, HuffmanTree[MAXNODE + 1]; /*数组存储赫夫曼树，下标从1开始*/

typedef struct
{
  char ch;        /*结点的值（字符）*/
  char code[100]; /*结点的huffman编码*/
} codenode, HuffmanCode[MAXNODE + 1];
/*数组存储赫夫曼编码，下标从1开始*/

void CrtHuffmanTree(HuffmanTree ht, int w[], int n)
{
  QUEUE q;
  int o1, o2;
  int index = 0, child = 0; // index: 当前处理的索引 （0-n） 叶子节点下标 每次父节点安排上了子节点就加了 1  迷之写法
  init(&q);

  QuickSort(w, 0, n - 1);
  //   for (int i = 0; i < n;i ++)
  //  {
  //    printf("%d",w[i]);
  //  }
  for (int i = 0; i < n; i++)
  {
    en_queue(&q, w[i]); // 队列不解释
  }

  for (int i = 0; i < 2 * n - 1; i++)
  {
    ht[i].weight = 0;
    ht[i].parent = -1;
    ht[i].lchild = -1;
    ht[i].rchild = -1;
  }

  for (int i = 0; i < n; i++)
  {
    ht[i].weight = w[i];
  }

  out_queue(&q, &o1);
  // printf("%d", o1);
  out_queue(&q, &o2);

  ht[index + n].weight = o1 + o2;
  ht[index + n].rchild = child++;
  ht[index + n].lchild = child++;
  o2 = ht[index + n].weight;
  ht[index].parent = index + n;
  ht[index + 1].parent = ht[index].parent;
  index++;

  while (!empty_queue(&q))
  {
    out_queue(&q, &o1);
    ht[index + n].weight = o1 + o2;
    ht[index + n].lchild = child;
    ht[index + n].rchild = index + n - 1;
    // o2 = ht[index + n].weight;
    // index++;
    o2 = ht[index + n].weight;
    ht[child].parent = index + n;
    ht[index + n - 1].parent = ht[child++].parent;
    index++;
  }
}

void printhuffmantree(HuffmanTree ht, int n)
{
  int k;
  printf("\n  weight   parent   lchild    rchild");
  for (k = 0; k < 2 * n - 1; k++)
    printf("\n   %d      %d         %d         %d", ht[k].weight, ht[k].parent, ht[k].lchild, ht[k].rchild);
}

void huffmancoding(HuffmanTree ht, HuffmanCode hc, char *c, unsigned int n)
{
  HuffmanTree hts;
  // HuffmanCode hc;
  int index = 0; // 记录当前处理下标
  int gap = n - 2;
  for (int i = 0; i < 2 * n - 1; i++)
  {
    hts[i].weight = 0;
    hts[i].parent = -1;
    hts[i].lchild = -1;
    hts[i].rchild = -1;
  }
  if (ht[0].weight > ht[1].weight)
  {
    hts[0].weight = 1;
    hts[1].weight = 0;
  }
  else
  {
    hts[0].weight = 0;
    hts[1].weight = 1;
  }
  for (int i = 2; i < n; i++)
  {
    if (ht[i].weight > ht[i + gap].weight)
    {
      hts[i].weight = 1;
      hts[i + gap].weight = 0;
    }
    else
    {
      hts[i].weight = 0;
      hts[i + gap].weight = 1;
    }
  }

  // printhuffmantree(hts, 4);
  hc[index].ch = c[index];
  // char *temp = (char *)malloc(sizeof(char) * 10);
  char temp[10] = "";
  // char temp2[10] = "";
  char s[10] = "";
  for (int i = 4; i < 2 * n - 2; i++)
  {
    sprintf(s, "%d", hts[i].weight);
    strcat(temp, s);
  }
  // printf("%s", temp);
  sprintf(s, "%d", hts[index].weight);
  strcat(s, temp);
  puts(s);
  strcpy(hc[index].code, s);
  sprintf(s, "%d", hts[++index].weight);
  hc[index].ch = c[index];
  strcat(s, temp);
  strcpy(hc[index].code, s);
  char temp2[10] = "";
  for (index++; index < n; index++)
  {
    hc[index].ch = c[index];
    strncpy(temp2, temp + 1, strlen(temp));
    sprintf(s, "%d", hts[index].weight);
    strcat(s, temp2);
    strcpy(temp, temp2);
    strcpy(hc[index].code, s);
  }
}

void printhuffmancode(HuffmanCode hc, int n)
{
  int k;
  for (k = 0; k < n; k++)
    printf("\n  %d   %c   %s", k, hc[k].ch, hc[k].code);

  puts("\n");
}

char *encode(char *sourcecode, char *dest, HuffmanCode hc, int n)
{
  char *p, *q;
  int i, j, nofind;
  j = 0;
  p = sourcecode;
  while (*p != '\0')
  {
    nofind = 1;
    for (i = 0; i < n && nofind; i++)
    {
      if (hc[i].ch == *p)
      {
        q = hc[i].code;
        while (*q != '\0')
        {
          dest[j++] = *q++;
          nofind = 0;
        }
        p++;
      }
      dest[j++] = '\0';
    }
  }
  return dest;
}

void decoding(char *sour, char *dest, HuffmanTree ht, HuffmanCode hc, int n)
{
  char *p, *q;
  int f;
  p = sour;
  q = dest;

  while (*q != '\0')
  {
    f = 2 * n - 1;
    while (ht[f].lchild != 0 && ht[f].rchild != 0 && *q != '\0')
    {
      if (*q == '\0')
      {
        f = ht[f].lchild;
      }
      else
        f = ht[f].rchild;
      q++;
    }
    *p++ = hc[f].ch;
  }
  *p++ = '\0';
}

int main(int argc, char const *argv[])
{
  HuffmanTree ht;
  int w[4] = {1, 3, 5, 5};
  CrtHuffmanTree(ht, w, 4);
  // printhuffmantree(ht, 4);
  HuffmanCode hc;
  huffmancoding(ht, hc, "ABCD", 4);
  printhuffmancode(hc, 4);
  // char dest[100];
  // printf("%s", encode("ABCCA", dest, hc, 4));

  return 0;
}
