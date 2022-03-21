// 三元组表的类型定义
#define Maxsize 1000
#include <stdio.h>
using namespace std;
typedef char DataType;
typedef struct
{
  int j, i;
  DataType v; // 元素的值
}TriTupleNode;
typedef struct{
  TriTupleNode data[Maxsize];
  int m, n, t; // 行数，列数，非零元素的个数
} TSMatrix;

void TransMatrix(TSMatrix a, TSMatrix *b){
  int p, q, col;
  b->m = a.n;
  b->n = a.m;
  b->t = a.t;
  if(b->t <= 0){
    printf("M中没有非零元素");
  }else{
    q = 0;
    for (col = 0; col < a.n;col++){
      for (p = 0; p < a.t;p++){
        if (a.data[p].j == col){
          b->data[q].i = a->data[p].j;
          b->data[q].j = a->data[p].i;
          b->data[q].v = a->data[p].v;
          ++q;
        }
      }
    }
  }
}
