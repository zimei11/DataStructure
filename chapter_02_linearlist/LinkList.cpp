/**
 ***************************************************
 * @file           : LinkList.cpp
 * @author         : zi_mei
 * @brief          : ������ģ�壨��ͷ��㣩
 * @date           : 2023/8/1
 ***************************************************
 */

#include<iostream>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode,*LinkList;

//��ʼ��
bool InitList(LinkList &L){
  L=new LNode;//����һ��ͷ���
  if(L==NULL)
    return false;
  L->next=NULL;
  return true;
}

//�п�
bool IsEmpty(LinkList L){
  if(L->next==NULL)
    return true;
  return false;
}

//ǰ�巨��p�ڵ�֮ǰ����e
bool InsertPriorNode(LNode *p,ElemType e){
  if(p==NULL)
    return false;
  LNode * s=new LNode;
  if(s==NULL)
    return false;
  s->next=p->next;
  s->data=p->data;
  p->next=s;
  p->data=e;
  return true;
}

//��巨
bool InsertNextNode(LNode *p,ElemType e){
  if(p==NULL)
    return false;
  LNode * s=new LNode ;
  if(s==NULL)
    return false;
  s->data=e;
  s->next=p->next;
  p->next=s;

  return true;
}

//��λ����루��ͷ��㣩
bool ListInsert(LinkList &L,int i,ElemType e){
  if(i<1)
    return false;
  LNode *p=L;
  for(int j=0;j<i-1&&p!=NULL;j++){
    p=p->next;
  }

  return InsertNextNode(p,e);
//  ������ return InsertNextNode(p,e) �ȼ�
//  if(p==NULL)
//    return false;
//  LNode *s=new LNode ;
//  s->data=e;
//  s->next=p->next;
//  p->next=s;
//  return true;
}

//��λ��ɾ������ͷ��㣩
bool ListDelete(LinkList &L,int i,ElemType &e){
  if(i<1)
    return false;
  LNode *p=L;
  for(int j=0;j<i-1&&p!=NULL;j++){
    p=p->next;
  }
  if(p==NULL||p->next==NULL)
    return false;
  LNode *q=p->next;
  e=q->data;
  p->next=q->next;
  delete q;
  return true;
}

//ָ���ڵ�ɾ��
bool DeleteNode(LNode *p){
  if(p==NULL)
     return false;
  LNode *q=p->next;
  p->data=q->data;
  p->next=q->next;
  delete q;
  return true;
}

//��ӡ
void PrintList(LinkList L){
  L=L->next;
  while(L!=NULL){
    cout<<L->data<<" ";
    L=L->next;
  }
  cout<<endl;
}

int main(){
  LinkList L;
  InitList(L);
  InsertNextNode(L,1);
  InsertPriorNode(L->next,2);
  ListInsert(L,3,3);
  PrintList(L);

  int elem;
  ListDelete(L,1,elem);
  cout<<"delete elem:"<<elem<<endl;
  PrintList(L);
  DeleteNode(L->next);
  cout<<"delete head"<<endl;
  PrintList(L);
  return 0;
}