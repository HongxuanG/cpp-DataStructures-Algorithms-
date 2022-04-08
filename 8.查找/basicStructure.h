typedef char DataType;
typedef int KeyType;
typedef struct
{
  KeyType key;
  InfoType data;
} NodeType;
typedef NodeType SeqList[n + 1]; // 0号单元是哨兵

typedef struct node
{
  KeyType key;
  DataType other;
  struct node *lchild, *rchild;
}BSTNode;
typedef BSTNode *BSTree;

