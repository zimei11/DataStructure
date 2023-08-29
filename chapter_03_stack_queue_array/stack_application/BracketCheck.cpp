/**
 ***************************************************
 * @file           : BracketCheck.cpp
 * @author         : zi_mei
 * @brief          : None
 * @date           : 2023/8/22
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType char
#define MaxSize 10

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
  return true;
}

bool Pop(SqStack &S,ElemType &x){
  if(StackIsEmpty(S))
    return false;
  x=S.data[S.top--];
  return true;
}

bool bracketCheck(char str[],int length){
  SqStack S;
  InitStack(S);

  for(int i=0;i<length;i++){
    if(str[i]=='('||str[i]=='['||str[i]=='{'){
      Push(S,str[i]);
    }else{
      char c;
      if(StackIsEmpty(S)) return false;
      Pop(S,c);
      if(str[i]==')'&&c!='(')  return false;
      else if(str[i]==']'&&c!='[') return false;
      else if(str[i]=='}'&&c!='{') return false;
    }
  }
  return StackIsEmpty(S);
}

int main(){
  char str[20];
  cin>>str;
  if (bracketCheck(str, strlen(str)))
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}