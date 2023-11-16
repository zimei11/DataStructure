/**
 ***************************************************
 * @file           : ALGraph.cpp
 * @author         : zi_mei
 * @brief          : �ڽӱ�
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

typedef char VertexType;//�����ַ�
typedef int EdgeType;//������

typedef struct ArcNode{
  // InfoType info;
  int adjvex;//��ָ�����һ�������λ��
  struct ArcNode *next;
}ArcNode;

typedef struct VNode{
  ArcNode *first;
  VertexType data;
}VNode,AdjList[MaxVertexNum];//�ڽӵ���

typedef struct {
  AdjList vertices;
  int vexnum,arcnum;
}ALGraph;


int main(){
  return 0;
}

/*
ͼ�Ļ���������
Adjacent(G,x,y)���ж�ͼG�Ƿ���ڱ�[HTML_REMOVED]��(x,y)��
Neighbors(G,x)���г�ͼG������x�ڽӵıߡ�
InsertVertex(G,x)����ͼG�в��붥��x��
DeleteVertex(G,x)����ͼG��ɾ������x��
AddEdge(G,x,y)���������(x,y)�������[HTML_REMOVED]�����ڣ�����ͼG����Ӹñߡ�
RemoveEdge(G,x,y)���������(x,y)�������[HTML_REMOVED]���ڣ����ͼG��ɾ���ñߡ�
FirstNeighbor(G,x)����ͼG�ж���x�ĵ�һ���ڽӵ㣬�����򷵻ض���š���xû���ڽӵ��ͼ�в�����x���򷵻�-1��
NextNeighbor(G,x,y)������ͼG�ж���y�Ƕ���x��һ���ڽӵ㣬���س�y֮�ⶥ��x����һ���ڽӵ�Ķ���ţ���y��x�����һ���ڽӵ㣬�򷵻�-1��
Get_edge_value(G,x,y)����ȡͼG�б�(x,y)��[HTML_REMOVED]��Ӧ��Ȩֵ��
Set_edge_value(G,x,y,v)������ͼG�б�(x,y)��[HTML_REMOVED]��Ӧ��ȨֵΪv��
Adjacent(G,x,y)���ж�ͼG�Ƿ���ڱ�<x,y>��(x,y)

���ߣ�Meng123456
        ���ӣ�https://www.acwing.com/blog/content/14761/
 */