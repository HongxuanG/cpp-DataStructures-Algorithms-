#include <stdio.h>
#include <iostream>
using namespace std;
typedef char DataType;
typedef struct node{
  DataType data;
  struct node *lchild, *rchild;

} BinTNode;
typedef BinTNode *BinTree;

void Postorder(BinTree bt){
  if(bt!=NULL){
    Postorder(bt->lchild);
    Postorder(bt->rchild);
    printf("%c", bt->data);
  }
}
