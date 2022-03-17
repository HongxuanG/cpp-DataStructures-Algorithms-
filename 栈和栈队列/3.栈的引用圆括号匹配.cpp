#include<iostream>
#define StackSize 100;
using namespace std;
typedef char DataType;
typedef struct 
{
  DataType data[StackSize];
  int top;
}SeqStack;
SeqStack S;

// 置空栈
void InitStack(SeqStack *S){
  S->top = -1;
}
int StackEmpty(SeqStack *S){
  return S->top == -1;
}
int StackFull(SeqStack *S){
  return S->top == StackSize - 1;
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
int Expr(){
  SeqStack S; // 栈
  DataType ch, x;
  InitStack(&S);
  ch = getchar();
  while(ch!='\n'){
    if(ch=='('){
      Push(&S, ch);
    }else{
      if(ch==')'){
        if(StackEmpty(&S)){
          return 0;
        }else{
          x = Pop(&S);
        }
      }
      ch = getchar();
    }
  }
  // if(StackEmpty(&S)){
  //   return 1;
  // }else{
  //   return 0;
  // }
  return StackEmpty(&S);
}
