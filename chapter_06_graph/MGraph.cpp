/**
***************************************************
* @file           : MGraph.cpp
* @author         : zi_mei
* @brief          : �ڽӾ���
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

typedef char VertexType;//�����ַ�
typedef int EdgeType;//������

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
 cout<<"����ͼ"<<endl;
 cout<<"���붥�������ߵĸ���"<<endl;
 cin>>g->vexnum >>g->arcnum;
 cout<<"���붥�������"<<endl;
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
