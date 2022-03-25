#include <stdio.h>
#include <iostream>
using namespace std;
typedef char DataType;
typedef struct node{
  DataType data;
  struct node *lchild, *rchild;

} BinTNode;
typedef BinTNode *BinTree;

BinTNode *CreateTree(char *str){
  BinTNode *st[100];
  BinTNode *p;
  int top, k, j = 0;
  top = -1;
  BinTNode *b;
  char ch = str[j];
  while (ch != '\0'){
    switch (ch)
    {
    case '(':
      top++;
      st[top] = p;
      k = 1;
      break;
    case ')':
      top--;
    case ',':
      k = 2;
      break;
    default:
      /*创建p节点 start*/
      p = (BinTNode *)malloc(sizeof(BinTNode));
      p->data = ch;
      p->lchild = p->rchild = NULL;
      /*创建p节点 end*/
      if(b==NULL){ // 只有一开始才进入的if语句，用于创建根节点
        b = p;
      }else{ // 根据k判断1还是2 就是说是左节点还是右节点
        switch (k)
        {
        case 1:
          st[top] -> lchild = p;
          break;
        case 2:
          st[top] -> rchild = p;
          break;
        }
      }
      break;
    }
    j++;
    ch = str[j]; // 取下一个字符
  }
  return b;
}
