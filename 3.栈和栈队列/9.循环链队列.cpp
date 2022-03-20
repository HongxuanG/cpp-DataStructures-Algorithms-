#include <iostream>
#define QueueSize 100
using namespace std;
typedef char DataType;
typedef struct queuenode{
  DataType data;
  struct queuenode *next;
} QueueNode;
QueueNode *rear;

// 初始化空的循环链队列
QueueNode InitQueue(QueueNode *rear){
  rear = (QueueNode *)malloc(sizeof(QueueNode));
  rear->next = rear;
  return rear;
}
// 入队
void EnQueue(QueueNode *rear, DataType x){
  QueueNode *s = (QueueNode *)malloc(sizeof(QueueNode));
  s->data = x;
  s->next = rear->next;
  rear->next = s;
  rear = s;
}
// 出队  还是删除头结点，返回原队头结点的数据域 跟链队的出队方式一样
DataType DeQueue(QueueNode *rear){
  QueueNode *s, *t; // s用来存储头结点，t用来存储元队头结点
  DataType x; // x用来存储原队头结点的data
  if (rear->next == rear)
  {
    printf("queue empty");
    exit(0);
  }
  else
  {
    s = rear->next;
    rear->next = s->next; // 删除头结点
    t = s->next; // 
    x = t->data; // 保存原队头结点的data
    free(s); // 释放头结点
    return x; 
  }
}
