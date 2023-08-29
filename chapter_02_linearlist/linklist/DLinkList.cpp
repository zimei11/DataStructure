/**
 ***************************************************
 * @file           : DLinkList.cpp
 * @author         : zi_mei
 * @brief          : 双链表
 * @date           : 2023/8/6
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

typedef struct DNode{
  ElemType data;
  struct DNode *next,*prior;
}DNode ,*DLinkList;

//初始化
bool InitDLinkList(DLinkList &L){
  L=new DNode;
  if(L==NULL)
     return false;
  L->next=NULL;
  L->prior=NULL;
  return true;
}

//判空
bool IsEmpty(DLinkList L){
  if(L->next==NULL)
     return true;
  return false;
}

//p节点后插入s节点
bool InsertNextNode(DNode *p,DNode *s){
  if(p==NULL||s==NULL)
     return false;
  s->next=p->next;
  if(p->next!=NULL)
     p->next->prior=s;
  p->next=s;
  s->prior=p;
  return true;
}

//删除p节点后继节点
bool DeleteNextNode(DNode *p){
  if(p==NULL||p->next==NULL)
     return false;
  DNode *q=p->next;
  p->next=q->next;
  if(q->next!=NULL)
     q->next->prior=p;
  delete q;
  return true;
}

//删除双链表
bool DestroyList(DLinkList &L){
  while(L->next!=NULL){
     DeleteNextNode(L);
  }
  delete L;
  L=NULL;//防止出现野指针
  return true;
}

//后项遍历
void NextTraversal(DNode *p){
  while(p!=NULL){
     cout<<p->data<<" ";
     p=p->next;
  }
  cout<<endl;
}

//前项遍历
void PriorTraversal(DNode *p){
  while(p!=NULL){
     cout<<p->data<<" ";
     p=p->prior;
  }
  cout<<endl;
}

//前项遍历（跳过头结点）
void PriorTraversalSkipHead(DNode *p){
  while(p->prior!=NULL){
     cout<<p->data<<" ";
     p=p->prior;
  }
  cout<<endl;
}

//插入4个结点，1234
void InsertDNodes(DLinkList &L){
  DNode *s;
  for(int i=1;i<=4;i++){
     s=new DNode ;
     s->data=i;
     s->next=NULL;
     InsertNextNode(L,s);
  }
}

int main(){
  DLinkList L;
  InitDLinkList(L);
//  插入4个结点，1234
  InsertDNodes(L);
  NextTraversal(L->next);

  DeleteNextNode(L);
  NextTraversal(L->next);

  DestroyList(L);
  cout<<L<<endl;
  return 0;
}