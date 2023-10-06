/**
 ***************************************************
 * @file           : PreThread.cpp
 * @author         : zi_mei
 * @brief          : 先序线索化
 * @date           : 2023/10/5
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

// 初始化与定义
typedef struct ThreadNode{
  ElemType data;
  struct ThreadNode *lchild,*rchild;
  int ltag,rtag;
}ThreadNode,*ThreadTree;

//当前访问结点的前驱
ThreadNode *pre=NULL;

void visit(ThreadNode *q){//建立q结点前驱
  if(q->lchild==NULL){
    q->lchild=pre;
    q->ltag=1;
  }
  if(pre!=NULL&&pre->rchild!=NULL){//建立pre结点后继
    pre->rchild=q;
    pre->rtag=1;
  }
  pre=q;
}

void PreThread(ThreadTree T){
  if(T!=NULL){
    visit(T);
    if(T->ltag==0)
      PreThread(T->lchild);
    PreThread(T->rchild);
  }
}

void CreatePreThread(ThreadTree T){
  pre=NULL;
  if(T!=NULL){
    PreThread(T);
    if(T->rchild==NULL)
      pre->ltag=1;
  }
}

int main(){
  return 0;
}