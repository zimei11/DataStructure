/**
 ***************************************************
 * @file           : UFSet.cpp
 * @author         : zi_mei
 * @brief          : 并查集
 * @date           : 2023/10/17
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define SIZE 13

using namespace std;

int S[SIZE];//某元素的父亲结点

void Initial(int S[]){
  for(int i=0;i<SIZE;i++){
    S[i]=-1;
  }
}

//返回某元素的根结点
int Find(int S[],int x){
  while(S[x]>=0){
    x=S[x];
  }
  return x;
}

//Root1=Find(elem1) Root2=Find(elem2)
void Union(int S[],int Root1,int Root2){
  if(S[Root1]==S[Root2]) return ;
  S[Root1]=Root2;
}

//下面是优化版本

//如果S[x]不是指向根结点，那么找到他的根结点，
//直接让查找路径上的所有结点都挂在根结点上
int Find2(int S[],int x){
  while(S[x]>=0){
    S[x]=Find2(S,x);
  }
  return S[x];
}

// 造成 Find 时间复杂度高的原因：
// 树太高了，我们在合并两个集合的时候，
// 如果让大树合并到小树上，就会让树变得更高，
// 所以我们在合并的时候，让小树合并到大树上。
void Union2(int S[],int Root1,int Root2){
  if(Root1==Root2) return ;
  if(abs(S[Root2])<abs(S[Root1])){
    S[Root1]+=S[Root2];
    S[Root2]=Root1;
  }else{
    S[Root2]+=S[Root1];
    S[Root1]=Root2;
  }
}

int main(){
  return 0;
}
