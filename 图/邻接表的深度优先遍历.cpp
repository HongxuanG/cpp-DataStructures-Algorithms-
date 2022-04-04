#include<basic-structure1.h>
#include<stdio.h>
using namespace std;

/**
 * 算法流程：
 * 1. 假如我们DFS1(G, 0) 也就是说从 顶点V0 开始 先输出 O (执行到 printf("v%d->", 0);)，并记作visited[0] = 1
 * 2. 沿着边表访问，判断j 有没有被访问过(visited[j] == 1) 没有被访问过则递归调用DFS1(G, j);又被访问过则判断下一个结点(p = p->next)
 */
int visited[20]; // 创建一个长度为20的整型数组，用于存放0 和 1
void DFS1(ALGraph G, int i){
  EdgeNode *p;
  int j;
  printf("v%d->", i);
  visited[i] = 1;
  p = G[i]->link; // p指向边表的头指针
  while(p!=NULL){
    j = p->adjvex;  // 取出指针p所指向的结点的序号 赋给j
    if(!visited[j]){ // 序号j 没被访问过
      DFS1(G, j)   // 递归调用 DFS1(G, j)
    }
    p = p->next;  // p指针指向下一个结点
  }
}
// 复杂度：O(n+e)
