#include <basicStructure.h>
// 查找p的中序遍历的后继结点
  //       A
  //     /   \
  //    B     C
  //   / \   / \
  //  D   E  F  G
  // 中序遍历顺序：D B E A F C G
BinThrNode *InorderNext(BinThrNode *p){
  if(p->rtag == 1){
    return p->rchild;
  }else{
    p = p->rchild;
    while(p->ltag == 0){
      p = p->lchild;
    }
    return p;
  }
}
// 如果要求出C的后继结点  G 就是C的后继结点
