/**
 ***************************************************
 * @file           : LiStack.cpp
 * @author         : zi_mei
 * @brief          : 链栈（带头结点）
 * @date           : 2023/8/10
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

typedef struct LinkNode{
  ElemType data;
  struct LinkNode *next;
}LinkNode,*LiStack;

void InitStack(LiStack &S){
  S=new LinkNode;
  S->next=NULL;
}

bool IsEmpty(LiStack S){
  if(S->next==NULL)
    return true;
  return false;
}

void Push(LiStack &S,ElemType x){
  LinkNode *q=new LinkNode ;
  q->data=x;
  q->next=S->next;
  S->next=q;
}

bool Pop(LiStack &S,ElemType &x){
  if(S->next==NULL)
    return false;
  LinkNode *q=S->next;
  x=q->data;
  S->next=q->next;
  delete q;
  return true;
}

int main(){
  LiStack S;
  InitStack(S);
  Push(S,1);
  cout<<IsEmpty(S)<<endl;
  return 0;
}