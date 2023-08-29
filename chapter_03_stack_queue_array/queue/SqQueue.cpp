/**
 ***************************************************
 * @file           : SqQueue.cpp
 * @author         : zi_mei
 * @brief          : 循环队列（顺序表，留出一个结点不用法）
 * @date           : 2023/8/12
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int
#define MaxSize 10

using namespace std;

typedef struct {
  ElemType data[MaxSize];
  int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q){
  Q.front=Q.rear=0;
}

bool QueueIsEmpty(SqQueue Q){
  if(Q.front==Q.rear)
    return true;
  return false;
}

bool EnQueue(SqQueue &Q,ElemType x){
  if((Q.rear+1)%MaxSize==Q.front)
    return false;
  Q.data[Q.rear]=x;
  Q.rear=(Q.rear+1)%MaxSize;
  return true;
}

bool DeQueue(SqQueue &Q,ElemType &x){
  if(Q.rear==Q.front)
    return false;
  x=Q.data[Q.front];
  Q.front=(Q.front+1)%MaxSize;
  return true;
}

bool GetHead(SqQueue Q,ElemType &x){
  if(Q.front==Q.rear)
    return false;
  x=Q.data[Q.front];
  return true;
}

int main(){
  SqQueue Q;
  InitQueue(Q);
  EnQueue(Q,1);
  ElemType x;
  GetHead(Q,x);
  cout<<x<<endl;
  return 0;
}
