#include <BSTbasicStructure.h>
#include <iostream>
using namespace std;

// 二叉查找树   pos是该关键字的位置  k是关键字
BTNode *SearchBTree(BTree T, KeyType K, int *pos){
  int i;
  BTNode *p = T;
  while(p!=NULL){
    i = p->keynum;  // 索引值
    p->key[0] = K;  // 要查找的关键字作为哨兵  用于处理边界
    while(K < p->key[i]){
      i--;
    }
    if(K == p->key[i] && i > 0){  // 找到了并且i不是0  非哨兵
      *pos = i;
      return p;
    }else{
      p = p->ptr[i];  // p指向下一个子树结点  继续循环直到p==null
    }
  }
  return NULL;
}
// 比较过程：
// 要查找K = 18的数
// 首先K作为哨兵存储在p->key[0]里面 K和根节点的p->key[i]比较，大于K就走根节点的左子树，小于K就走根节点的右子树
// 
