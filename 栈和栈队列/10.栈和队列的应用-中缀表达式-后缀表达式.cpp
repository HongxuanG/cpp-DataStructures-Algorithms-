#include <iostream>
#define QueueSize 100
#define StackSize 100
using namespace std;
typedef char DataType;
typedef struct
{
  DataType data[QueueSize];
  int front, rear;
} CirQueue;

typedef struct
{
  DataType data[StackSize];
  int top;
} SeqStack;

// 判队空
int QueueEmpty(CirQueue *Q)
{
  return Q->rear == Q->front;
}
// 置空栈
void InitStack(SeqStack *S)
{
  S->top = -1;
}
void Push(SeqStack *S, DataType x)
{
  if (StackFull(S))
  {
    printf("stack overflow");
  }
  else
  {
    S->top = S->top + 1;
    S->data[S->top] = x;
  }
}
DataType Pop(SeqStack *S)
{
  if (StackEmpty(S))
  {
    printf("Stack Empty");
  }
  else
  {
    return S->data[S->top - 1];
  }
}
// 取栈顶元素
DataType GetTop(SeqStack *S)
{
  if (StackEmpty(S))
  {
    printf("Stack Empty");
    exit(0);
  }
  else
  {
    return S->data[S->top];
  }
}
// 入队
void EnQueue(CirQueue *Q, DataType x)
{
  if (QueueFull(Q))
  {
    printf("Queue overflow");
  }
  else
  {
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % QueueSize;
  }
}
// 出队
DataType DeQueue(CirQueue *Q, DataType x)
{
  DataType x;
  if (QueueEmpty(Q))
  {
    printf("Queue Empty");
  }
  else
  {
    x = Q->data[Q->front];
    Q->front = (Q->front + 1) % QueueSize;
    return x;
  }
}
/*********************中缀表达式 转换为 后缀表达式****************************/
int Priority(char c)
{
  switch (c)
  {
  case '#':
  case '(':
    return 0;
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  }
  return -1;
}
void CTPostExp(CirQueue *Q)
{
  SeqStack *S;
  char c, t; // t是出栈的符号
  InitStack(&S);
  Push(&S, '#');
  do
  {
    c = getchar();
    switch (c)
    {
    case '':
      break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      EnQueue(&Q, c);
      break;
    case '+':
    case '-':
    case '*':
    case '/':
      while (Priority(c) <= Priority(GetTop(&S)))
      {
        t = Pop(&S);
        EnQueue(&Q, t);
      }
      Push(&S, c);
      break;
    }
  case '(':
    Push(&S, c);
    break;
  case ')':
  case '#':
    do
    {
      t = Pop(&S);
      if (t != '(' && t != '#')
      { // 没遇到'('或者没空的时候 进队列 用于把左括号和右括号的中间的那些栈元素出栈然后进队列
        EnQueue(&Q, t);
      }
    } while (t != '(' && S->top != -1) break;

  } while (c != '#');
}
/********************后缀表达式的计算*****************************/
int CPostExp(CirQueue *C)
{
  SeqStack *S;
  InitStack(&S);
  char ch;
  while (QueueEmpty(&C))
  {
    ch = DeQueue(&C);
    if (ch >= '0' && ch <= '9')
    {
      Push(&C, ch - '0');
    }
    else
    {
      int y = Pop(&S);
      int x = Pop(&S);
      switch (ch)
      {
      case '+':
        Push(&S, x + y);
        break;
      case '-':
        Push(&S, x - y);
        break;
      case '*':
        Push(&S, x * y);
        break;
      case '/':
        Push(&S, x / y);
        break;
      }
    }
  }
  return GetTop(&S)
}
