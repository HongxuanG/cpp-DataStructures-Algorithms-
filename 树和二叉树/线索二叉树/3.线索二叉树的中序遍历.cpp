#include <basicStructure.h>

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

// 回想一下之前用中序遍历的时候
// 现在用线索二叉树实现中序遍历，会方便很多，思路也清晰很多
void TinorderThrTree(BinThrTree bt){
  BinThrNode *p;
  if(bt!=NULL){
    p = bt;
    while(p->ltag == 0){
      p = p->lchild;        // 寻找中序遍历的第一个左子树结点  左子树的左子树的左子树的左子树.......
    }
    do{
      printf("%c", p->data); // 输出访问到的结点值
      p = InorderNext(p); // 查找结点*p的中序后继结点
    } while (p != NULL);  // 当p为空是算法结束
  }
}
