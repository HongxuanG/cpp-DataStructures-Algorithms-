#include<basic-structrue.h>
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
// 邻接矩阵的广度优先遍历
int visited[20];
// i 是一开始的顶点序号  n 是顶点的总数
void BFS(MGraph G, int i, int n){
  // 队列，存放被访问过的顶点
  CirQueue Q;
  int k, j;
  InitQueue(&Q);
  printf("v%d->", i);
  visited[i] = 1;
  EnQueue(&Q, i);
  while(!QueueEmpty(&Q)){
    k = DeQueue(&Q);
    for (j = 0; j < n;j++){
      if(G.arcs[k][j] == 1 && !visited[j]){
        printf("v%d->", j);
        visited[j] = 1;
        EnQueue(&Q, j);
      }
    }
  }
}
