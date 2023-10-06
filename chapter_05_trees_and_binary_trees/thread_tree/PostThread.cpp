/**
 ***************************************************
 * @file           : PostThread.cpp
 * @author         : zi_mei
 * @brief          : ºóÐòÏßË÷»¯
 * @date           : 2023/10/5
 ***************************************************
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

typedef struct ThreadNode{
  ElemType data;
  struct ThreadNode *rchild,*lchild;
  int ltag,rtag;
}ThreadNode,*ThreadTree;

ThreadNode *pre=NULL;

void visit(ThreadNode *q){
  if(q->lchild==NULL){
    q->lchild=pre;
    q->ltag=1;
  }
  if(pre!=NULL&&pre->rchild==NULL){
    pre->rchild=q;
    pre->rtag=1;
  }
  pre=q;
}

void PostThread(ThreadTree T){
  if(T!=NULL){
    PostThread(T->lchild);
    PostThread(T->rchild);
    visit(T);
  }
}

void CreatePostThread(ThreadTree T){
  pre=NULL;
  if(T!=NULL){
    PostThread(T);
    if(pre->rchild==NULL){
      pre->rtag=1;
    }
  }
}

int main(){
  return 0;
}