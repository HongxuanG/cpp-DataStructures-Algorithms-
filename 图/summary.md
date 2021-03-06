<h1 align="center">图Graph</h1>

## 图的定义和术语

### 有向图
每条边都有方向（箭头）

## 无向图
每条边都没有方向

### 出边和入边
有向图中< V<sub>i</sub> , V<sub>j</sub> >表示从顶点V<sub>i</sub>`到顶点V<sub>j</sub>的边

这条边称为V<sub>i</sub> 的`出边`，这条边也称为V<sub>j</sub> 的`入边`


### 弧
有向图的每条边都成为弧

### 弧尾
这条边的起点称为弧的`弧尾`

### 弧头
这条边的起点称为弧的`弧头`

### 有向完全图
有`n`个顶点的有向图，边的数目达到`n(n-1)`

### 无向完全图
有`n`个顶点的无向图，边的数目达到`n(n-1) / 2`

### 度
一个顶点V的度就是，顶点V的边的数目

顶点V的度的总数 = 顶点V的入边数目 + 顶点V的出边数目

### 入度
一个顶点V的入度就是，顶点V的入边的数目
### 出度
一个顶点V的出度就是，顶点V的出边的数目
### 路径
一个顶点V<sub>i</sub>到另一个顶点V<sub>j</sub>所经过的边的集合

### 回路或环
起点V<sub>i</sub>到终点V<sub>j</sub>是相同的点，从起点出发经过了一条简单路径，最后回到终点，这个路径称为`回路`或`环`

### 边上的权
边上标有数值，那么这个值就是这条边的权

### 图的特征特点 
1. 所有顶点的度之和，等于边或弧的条数的2倍
2. 具有`n`个顶点的无向图中，边的数目最多为`n(n-1) / 2`
3. 具有`n`个顶点的有向图中，边的数目最多为`n(n-1)`

## 图的存储结构
邻接矩阵表示法
邻接表表示法

## 图的遍历
深度优先搜索遍历
广度优先搜索遍历
