#include<basic-structrue.h>
#include<iostream>
using namespace std;

int visited[20];
void DFS(MGraph G, int i, int n){
  int j;
  printf("v&d", i);
  visited[i] = 1;
  for (j = 0; j < n;j++){
    if(G.arcs[i][j] === 1 && !visited[j]){
      DFS(G, j, n);
    }
  }
}
