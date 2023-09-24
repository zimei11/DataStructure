/**
 ***************************************************
 * @file           : PreOrder.cpp
 * @author         : zi_mei
 * @brief          : 先序遍历，中序遍历，后序遍历
 * @date           : 2023/9/24
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

typedef struct BiNode{
  ElemType data;
  struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

void visit(BiNode*);

void PreOrder(BiTree T){
  if(T!=NULL){
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
  }
}

void InOrder(BiTree T){
  if(T!=NULL){
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
  }
}

void PostOrder(BiTree T){
  if(T!=NULL){
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
  }
}

int main(){
  return 0;
}