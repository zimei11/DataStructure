/**
 ***************************************************
 * @file           : PTree.cpp
 * @author         : zi_mei
 * @brief          : ˳��洢��˫�ױ�ʾ����
 * @date           : 2023/10/17
 ***************************************************
 */


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define MAX_TREE_SIZE 100
#define ElemType int

using namespace std;

typedef struct{
  int parent;
  ElemType data;
}PTNode;

typedef struct {
  PTNode node[MAX_TREE_SIZE];
  int n;
}PTree;

int main(){
  return 0;
}