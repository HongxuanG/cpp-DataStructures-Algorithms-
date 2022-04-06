#include <basicStructure.h>
typedef char DataType;
typedef struct node {
  DataType data;
  struct node *next;
} ListNode;
typedef ListNode *LinkList;
// 基本思路和普通的直接选择排序一样，只是换成了链表的形式
void LselectSort1(LinkList head){
  ListNode *p, *r, *s;
  ListNode q; // q相当于R[0哨兵，用于存储要交换的结点
  p = head;
  // p是用于标记循环的指针
  while(p!=NULL){
    s = p;
    r = p->next;
    // 找出最小的结点
    while(r!=NULL){
      if(r->data < s->data){
        s = r;
      }
      r = r->next;
    }
    // 节点之间交换位置
    if(s!=p){
      q=(*p);
      p->data = s->data;
      s->data = q.data;
    }
    p = p->next;
  }
}
