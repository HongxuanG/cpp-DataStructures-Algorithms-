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
}ListNode;
typedef ListNode *LinkList;
// 双向链表的结构
typedef struct dlnode
{
  DataType data;
  struct dlnode *prior, *next;

} DLNode;
typedef DLNode *DLinkList;
DLinkList head;

// 实现细节  删除
DataType DLDelete(DLNode *p, DataType x){
  p->prior->next = p->next;
  p->next->prior = p->prior;
  x = p->data;
  free(p);
  return x;
}
