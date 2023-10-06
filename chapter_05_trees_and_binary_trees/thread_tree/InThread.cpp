/**
 ***************************************************
 * @file           : ThreadTree.cpp
 * @author         : zi_mei
 * @brief          : ��������������������
 * @date           : 2023/9/25
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

/*
 * ��ͳ����������ǰ��
 */

/*
typedef struct BiTNode{
  struct BiTNode *lchild,*rchild;
  ElemType data;
}BiTNode,*BiTree;
BiTNode *p; //pָ��Ŀ���㣬����p��ǰ��
BiTNode *pre=NULL; //preָ��ǰ���ʽ���ǰ��
BiTNode *final=NULL; //���ڼ�¼���ս��

void visit(BiTNode* q){
  if(p==q){
    final=pre;
  }else{
    pre=q;
  }
}

void InOrder(BiTree T){
  if(T!=NULL){
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
  }
}
*/

/*
 * ��������������
 */

typedef struct ThreadNode{
  ElemType data;
  struct ThreadNode *lchild,*rchild;
  int ltag,rtag;
}ThreadNode,*ThreadTree;

/*
 * tag=0 ��ʾָ��ָ����
 * tag=1 ��ʾָ��ָ������
 */

// ȫ�ֱ��� pre,ָ��ǰ���ʽ���ǰ��
ThreadNode *pre=NULL;
//�����Ѿ���һ�Ŷ��������Ҹ��������н���� lchild = 0, rchild = 0��

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

void InThread(ThreadTree T){
  if(T!=NULL){
    InThread(T->lchild);
    visit(T);
    InThread(T->rchild);
  }
}

void CreateInThread(ThreadTree T){
  pre=NULL;
  if(T!=NULL){
    InThread(T);
    if(pre->rchild==NULL)//��ʵ�ǲ���Ҫ��� if �жϵ�,��Ϊ���һ������Ȼû���Һ���
      pre->rtag=1;
  }
}

int main(){
  return 0;
}