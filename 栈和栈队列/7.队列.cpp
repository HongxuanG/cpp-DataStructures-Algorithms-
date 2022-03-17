#include <iostream>
#define QueueSize 100
using namespace std;
typedef char DataType;
typedef struct {
  DataType data[QueueSize];
  int front, rear;
} CirQueue;

// 置空
void InitQueue(CirQueue *Q){
  Q->front = Q->rear = 0;
}
// 判队空
int QueueEmpty(CirQueue *Q){
  return Q->rear == Q->front;
}
// 判队满
int QueueFull(CirQueue *Q){
  return (Q->rear + 1) % QueueSize == Q->front;
}
// 入队
void EnQueue(CirQueue *Q,DataType x){
  if(QueueFull(Q)){
    printf("Queue overflow");
  }else{
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % QueueSize;
  }
}
// 出队
DataType DeQueue(CirQueue *Q, DataType x){
  DataType x;
  if(QueueEmpty(Q)){
    printf("Queue Empty");
    exit(0);
  }
  else
  {
    x = Q->data[Q->front];
    Q->front = (Q->front + 1) % QueueSize;
    return x;
  }
}
// 去队头元素
DataType GetFront(CirQueue *Q){
  if(QueueEmpty(Q)){
    printf("Queue Empty");
    exit(0);
  }else{
    return Q->data[Q->front];
  }
}
