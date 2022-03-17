#include <stdlib.h>
#include <stdio.h>
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

LinkList CreateListF(){
  LinkList head;
  ListNode *p;
  char ch;
  head = NULL;
  ch = getchar();
  while(ch!='\n'){
    p = (ListNode *)malloc(sizeof(ListNode));
    p->data = ch;
    p->next = head;
    head = p;
    ch = getchar();
  }
  return head;
}