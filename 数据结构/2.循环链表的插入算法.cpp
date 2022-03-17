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

// 从大到小排列的非空循环单链表，要插入一个x节点到合适的位置，使其仍然是有序的
// 将x插入到
void InsertList(LinkList L, int x){
  ListNode *s, *p, *q;  // 为什么要两个指针呢，因为插入一个节点就必须要两个指针辅助切换指针的所指方向
  s = (ListNode *)malloc(sizeof(ListNode));
  s->data = x;
  p = L;   // p指向头结点
  q = p->next; // q指向第一个节点
  while (q->data>x&&q!=L)
  {
    p = p->next;
    q = p->next;
  }
  // 下面的两句就是插入节点的关键语句
  p->next = s;
  s->next = q;
}