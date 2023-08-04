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
#include<cstdio>

#define ElemType int

using namespace std;

typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode,*LinkList;

//初始化（带头结点）
bool InitList(LinkList &L){
  L=new LNode;//分配一个头结点
  if(L==NULL)
    return false;
  L->next=NULL;
  return true;
}

//判空（带头结点）
bool IsEmpty(LinkList L){
  if(L->next==NULL)
    return true;
  return false;
}

//按位查找
LNode * GetElem(LinkList L,int i){
  if(i<0) return NULL;//i=0会返回头结点
  LNode *p=L;
  for(int j=0;j<i&&p!=NULL;j++){
    p=p->next;
  }
  return p;
}

//按值查找
LNode * LocateElem(LinkList L,ElemType e){
  LNode *p=L->next;
  while(p!=NULL&&p->data!=e){
    p=p->next;
  }
  return p;
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
  LNode *p= GetElem(L,i-1);
//  与上面 LNode *p= GetElem(L,i-1);等价
//  LNode *p=L;
//  for(int j=0;j<i-1&&p!=NULL;j++){
//    p=p->next;
//  }

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

//求表长
int Length(LinkList L){
  int len=0;
  LNode *p=L->next;
  while(p!=NULL){
     p=p->next;
     len++;
  }
  return len;
}

//单链表的建立 头插法
void ListHeadInsert(LinkList &L){
  int x;
  LNode *s;

  L=new LNode ;
  L->next=NULL;

//  while(scanf("%d",&x)!=EOF){//end of file ctrl+z结束
  cin>>x;
  while(x!=999){
     s=new LNode ;
     s->data=x;
     s->next=L->next;
     L->next=s;
     cin>>x;
  }
}

//单链表的建立 尾插法
void ListTailInsert(LinkList &L){
  int x;
  L=new LNode ;
  L->next=NULL;

  LNode *s,*p=L;

//  while(scanf("%d",&x)!=EOF) { // end of file ctrl+z结束
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

//打印（带头结点）
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