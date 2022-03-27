#define MaxTreeSize = 10;
typedef char DataType;
typedef struct {
  DataType data;
  int parent;   // 双亲位置域
} PTNode;
typedef struct
{
  PTNode nodes[MaxTreeSize]; // 
  int n;          // 结点树
}Ptree;
