/**
 ***************************************************
 * @file           : CDLinkList.cpp
 * @author         : zi_mei
 * @brief          : Ñ­»·Ë«ÏòÁ´±í
 * @date           : 2023/8/6
 ***************************************************
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

typedef struct CDNode{
  ElemType data;
  struct CDNode *next;
  struct CDNode *prior;
}DNode,*DLinkList;

bool InitDLinkList(DLinkList &L){
  L=new DNode ;
  if(L==NULL)
    return false;
  L->next=L;
  L->prior=L;
  return true;
}

bool IsEmpty(DLinkList L){
  if(L->next==L)
    return true;
  return false;
}

bool isTail(DLinkList L,DNode *p){
  if(p->next==L)
    return true;
  return false;
}

int main(){
  DLinkList L;
  InitDLinkList(L);
  return 0;
}