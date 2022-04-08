#define m 10
typedef int KeyType;
typedef struct node
{
  int keynum;        // 当前结点的关键字个数
  KeyType key[m];   // key[0]作为哨兵 用于存储要查找的关键字  从key[1]开始到key[keynum]
  struct node *parent;  // 指向双亲结点
  struct node *ptr[m];  // 子树的指针向量
}BTNode;
typedef BTNode *BTree;
