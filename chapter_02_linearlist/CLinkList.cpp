/**
 ***************************************************
 * @file           : CLinkList.cpp
 * @author         : zi_mei
 * @brief          : Ñ­»·Á´±í
 * @date           : 2023/8/6
 ***************************************************
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

typedef struct CNode{
  ElemType data;
  struct CNode *next;
}LNode,*LinkList;

bool InitLinkList(LinkList &L){
  L=new LNode;
  if(L==NULL)
    return false;
  L->next=L;
  return true;
}

bool IsEmpty(LinkList L){
  if(L->next==L)
    return true;
  return false;
}

bool isTail(LinkList L,LNode *p){
  if(p->next==L)
    return true;
  return false;
}

int main(){
  LinkList L;
  InitLinkList(L);
  return 0;
}