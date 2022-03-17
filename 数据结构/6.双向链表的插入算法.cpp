#include <stdlib.h>
// 双向链表不用遍历每一个节点，直接插入，删除
// 表结构
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
} ListNode;
typedef ListNode *LinkList;
// 双向链表的结构
typedef struct dlnode
{
  DataType data;
  struct dlnode *prior, *next;

} DLNode;
typedef DLNode *DLinkList;
DLinkList head;

// 实现细节  插入算法
// 第一种指针修改的步骤顺序
void DLInsert(DLNode *p, DataType x)
{
  DLNode *s = (DLNode *)malloc(sizeof(DLNode));
  s->data = x;
  s->prior = p;       // 1
  s->next = p->next;  // 2
  p->next->prior = s; // 3
  p->next = s;        // 4
}
// 第二种指针修改的步骤顺序
void DLInsert(DLNode *p, DataType x, int y = 0)
{
  DLNode *s = (DLNode *)malloc(sizeof(DLNode));
  s->data = x;
  s->prior = p;       // 1
  s->next = p->next;  // 2
  p->next = s;        // 4
  s->next->prior = s; // 3
}
// 要修改四次指针域  
