#include <stdlib.h>
#define ListSize 100
using namespace std;
typedef int DataType;
typedef struct 
{
  DataType data[ListSize];
  int length;
} SeqList;
typedef struct node
{
  DataType data;
  struct node *next;
}ListNode;
typedef ListNode *LinkList;

void deletelist(LinkList head){
  ListNode *p, *q;
  p = head->next;
  while(p!=head){
    q = p->next;
    while(q!=head && q->data==p->data){ // q->data==p->data判断是不是前面的指针和后面指针所指的数据域相等
      // 删除q所指向的节点并释放掉
      p->next = q->next; // 改变指针指向下一个节点
      free(q);   // 释放掉
      q = p->next;
    }
    p = p->next;
  }
}