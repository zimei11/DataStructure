/**
 ***************************************************
 * @file           : SqStack.cpp
 * @author         : zi_mei
 * @brief          : ˳��ջ
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
 * ע����Ŀ����ջ��ʱ�򣬶���ջ��ָ������Ϊ����
 * ����һ�ֳ���������Ϊ����Ϊ 0����ʱջ��ָ������ż�������Ԫ�ص�λ�ã�
 * �Դ�������ظ��ģ�
 * // ��ʼ��ջ
 * void InitStack(SqStack &S){
 *     S.top = 0;               // ��ʼ��ջ��ָ��
 * }
 *
 * // �ж�ջ��
 * bool StackEmpty(SqStack S){
 *   if (S.top == 0) return true;
 *   else return false;
 * }
 *
 * // ��ջ����
 * S.data[S.top ++] = x;
 *
 * // ��ջ����
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