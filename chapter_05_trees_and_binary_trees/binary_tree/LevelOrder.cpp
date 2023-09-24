/**
 ***************************************************
 * @file           : LevelOrder.cpp
 * @author         : zi_mei
 * @brief          : 层序遍历
 * @date           : 2023/9/24
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType char

using namespace std;

//链式二叉树
typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//链式队列
typedef struct LinkNode{
  BiTNode *data;
  struct LinkNode *next;
}LinkNode;

typedef struct {
  LinkNode *front,*rear;
}LinkQueue;

//访问节点操作
void visit(BiTNode* p);

//队列操作
void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q,BiTree x);
void DeQueue(LinkQueue &Q,BiTree &x);

//层序遍历
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