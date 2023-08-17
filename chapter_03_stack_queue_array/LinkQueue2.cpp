/**
 ***************************************************
 * @file           : LinkQueue2.cpp
 * @author         : zi_mei
 * @brief          : 队列（链式，不带头结点）
 * @date           : 2023/8/17
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

typedef struct LinkNode{
  ElemType data;
  LinkNode *next;
}LinkNode;

typedef struct LinkQueue{
  LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue &Q){
  Q.rear=NULL;
  Q.front=NULL;
}

bool IsEmpty(LinkQueue Q){
  if(Q.front==NULL)
    return true;
  return false;
}

void EnQueue(LinkQueue &Q,ElemType x){
  LinkNode *s=new LinkNode ;
  s->data=x;
  s->next=NULL;
  if(IsEmpty(Q)){
    Q.front=s;
    Q.rear=s;
  }
  else {
    Q.rear->next = s;
    Q.rear = s;
  }
}

bool DeQueue(LinkQueue &Q,ElemType &x){
  if(IsEmpty(Q))
    return false;
  LinkNode *p=Q.front;
  x=p->data;
  Q.front=p->next;
  if(Q.rear==p){
    Q.front=NULL;
    Q.rear=NULL;
  }
  delete p;
  return true;
}

int main(){
  LinkQueue Q;
  InitQueue(Q);
  return 0;
}
