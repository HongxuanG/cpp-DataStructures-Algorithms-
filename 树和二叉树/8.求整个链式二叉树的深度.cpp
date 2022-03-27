#include <iostream>
#include <stdio.h>
using namespace std;

typedef char DataType;
typedef struct node{
  DataType data;
  struct node *lchild, *rchild;

} BinTNode;
typedef BinTNode *BinTree;

// 二叉树的深度：就是根的左子树和根的右子树的层级 + 1
// 1 是 根节点的层级 1
int BinTreeDepth(BinTree bt){
  int depl,depr;
  if(bt==NULL){
    return 0;
  }else{
    depl = BinTreeDepth(bt->lchild);
    depr = BinTreeDepth(bt->rchild);
    if(depl > depr){
      return depl + 1;
    }else{
      return depr + 1;
    }
  }
}
