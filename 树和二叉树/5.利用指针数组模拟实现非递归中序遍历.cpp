#include <stdio.h>
#include <iostream>
using namespace std;
typedef char DataType;
typedef struct node{
  DataType data;
  struct node *lchild, *rchild;

} BinTNode;
typedef BinTNode *BinTree;

void Inorder2(BinTree bt){
  BinTNode *ST[100];
  int top = 0;
  ST[top] = bt;
  do{
    while(ST[top] != NULL){ 
      top = top + 1;
      ST[top] = ST[top - 1]->lchild;  // 把根节点和其所有的左节点装入数组
    }
    top = top -1;   // 索引到上层节点
    if(top>=0){
      printf("%c", ST[top]->data); // 输出该节点
      ST[top] = ST[top]->rchild; // 该节点被赋值该节点的右子树 如过右子树也为null，则直接top = top - 1 索引到上层左子树
    }
  }while(top != -1)
}
