/**
 ***************************************************
 * @file           : PreThread.cpp
 * @author         : zi_mei
 * @brief          : ����������
 * @date           : 2023/10/5
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

// ��ʼ���붨��
typedef struct ThreadNode{
  ElemType data;
  struct ThreadNode *lchild,*rchild;
  int ltag,rtag;
}ThreadNode,*ThreadTree;

//��ǰ���ʽ���ǰ��
ThreadNode *pre=NULL;

void visit(ThreadNode *q){//����q���ǰ��
  if(q->lchild==NULL){
    q->lchild=pre;
    q->ltag=1;
  }
  if(pre!=NULL&&pre->rchild!=NULL){//����pre�����
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