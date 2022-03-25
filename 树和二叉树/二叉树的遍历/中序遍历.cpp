#include <stdio.h>
#include <iostream>
using namespace std;
typedef char DataType;
typedef struct node{
  DataType data;
  struct node *lchild, *rchild;

} BinTNode;
typedef BinTNode *BinTree;

void Inorder(BinTree bt){
  if(bt!=NULL){
    Inorder(bt->lchild);
    printf("%c", bt->data);
    Inorder(bt->rchild);
  }
}
