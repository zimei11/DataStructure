/**
 ***************************************************
 * @file           : DLinkList.cpp
 * @author         : zi_mei
 * @brief          : ˫����
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

//��ʼ��
bool InitDLinkList(DLinkList &L){
  L=new DNode;
  if(L==NULL)
     return false;
  L->next=NULL;
  L->prior=NULL;
  return true;
}

//�п�
bool IsEmpty(DLinkList L){
  if(L->next==NULL)
     return true;
  return false;
}

//p�ڵ�����s�ڵ�
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

//ɾ��p�ڵ��̽ڵ�
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

//ɾ��˫����
bool DestroyList(DLinkList &L){
  while(L->next!=NULL){
     DeleteNextNode(L);
  }
  delete L;
  L=NULL;//��ֹ����Ұָ��
  return true;
}

//�������
void NextTraversal(DNode *p){
  while(p!=NULL){
     cout<<p->data<<" ";
     p=p->next;
  }
  cout<<endl;
}

//ǰ�����
void PriorTraversal(DNode *p){
  while(p!=NULL){
     cout<<p->data<<" ";
     p=p->prior;
  }
  cout<<endl;
}

//ǰ�����������ͷ��㣩
void PriorTraversalSkipHead(DNode *p){
  while(p->prior!=NULL){
     cout<<p->data<<" ";
     p=p->prior;
  }
  cout<<endl;
}

//����4����㣬1234
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
//  ����4����㣬1234
  InsertDNodes(L);
  NextTraversal(L->next);

  DeleteNextNode(L);
  NextTraversal(L->next);

  DestroyList(L);
  cout<<L<<endl;
  return 0;
}