#include<basic-structrue.h>
#include<stdio.h>
using namespace std;
void CreateMGraph(MGraph *G, int n, int e){
  int i, j, k, w;
  scanf("%d, %d", &n, &e);
  for (i = 0; i < n;i++){
    scanf("%c", &G->vexs[i]);
  }
  for (i = 0; i < n;i++){
    for (j = 0; j < n;j++){
      G->arcs[i][j] = 65535;
    }
  }
  for (k = 0;k<e;k++){
    scanf("%d, %d, %d", &i, &j, &w);
    // 这里是因为无向图是对称矩阵，需要两次的权值赋值
    // 因为是对称矩阵，所以赋给i,j和j,i
    G->arcs[i][j] = w;
    G->arcs[j][i] = w;
  }
}
