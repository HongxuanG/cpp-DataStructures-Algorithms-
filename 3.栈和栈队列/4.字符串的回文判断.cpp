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
// 回文串 对称的字符串就是回文串
// 怎么比较？ 思路：求出字符串长度，从中间开始将前半截字符串
// 顺序入栈，然后利用退栈操作与后半截比较
// 相等就是回文串，不等就是不是
int symmetry(char str[]){
  SeqStack S;
  InitStack(&S);
  int j, k, i;
  while(str[i]!='\0'){
    i++;
  }
  // 如果长度是5,5/2 = 2  循环两次
  // 如果长度是6,6/2 = 3  循环三次
  for (j = 0; j < i / 2; j++){
    Push(&S, str[i]);
  }
  k = (i + 1) / 2;  // 这里微妙的处理了奇偶数的情况
  // 如果长度是5,5+1/2 = 3  从下标为3开始，巧妙的跳过了中间的下标2
  // 如果长度是6,6+1/2 = 3  从下表为3开始，没有跳过下标4
  for (j = k; j < i; j++){
    if(j!=Pop(&S))
      return 0;
  }
  return 1;
}
