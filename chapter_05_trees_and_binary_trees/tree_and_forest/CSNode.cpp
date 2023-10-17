/**
 ***************************************************
 * @file           : CSNode'.cpp
 * @author         : zi_mei
 * @brief          : 顺序+链式（孩子兄弟表示法）
 * @date           : 2023/10/17
 ***************************************************
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

typedef struct CSNode{
  struct CSNode *firstchild,*nextsibling;
  ElemType data;
}CSNode,*CSTree;

int main(){
  return 0;
}