/**
 ***************************************************
 * @file           : ALGraph.cpp
 * @author         : zi_mei
 * @brief          : 邻接表
 *                   https://blog.csdn.net/CXR_XC/article/details/127809296
 * @date           : 2023/10/24
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define MaxVertexNum 100

using namespace std;

typedef char VertexType;//顶点字符
typedef int EdgeType;//边整型

typedef struct ArcNode{
  // InfoType info;
  int adjvex;//弧指向的下一个顶点的位置
  struct ArcNode *next;
}ArcNode;

typedef struct VNode{
  ArcNode *first;
  VertexType data;
}VNode,AdjList[MaxVertexNum];//邻接点域

typedef struct {
  AdjList vertices;
  int vexnum,arcnum;
}ALGraph;


int main(){
  return 0;
}

/*
图的基本操作：
Adjacent(G,x,y)：判断图G是否存在边[HTML_REMOVED]或(x,y)。
Neighbors(G,x)：列出图G中与结点x邻接的边。
InsertVertex(G,x)：在图G中插入顶点x。
DeleteVertex(G,x)：从图G中删除顶点x。
AddEdge(G,x,y)：若无向边(x,y)或有向边[HTML_REMOVED]不存在，则向图G中添加该边。
RemoveEdge(G,x,y)：若无向边(x,y)或有向边[HTML_REMOVED]存在，则从图G中删除该边。
FirstNeighbor(G,x)：求图G中顶点x的第一个邻接点，若有则返回顶点号。若x没有邻接点或图中不存在x，则返回-1。
NextNeighbor(G,x,y)：假设图G中顶点y是顶点x的一个邻接点，返回除y之外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1。
Get_edge_value(G,x,y)：获取图G中边(x,y)或[HTML_REMOVED]对应的权值。
Set_edge_value(G,x,y,v)：设置图G中边(x,y)或[HTML_REMOVED]对应的权值为v。
Adjacent(G,x,y)：判断图G是否存在边<x,y>或(x,y)

作者：Meng123456
        链接：https://www.acwing.com/blog/content/14761/
 */