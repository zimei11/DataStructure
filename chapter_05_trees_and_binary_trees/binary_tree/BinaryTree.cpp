/**
 ***************************************************
 * @file           : BinaryTree.cpp
 * @author         : zi_mei
 * @brief          : 二叉树的顺序存储
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
 * i的左孩子：2i
 * i的右孩子：2i+1
 * i的父节点：[i/2]向下取整
 * i所在的层次：[log(i)]向下取整+1，[log(i+1)]向上取整
 *
 * 若完全二叉树中有n个节点
 * i有左孩子：2i<=n
 * i有右孩子：2i+1<=n
 * i为叶子节点：[i>n/2]向下取整
 */

int main(){
  TreeNode t[MaxSize];

  for(int i=0;i<MaxSize;i++){
    t[i].isEmpty=true;
  }
  return 0;
}