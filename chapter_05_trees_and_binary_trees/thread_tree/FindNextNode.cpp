/**
 ***************************************************
 * @file           : NextNode.cpp
 * @author         : zi_mei
 * @brief          : 中序遍历找后继结点
 * @date           : 2023/10/17
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

typedef struct ThreadNode{
  struct ThreadNode *lchild,*rchild;
  ElemType data;
  int ltag,rtag;
}ThreadNode ,*ThreadTree;

ThreadNode * FirstNode(ThreadNode *p){
  while(p->ltag==0){
    p=p->lchild;
  }
  return p;
}

ThreadNode *NextNode(ThreadNode *p){
  if(p->rtag==1){
    return p->rchild;
  }else{
    return FirstNode(p->rchild);
  }
}

void InOrder(ThreadNode * T){
  for(ThreadNode *p=FirstNode(T);p!=NULL;p= NextNode(p)){
    cout<<p->data<<" ";
  }
  cout<<endl;
}

int main(){
  return 0;
}