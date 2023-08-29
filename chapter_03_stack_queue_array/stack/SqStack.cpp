/**
 ***************************************************
 * @file           : SqStack.cpp
 * @author         : zi_mei
 * @brief          : 顺序栈
 * @date           : 2023/8/10
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int
#define MaxSize 50

using namespace std;

typedef struct{
  ElemType data[MaxSize];
  int top;
}SqStack;

void InitStack(SqStack &S){
  S.top=-1;
}

bool StackIsEmpty(SqStack S){
  if(S.top==-1)
    return true;
  return false;
}

bool Push(SqStack &S,ElemType x){
  if(S.top+1==MaxSize)
    return false;
  S.data[++S.top]=x;
  /*
   S.top = S.top + 1;
   S.data[S.top] = x;
   */
  return true;
}

bool Pop(SqStack &S,ElemType &x){
  if(S.top==-1)
    return false;
  x=S.data[S.top--];
  /*
   x = S.data[S.top];
   S.top = S.top - 1;
   */
  return true;
}

bool GetTop(SqStack S,ElemType &x){
  if(S.top==-1)
    return false;
  x=S.data[S.top];
  return true;
}

/*
 * 注意题目定义栈的时候，对于栈顶指针设置为几，
 * 还有一种常见的设置为设其为 0，此时栈顶指针代表着即将插入元素的位置，
 * 对代码有相关更改：
 * // 初始化栈
 * void InitStack(SqStack &S){
 *     S.top = 0;               // 初始化栈顶指针
 * }
 *
 * // 判断栈空
 * bool StackEmpty(SqStack S){
 *   if (S.top == 0) return true;
 *   else return false;
 * }
 *
 * // 入栈操作
 * S.data[S.top ++] = x;
 *
 * // 出栈操作
 * x = S.data[-- S.top];
 */

int main(){
  SqStack S;
  InitStack(S);
  Push(S,1);

  ElemType x;
  GetTop(S,x);
  cout<<x<<endl;
  return 0;
}