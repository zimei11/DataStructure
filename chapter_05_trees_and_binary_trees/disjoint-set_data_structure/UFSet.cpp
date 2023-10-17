/**
 ***************************************************
 * @file           : UFSet.cpp
 * @author         : zi_mei
 * @brief          : ���鼯
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

int S[SIZE];//ĳԪ�صĸ��׽��

void Initial(int S[]){
  for(int i=0;i<SIZE;i++){
    S[i]=-1;
  }
}

//����ĳԪ�صĸ����
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

//�������Ż��汾

//���S[x]����ָ�����㣬��ô�ҵ����ĸ���㣬
//ֱ���ò���·���ϵ����н�㶼���ڸ������
int Find2(int S[],int x){
  while(S[x]>=0){
    S[x]=Find2(S,x);
  }
  return S[x];
}

// ��� Find ʱ�临�Ӷȸߵ�ԭ��
// ��̫���ˣ������ںϲ��������ϵ�ʱ��
// ����ô����ϲ���С���ϣ��ͻ�������ø��ߣ�
// ���������ںϲ���ʱ����С���ϲ��������ϡ�
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
