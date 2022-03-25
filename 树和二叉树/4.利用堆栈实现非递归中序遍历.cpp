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

void Inorder1(BinTree bt){
  SeqStack S;
  BinTNode *p;
  InitStack(&S);
  Push(&S, bt);
  while(!StackEmpty(&S)){
    while(GetTop(&S)){
      Push(&S, GetTop(&S)->lchild); // 直到左子树空为止
    }
    p = Pop(&S);   // 空指针退栈
    if(!StackEmpty(&S)){
      printf("%c", GetTop(&S)->data); // 访问根节点
      p = Pop(&S);
      Push(&S, p->rchild); // 右子树进栈
    }
  }
}
