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


// 双链表的对称型
// p->prior->next == p->next->prior == p
