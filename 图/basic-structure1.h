// 邻接表表示法
#define MaxVertexNum 20
typedef char VertexType;
typedef struct node {  // 边表结点类型
  int adjvex;            // 该边所指向的顶点的位置
  struct node *next;   // 指向下一条边的指针
} EdgeNode;
typedef struct vnode{  // 顶点表结点
  VertexType vertex;   // 顶点信息
  EdgeNode * link;     // 边表头指针, 指向第一条依附该顶点的边
} VNode, AdjList[MaxVertexNum]; // 邻接表类型
typedef AdjList ALGraph;  // 定义为图类型
