#include <iostream>
#include <stdio.h>
using namespace std;

typedef char DataType;
typedef struct node{
  DataType data;
  struct node *lchild, *rchild;

} BinTNode;
typedef BinTNode *BinTree;

int found = 0;  // 标志是否已经找到了 0未找到 1找到
BinTNode *p; // 目标结点

void FindBT(BinTree bt, DataType x){
  if((bt!=NULL)&& (!found)){
    if(bt->data == x){
      found = 1;
      p = bt
    }else{
      FindBT(bt->lchild, x);
      FindBT(bt->rchild, x);
    }
  }
}
