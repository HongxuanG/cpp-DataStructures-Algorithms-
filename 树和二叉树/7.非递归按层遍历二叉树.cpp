#include <iostream>
#define QueueSize 100
#include <stdio.h>
using namespace std;

typedef char DataType;
typedef struct node{
  DataType data;
  struct node *lchild, *rchild;

} BinTNode;
typedef BinTNode *BinTree;

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
DataType DeQueue(CirQueue *Q){
  DataType x;
  if(QueueEmpty(Q)){
    printf("Queue Empty");
    exit(0);
  }
  else
  {
    DataType x = Q->data[Q->front];
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
// 先根节点入队，输出根节点，然后出队
// 如果根节点的左子树不是空，输出左子树，将该左子树入队
// 如果根节点的右子树不是空，输出右子树，将该右子树入队
// 执行下一个循环
void TransLevel(BinTree bt){
  CirQueue Q;
  InitQueue(&Q);
  if(bt==NULL){
    return;
  }else{
    printf("%c", bt->data);
    EnQueue(&Q, bt);
    while(!QueueEmpty(&Q)){
      bt = DeQueue(&Q);
      if(bt->lchild!=NULL){
        printf("%c", bt->lchild->data);
        EnQueue(&Q, bt->lchild);
      }
      if(bt->rchild!=NULL){
        printf("%c", bt->rchild->data);
        EnQueue(&Q, bt->rchild);
      }
    }
  }
}
