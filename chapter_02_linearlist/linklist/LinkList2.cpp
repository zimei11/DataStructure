/**
 ***************************************************
 * @file           : LinkList2.cpp
 * @author         : zi_mei
 * @brief          : 单链表模板（不带头结点）
 * @date           : 2023/8/2
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
  L=NULL;
  return true;
}

//判空
bool IsEmpty(LinkList L){
  if(L==NULL) return true;
  return false;
}

//按位序插入
bool ListInsert(LinkList &L,int i,ElemType e){
  if(i<1)
    return false;
  if(i==1){
    LNode *s=new LNode ;
    s->data=e;
    s->next=L;
    L=s;
    //这里s不能直接delete释放，因为s就是L
    return true;
  }

  LNode *p=L;
  for(int j=0;j<i-2&&p!=NULL;j++){
    p=p->next;
  }
//  或者写成下面这样，与带头结点不同，少了插在头的一次循环
//  for(int j=1;j<i-1&&p!=NULL;j++){
//    p=p->next;
//  }
  if(p==NULL)
    return false;
  LNode *s=new LNode ;
  s->data=e;
  s->next=p->next;
  p->next=s;
  return true;
}

//按位序删除
bool ListDelete(LinkList &L,int i,ElemType &e){
  if(i<1)
    return false;
  if(i==1){
    LNode *s=L;
    L=s->next;
    e=s->data;
    delete s;
    return true;
  }
//  下面是 偷天换日 版本的写法
//  if(i==1){
//    e=L->data;
//
//    LNode *s=L->next;
//    L->data=s->data;
//    L->next=s->next;
//    delete s;
//    return true;
//  }
  LNode *p=L;
  for(int j=0;j<i-2&&p!=NULL;j++){
    p=p->next;
  }
  if(p==NULL)
     return false;
  LNode *s=p->next;
  e=s->data;
  p->next=s->next;
  delete s;
  return true;
}

//打印
void PrintList(LinkList L){
  LNode *p=L;//这里可直接用L,不用使用p,因为是值传递
  while(p!=NULL){
    cout<<p->data<<" ";
    p=p->next;
  }
  cout<<endl;
}

int main(){
  LinkList L;
  InitList(L);
  ListInsert(L,1,2);
  ListInsert(L,2,3);
  ListInsert(L,2,1);
  PrintList(L);

  int elem;
  ListDelete(L,1,elem);
  cout<<"delete elem:"<<elem<<endl;
  PrintList(L);

  ListDelete(L,2,elem);
  cout<<"delete elem:"<<elem<<endl;
  PrintList(L);
  return 0;
}