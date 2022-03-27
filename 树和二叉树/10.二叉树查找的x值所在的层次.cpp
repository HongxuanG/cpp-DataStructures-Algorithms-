#include <iostream>
#include <stdio.h>
using namespace std;

typedef char DataType;
typedef struct node{
  DataType data;
  struct node *lchild, *rchild;

} BinTNode;
typedef BinTNode *BinTree;

// 遍历用的前序遍历法  根 左 右
// lh 是当前搜索到的层级
// p 是要搜索的结点
int Level(BinTree bt, BinTNode *p, int lh){
  static int h = 0;
  if(bt==NULL){
    h = 0;
  }else if(bt == p){
    h = lh;
  }else{
    Level(bt->lchild, p, lh + 1);
    if(h == 0){
      Level(bt->rchild, p, lh + 1);
    }
  }
  return h;
}
