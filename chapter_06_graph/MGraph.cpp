/**
***************************************************
* @file           : MGraph.cpp
* @author         : zi_mei
* @brief          : 邻接矩阵
* @date           : 2023/10/24
***************************************************
*/


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define MaxVertexNum 100
#define Infinite 0x3f3f3f3f

using namespace std;

typedef char VertexType;//顶点字符
typedef int EdgeType;//边整型

typedef struct{
 VertexType Vec[MaxVertexNum];
 EdgeType Edges[MaxVertexNum][MaxVertexNum];
 int vexnum;
 int arcnum;
}MGraph;

void printGraph(MGraph *g){
 for(int i=0;i<g->vexnum;i++){
   for(int j=0;j<g->vexnum;j++){
     cout<<g->Edges[i][j]<<" ";
   }
   cout<<endl;
 }
 cout<<endl;
}

void CreateMGraph(MGraph *g){
 cout<<"创建图"<<endl;
 cout<<"输入顶点个数与边的个数"<<endl;
 cin>>g->vexnum >>g->arcnum;
 cout<<"输入顶点的名称"<<endl;
 for(int i=0;i<g->vexnum;i++){
   cin>>g->Vec[i];
 }
 for(int i=0;i<g->vexnum;i++){
   for(int j=0;j<g->vexnum;j++){
     g->Edges[i][j]=0;
   }
 }
}

int main(){
 MGraph * g=new MGraph ;
 CreateMGraph(g);
 printGraph(g);
 return 0;
}
