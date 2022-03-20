#include <iostream>
#define QueueSize 100
using namespace std;
typedef char DataType;
typedef struct qnode
{
  DataType data;
  struct qnode *next;
}QueueNode;
typedef struct {
  QueueNode *front;
  QueueNode *rear;
} LinkQueue;
LinkQueue Q;

// 构造空队列
void InitLinkQueue(LinkQueue *Q){
  Q->front = (QueueNode *)malloc(sizeof(QueueNode));
  Q->rear = Q->front;
  Q->rear->next = NULL;
}
// 判队空空
int QueueEmpty(LinkQueue *Q){
  return Q->front == Q->rear;
}
// 入队
void EnQueue(LinkQueue *Q, DataType x){
  QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));
  p->data = x;
  p->next = NULL;
  Q->rear->next = p;
  Q->rear = p;
}
// 取对头元素
DataType GetFront(LinkQueue *Q){
  if(QueueEmpty(Q)){
    printf("queue empty");
    exit(0);
  }else{
    return Q->front->next->data;
  }
}
// 出队列
DataType DeQueue(LinkQueue *Q){
  QueueNode *p;
  if (QueueEmpty(Q))
  {
    printf("queue empty");
    exit(0);
  }
  else
  {
    p = Q->front;
    Q->front = Q->front->next;
    free(p);
    return Q->front->data;
  }
}
