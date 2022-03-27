#include <stdio.h>
#include <iostream>
using namespace std;
typedef char DataType;
typedef struct node
{
  DataType data;
  int rtag, ltag;
  struct node *lchild, *rchild;
} BinThrNode;
typedef BinThrNode *BinThrTree;
