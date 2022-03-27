#include <basicStructure.h>

// 二叉树的线索化
// 如果左子树指针为null，左线索标志ltag = 1 否则ltag = 0
// 如果右子树指针为null，右线索标志rtag = 1 否则ltag = 0
void InorderThread(BinThrTree bt){
  static BinThrNode *pre = NULL; // 前趋结点，保存刚访问过的结点
  if(bt!=NULL){
    InorderThread(bt->lchild);  // 左子树线索化
    if(bt->lchild == NULL){
      bt->ltag = 1;
    }else{
      bt->ltag = 0
    }
    if(bt->rchild == NULL){
      bt->rtag = 1;
    }else {
      bt->rtag = 0;
    }
    if(pre){
      if(pre->rtag == 1){ 
        pre->rchild = bt; // 前趋结点的右子树的指针域指向当前根节点
      }
      if(bt->ltag == 1){
        bt->lchild = pre; // 当前根结点的左子树的指针域指向前趋结点
      }
    }
    pre = bt;
    InorderThread(bt->rchild); // 右子树线索化
  }
}
