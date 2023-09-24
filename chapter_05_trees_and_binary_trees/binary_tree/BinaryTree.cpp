/**
 ***************************************************
 * @file           : BinaryTree.cpp
 * @author         : zi_mei
 * @brief          : ��������˳��洢
 * @date           : 2023/9/16
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define MaxSize 1000

using namespace std;

typedef int ElemType;

struct TreeNode{
  ElemType value;
  bool isEmpty;
};

/*
 * i�����ӣ�2i
 * i���Һ��ӣ�2i+1
 * i�ĸ��ڵ㣺[i/2]����ȡ��
 * i���ڵĲ�Σ�[log(i)]����ȡ��+1��[log(i+1)]����ȡ��
 *
 * ����ȫ����������n���ڵ�
 * i�����ӣ�2i<=n
 * i���Һ��ӣ�2i+1<=n
 * iΪҶ�ӽڵ㣺[i>n/2]����ȡ��
 */

int main(){
  TreeNode t[MaxSize];

  for(int i=0;i<MaxSize;i++){
    t[i].isEmpty=true;
  }
  return 0;
}