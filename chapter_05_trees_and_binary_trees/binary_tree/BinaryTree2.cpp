/**
 ***************************************************
 * @file           : BinaryTree2.cpp
 * @author         : zi_mei
 * @brief          : ����������ʽ�洢
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
//  struct BiTNode *parent;//�������������ָ��
}BiTNode,*BiTree;

int main(){
  //�������
  BiTree root = NULL;

  //��������
  root=new BiTNode;
  root->data={1};
  root->lchild=NULL;
  root->rchild=NULL;

  //�����½��
  BiTNode * p=new BiTNode ;
  p->data={2};
  p->rchild=NULL;
  p->lchild=NULL;
  root->lchild=p;
  return 0;
}