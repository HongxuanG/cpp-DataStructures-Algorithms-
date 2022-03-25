#include <stdio.h>
#include <iostream>
using namespace std;
typedef char DataType;
typedef struct node{
  DataType data;
  struct node *lchild, *rchild;

} BinTNode;
typedef BinTNode *BinTree;

void Preorder(BinTree bt){
  if(bt!=NULL){
    printf("%c", bt->data);
    Preorder(bt->lchild);
    Preorder(bt->rchild);
  }
}
