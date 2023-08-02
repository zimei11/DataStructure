/**
 ***************************************************
 * @file           : LinkList.cpp
 * @author         : zi_mei
 * @brief          : 单链表模板（带头结点）
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

//初始化
bool InitList(LinkList &L){
  L=new LNode;//分配一个头结点
  if(L==NULL)
    return false;
  L->next=NULL;
  return true;
}

//判空
bool IsEmpty(LinkList L){
  if(L->next==NULL)
    return true;
  return false;
}

//前插法，p节点之前插入e
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

//后插法
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

//按位序插入（带头结点）
bool ListInsert(LinkList &L,int i,ElemType e){
  if(i<1)
    return false;
  LNode *p=L;
  for(int j=0;j<i-1&&p!=NULL;j++){
    p=p->next;
  }

  return InsertNextNode(p,e);
//  与上面 return InsertNextNode(p,e) 等价
//  if(p==NULL)
//    return false;
//  LNode *s=new LNode ;
//  s->data=e;
//  s->next=p->next;
//  p->next=s;
//  return true;
}

//按位序删除（带头结点）
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

//指定节点删除
bool DeleteNode(LNode *p){
  if(p==NULL)
     return false;
  LNode *q=p->next;
  p->data=q->data;
  p->next=q->next;
  delete q;
  return true;
}

//打印
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