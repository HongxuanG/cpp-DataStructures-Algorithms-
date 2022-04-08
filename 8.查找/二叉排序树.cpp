// 特点：根的左子树的节点均小于根节点，根的右子树的节点均大于根节点
// 中序遍历可以得出一个递增的有序序列
#include <basicStructure.h>
#include <iostream>
using namespace std;
// 插入算法
BSTree InsertBST(BSTree T, BSTNode *S){
  BSTNode *f, *p = T;
  while(p){
    f = p;
    if(S->key < P->key){
      p = p->lchild;
    }else {
      p = p->rchild;
    }
  }
  if(T==NULL){
    T = S;
  }else if(S->key<f->key){
    f->lchild = S;
  }else{
    f->rchild = S;
  }
  return T;
}
// 生成二叉查找树 没输入一个节点数据，就调用一次插入算法
BSTree CreateBST(void){
  BSTree T = NULL;
  KeyType key;
  BSTNode *S;
  scanf("%d", &key);
  while(key){
    S = (BSTNode *)malloc(sizeof(BSTNode));
    S->key = key;
    S->lchild = S->rchild = NULL;
    T = InsertBST(T, S);
    scanf("%d", &key);
  }
  return T;
}
// 查找
BSTNode * SearchBST(BSTree T, KeyType x){
  if(T==NULL || T->key == x){
    return T;
  }
  if(x<T->key){
    return SearchBST(T->lchild, x);
  }else{
    return SearchBST(T->rchild, x);
  }
}
