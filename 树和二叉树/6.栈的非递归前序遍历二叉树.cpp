#include <stdio.h>
#include <iostream>
using namespace std;
typedef char DataType;
typedef struct node{
  DataType data;
  struct node *lchild, *rchild;

} BinTNode;
typedef BinTNode *BinTree;
#define StackSize 100;
typedef struct 
{
  DataType data[StackSize];
  int top;
}SeqStack;

// 置空栈
void InitStack(SeqStack *S){
  S->top = -1;
}
int StackEmpty(SeqStack *S){
  return S->top == -1;
}
void Push(SeqStack *S, DataType x){
  if(StackFull(S)){
    printf("stack overflow");
  }else{
    S->top = S->top + 1;
    S->data[S->top] = x;
  }
}
DataType Pop(SeqStack *S){
  if(StackEmpty(S)){
    printf("Stack Empty");
  }else{
    return S->data[S->top - 1];
  }
}
// 取栈顶元素
DataType GetTop(SeqStack *S){
  if(StackEmpty(S)){
    printf("Stack Empty");
    exit(0);
  }else{
    return S->data[S->top];
  }
}

void Preorder1(BinTree bt){
  SeqStack S;
  InitStack(&S);
  Push(&S, bt);
  while(!StackEmpty(&S)){
    bt = Pop(&S);
    if(bt!=NULL){
      printf("&c", bt->data);
      Push(&S, bt->rchild); // 因为是栈的原因，所以先入栈右子树再入栈左子树，那出栈的时候就可以左子树先出栈
      Push(&S, bt->lchild);
    }
  }
}
