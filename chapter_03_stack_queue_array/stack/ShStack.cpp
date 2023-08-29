/**
 ***************************************************
 * @file           : ShStack.cpp
 * @author         : zi_mei
 * @brief          : À≥–Úπ≤œÌ’ª
 * @date           : 2023/8/11
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int
#define MaxSize 10

using namespace std;

typedef struct{
  ElemType data[MaxSize];
  int top0;
  int top1;
}ShStack;

bool InitStack(ShStack &S){
  S.top0=-1;
  S.top1=MaxSize;
  return true;
}

bool StackIsEmpty(ShStack S){
  if(S.top0+1==S.top1)
    return false;
  return true;
}

int main(){
  ShStack S;
  return 0;
}