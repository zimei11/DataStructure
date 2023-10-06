/**
 ***************************************************
 * @file           : ThreadTree.cpp
 * @author         : zi_mei
 * @brief          : 二叉树的线索化（中序）
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
 * 传统方法找中序前驱
 */

/*
typedef struct BiTNode{
  struct BiTNode *lchild,*rchild;
  ElemType data;
}BiTNode,*BiTree;
BiTNode *p; //p指向目标结点，即找p的前驱
BiTNode *pre=NULL; //pre指向当前访问结点的前驱
BiTNode *final=NULL; //用于记录最终结果

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
 * 中序线索化代码
 */

typedef struct ThreadNode{
  ElemType data;
  struct ThreadNode *lchild,*rchild;
  int ltag,rtag;
}ThreadNode,*ThreadTree;

/*
 * tag=0 表示指针指向孩子
 * tag=1 表示指针指向线索
 */

// 全局变量 pre,指向当前访问结点的前驱
ThreadNode *pre=NULL;
//假设已经有一颗二叉树（且该树的所有结点有 lchild = 0, rchild = 0）

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
    if(pre->rchild==NULL)//其实是不需要这个 if 判断的,因为最后一个结点必然没有右孩子
      pre->rtag=1;
  }
}

int main(){
  return 0;
}