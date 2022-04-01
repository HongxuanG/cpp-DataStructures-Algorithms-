// 邻接矩阵表示
#define MaxVertexNum 50
typedef char VertexType;
typedef Struct{
  VertexType vexs[MaxVertexNum];
  Adjmatrix arcs [MaxVertexNum][MaxVertexNum];
}MGraph;
