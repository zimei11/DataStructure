/**
 ***************************************************
 * @file           : LinkQueue.cpp
 * @author         : zi_mei
 * @brief          : 队列（链式，带头结点）
 * @date           : 2023/8/15
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
  Q.front=Q.rear=new LinkNode ;
  Q.front->next=NULL;//此时头结点与尾节点指向头结点，让头结点指向NULL
}

bool IsEmpty(LinkQueue Q){
  if(Q.front==Q.rear)
    return true;
  return false;
}

void EnQueue(LinkQueue &Q,ElemType x){
  LinkNode *s=new LinkNode ;
  s->data=x;
  s->next=NULL;
  Q.rear->next=s;
  Q.rear=s;
}

bool DeQueue(LinkQueue &Q,ElemType &x){
  if(IsEmpty(Q))
    return false;
  LinkNode *p =Q.front->next;
  x= p->data;
  Q.front->next= p->next;
  if(Q.rear==p){
    Q.rear=Q.front;
  }
  delete p;
  return true;
}

int main(){
  LinkQueue Q;
  InitQueue(Q);
  if (IsEmpty) cout<<"YES"<<endl;

  int num_in = 0, x = 0;
  cout<<"Enter the total number of elements to be queued:"<<endl;
  cin>>num_in;
  for (int i = 0; i < num_in; i ++ ){
    cout<<"Input element"<<endl;
    cin>>x;
    EnQueue(Q, x);
  }
  return 0;
}