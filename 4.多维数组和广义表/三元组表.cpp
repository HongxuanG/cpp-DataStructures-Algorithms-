// 三元组表的类型定义
#define Maxsize 1000
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

// 建立三元组表
void CreateTriTable(TSMatrix *b, int a[][5], int m, int n){
  int i, j, k = 0; // k是记录非零元素的个数
  for (i = 0; i < m;i++){
    for (j = 0; j < n;j++){
      if(a[i][j]!=0){
        b->data[k].i = i;
        b->data[k].j = j;
        b->data[k].v = a[i][j];
        k++;
      }
    }
  }
  b->m = m;
  b->n = n;
  b->t = k;
}
