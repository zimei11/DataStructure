/**
 ***************************************************
 * @file           : SLinkList.cpp
 * @author         : zi_mei
 * @brief          : 静态链表
 * @date           : 2023/8/5
 ***************************************************
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

//#define ElemType int
#define MaxSize 10

typedef int ElemType;

using namespace std;

typedef struct {
  ElemType data;
  int next;
}SLinkList[MaxSize];

/**
 * 初始化静态链表：
 * 1.把 a[0] 的 next 设为 -1
 * 2.把其他结点的 next 设为一个特殊值用来表示结点空闲，如 -2
 *
 * 插入位序为 i 的结点：
 * 1.找到一个空的结点，存入数据元素
 * 2.从头结点出发找到位序为 i-1 的结点
 * 3.修改新结点的 next
 * 4.修改 i-1 号结点的 next
 *
 * 删除某个结点：
 * 1.从头结点出发找到前驱结点
 * 2.修改前驱结点的游标
 * 3.被删除结点 next 设为 -2
**/

int main(){
  SLinkList L;
  return 0;
}