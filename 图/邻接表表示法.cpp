#include<basic-structure1.h>
#include<iostream>
#include<stdio.h>
using namespace std;
void CreateGraph(ALGraph GL, int n, int e){
  int i, j, k;
  EdgeNode *p;
  for (i = 0; i < n;i++){
    GL[i].vertex = getchar();
    GL[i].link = NULL;
  }
  for (k = 0; k < e;k++){
    scanf("%d, %d", &i, &j);
    p = (EdgeNode *)malloc(sizeof(EdgeNode));
    p->adjvex = j;
    p->next = GL[i].link;
    GL[i].link = p;
    p = (EdgeNode *)malloc(sizeof(EdgeNode));
    p->adjvex = i;
    p->next = GL[j].link;
    GL[j].link = p;
  }
}
