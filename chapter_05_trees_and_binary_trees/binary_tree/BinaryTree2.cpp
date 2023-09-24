/**
 ***************************************************
 * @file           : BinaryTree2.cpp
 * @author         : zi_mei
 * @brief          : 二叉树的链式存储
 * @date           : 2023/9/24
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct ElemType{
  int value;
};

typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;
//  struct BiTNode *parent;//三叉链表，父结点指针
}BiTNode,*BiTree;

int main(){
  //定义空树
  BiTree root = NULL;

  //插入根结点
  root=new BiTNode;
  root->data={1};
  root->lchild=NULL;
  root->rchild=NULL;

  //插入新结点
  BiTNode * p=new BiTNode ;
  p->data={2};
  p->rchild=NULL;
  p->lchild=NULL;
  root->lchild=p;
  return 0;
}