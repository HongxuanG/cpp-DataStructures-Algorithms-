#include<basic-structrue1.h>
#include <iostream>
#include<stdio.h>
using namespace std;
#define QueueSize 100
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

// 邻接表的广度优先遍历
// 依然是使用队列，将已访问的顶点入队列，
void BFS1(ALGraph G, int i, int n){
  CirQueue Q;
  int j, k;
  int visited[20];
  InitQueue(&Q);
  EdgeNode *p;
  EnQueue(&Q, i);
  while(!QueueEmpty(&Q)){
    k = DeQueue(&Q);
    p = G[k].link;
    while(p!=NULL){
      j = p->adjvex;
      if(!visited[j]){
        printf("v%d->", j);
        visited[j] = 1;
        EnQueue(&Q, j);
      }
      p = p->next;
    }
  }
}
