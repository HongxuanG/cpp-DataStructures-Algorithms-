#include<stdio.h>
using namespace std;
// 马鞍点：某个元素即是i行中的最小值又是j列中最大值
// 输出矩阵中的所有马鞍点
void MaxMin(int A[4][5], int m, int n)
{
  int i, j;
  int Max[5], Min[4];
  for (i = 0; i < m;i++){
    Min[i] = A[i][0];
    for (j = 0; j < n;j++){
      if(Min[i]>A[i][j]){
        Min[i] = A[i][j];
      }
    }
  }
  for (i = 0; i < n;i++){
    Max[i] = A[0][i];
    for (j = 0; j < m;j++){
      if(Max[i]<A[j][i]){
        Max[i] = A[j][i];
      }
    }
  }
  for (i = 0; i < m;i++){
    for (j = 0; j < n;j++){
      if(Min[i] == Max[j]){
        printf("(%d,%d)", i, j);
      }
    }
  }
}
