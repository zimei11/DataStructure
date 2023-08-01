/**
 ***************************************************
 * @file           : LinkList.cpp
 * @author         : zi_mei
 * @brief          : 单链表模板
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

bool InitList(LinkList &L){
  L=new LNode;//分配一个头结点
  if(L==NULL)
    return false;
  L->next=NULL;
  return true;
}

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
bool ListInsert(LinkList L,int i,ElemType e){

}

void PrintList(LinkList &L){
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
  PrintList(L);
  return 0;
}