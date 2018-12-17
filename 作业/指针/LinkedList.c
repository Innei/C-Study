#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    struct Node *pNext;
    int data;
}Node;

struct ListNode *CreateList(void)
{
    int len;
    int data;

    struct Node *pHead = NULL;
    pHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    
    if (pHead == NULL) {
        exit(1);
    }
    struct ListNode * pTail = pHead;
    pTail->pNext = NULL;
     printf("请输入节点个数：");
    scanf_s("%d", &len);        //    输入节点个数
     for (int i = 0; i < len; i++) {

        struct Node * pNew = (struct ListNode * )malloc(sizeof(struct ListNode));    //    分配一个新节点
        if (pNew == NULL) {
            printf("分配新节点失败\n");
            exit(-1);
        }
        printf("请输入第 %d 个节点的数据：", i + 1);
        scanf_s("%d", &data);    //    输入链表节点的数据

        pNew->data = data;    //    把数据赋值给节点数据域
        pTail->Next = pNew;    //    末尾节点指针指向下一个新节点
        pNew->Next = NULL;        //    新节点指针指向为空
        PTail = pNew;    //    将新节点复制给末尾节点    
}






int main(int argc, char const *argv[])
{
    
    return 0;
}
