#include <iostream>
using namespace std;
typedef char DataType;
typedef struct stacknode
{
  DataType data;
  struct stacknode *next;
}StackNode;
typedef StackNode *LinkStack;
LinkStack top; // 指针
// 判链栈空
int StackEmpty(LinkStack top){
  return top == NULL;
}
// 进栈
LinkStack Push(LinkStack top, DataType x){
  StackNode *p;
  p = (StackNode *)malloc(sizeof(StackNode));
  p->data = x;
  p->next = top;
  top = p;
  return top;
}
// 出栈
LinkStack Pop(LinkStack top, DataType *x){
  StackNode *p = top;
  if(StackEmpty(top)){
    printf("stack Empty");
    exit(0);
  }else{
    *x = p->data;
    top = p->next;
    free(p);
    return top;
  }
}
DataType GetTop(LinkStack top){
  if(StackEmpty(top)){
    printf("stack Empty");
    exit(0);
  }else{
    return top->data;
  }
}
