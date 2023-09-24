/**
 ***************************************************
 * @file           : LevelOrder.cpp
 * @author         : zi_mei
 * @brief          : �������
 * @date           : 2023/9/24
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType char

using namespace std;

//��ʽ������
typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//��ʽ����
typedef struct LinkNode{
  BiTNode *data;
  struct LinkNode *next;
}LinkNode;

typedef struct {
  LinkNode *front,*rear;
}LinkQueue;

//���ʽڵ����
void visit(BiTNode* p);

//���в���
void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q,BiTree x);
void DeQueue(LinkQueue &Q,BiTree &x);

//�������
void LevelOrder(BiTree T){
  LinkQueue Q;
  InitQueue(Q);
  EnQueue(Q,T);
  BiTNode* p;
  while(!IsEmpty(Q)){
    DeQueue(Q,p);
    visit(p);
    if(p->lchild!=NULL)
      EnQueue(Q,p->lchild);
    if(p->rchild!=NULL)
      EnQueue(Q,p->rchild);
  }
}

int main(){
  return 0;
}