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
#include<cstdio>

#define ElemType int

using namespace std;

typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode,*LinkList;

//��ʼ������ͷ��㣩
bool InitList(LinkList &L){
  L=new LNode;//����һ��ͷ���
  if(L==NULL)
    return false;
  L->next=NULL;
  return true;
}

//�пգ���ͷ��㣩
bool IsEmpty(LinkList L){
  if(L->next==NULL)
    return true;
  return false;
}

//��λ����
LNode * GetElem(LinkList L,int i){
  if(i<0) return NULL;//i=0�᷵��ͷ���
  LNode *p=L;
  for(int j=0;j<i&&p!=NULL;j++){
    p=p->next;
  }
  return p;
}

//��ֵ����
LNode * LocateElem(LinkList L,ElemType e){
  LNode *p=L->next;
  while(p!=NULL&&p->data!=e){
    p=p->next;
  }
  return p;
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
  LNode *p= GetElem(L,i-1);
//  ������ LNode *p= GetElem(L,i-1);�ȼ�
//  LNode *p=L;
//  for(int j=0;j<i-1&&p!=NULL;j++){
//    p=p->next;
//  }

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

//���
int Length(LinkList L){
  int len=0;
  LNode *p=L->next;
  while(p!=NULL){
     p=p->next;
     len++;
  }
  return len;
}

//������Ľ��� ͷ�巨
void ListHeadInsert(LinkList &L){
  int x;
  LNode *s;

  L=new LNode ;
  L->next=NULL;

//  while(scanf("%d",&x)!=EOF){//end of file ctrl+z����
  cin>>x;
  while(x!=999){
     s=new LNode ;
     s->data=x;
     s->next=L->next;
     L->next=s;
     cin>>x;
  }
}

//������Ľ��� β�巨
void ListTailInsert(LinkList &L){
  int x;
  L=new LNode ;
  L->next=NULL;

  LNode *s,*p=L;

//  while(scanf("%d",&x)!=EOF) { // end of file ctrl+z����
  cin>>x;
  while (x!=999){
     s = new LNode;
     s->data=x;
     p->next=s;
     p=s;
     cin>>x;
  }
  p->next=NULL;
}

//��ӡ����ͷ��㣩
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

  cout<<"Please enter the elements "
          "of the head insertion method:(end with 999)"<<endl;
  ListHeadInsert(L);
  PrintList(L);

  cout<<"Please enter the elements "
          "of the tail insertion method:(end with 999)"<<endl;
  ListTailInsert(L);
  PrintList(L);
  return 0;
}