/**
 ***************************************************
 * @file           : PreNode.cpp
 * @author         : zi_mei
 * @brief          : None
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
}ThreadNode,*ThreadTree;

ThreadNode *LastNode(ThreadNode* p){
  if(p->rtag==0){
    p=p->rchild;
  }
  return p;
}

ThreadNode *PreNode(ThreadNode* p){
  if(p->ltag==1){
    return p->lchild;
  }else{
    return LastNode(p->lchild);
  }
}

void RevInOrder(ThreadTree T){//ÄæÏòÖÐÐò±éÀú
  for(ThreadNode *p=T;p!=NULL;p= PreNode(p)){
    cout<<p->data<<" ";
  }
  cout<<endl;
}

int main(){
  return 0;
}