/**
 ***************************************************
 * @file           : sqlist.cpp
 * @author         : zi_mei
 * @brief          : 顺序表模板
 * @date           : 2023/7/18
 ***************************************************
 */

#include <algorithm>
#include <cstring>
#include <iostream>

#define MaxSize 50
#define InitSize 50

typedef int ElemType;

using namespace std;

//定义顺序表 静态分配
typedef struct {
  ElemType data[MaxSize];
  int length;
} SqList;

//定义顺序表 动态分配
typedef struct {
  ElemType *data;
  int length;
  //  int MaxSize;
} SqList2;

//按位序插入
bool ListInsert(SqList &L, int i, ElemType e) {
  if (i < 1 || i > L.length) {
    return false;
  }
  if (i >= MaxSize) {
    return false;
  }
  for (int j = L.length; j >= i; j--) {
    L.data[j] = L.data[j - 1];
  }
  L.data[i - 1] = e;
  L.length++;
  return true;
}

//按位序删除
bool ListDelete(SqList &L, int i, ElemType &e) {
  if (i < 1 || i > L.length) {
    return false;
  }
  e = L.data[i - 1];
  for (int j = i - 1; j < L.length - 1; j++) {
    L.data[j] = L.data[j + 1];
  }
  L.length--;
  return true;
}

//按元素查找
int LocateElem(SqList L, ElemType e) {
  for (int i = 0; i < L.length; i++) {
    if (L.data[i] == e) {
      return i + 1;
    }
  }
  return 0;
}

//打印
void PrintList(SqList L) {
  for (int i = 0; i < L.length; i++) {
    cout << L.data[i] << " ";
  }
  cout << endl;
}

//初始化顺序表 静态分配
void InitList(SqList &L) {
  L.length = 10;
  for (int i = 0; i < L.length; i++) {
    L.data[i] = i + 1;
  }
}

//初始化顺序表 动态分配
void InitList2(SqList2 &L) {
  L.length = 10;
  L.data = new ElemType[InitSize];
  for (int i = 0; i < L.length; i++) {
    L.data[i] = i + 1;
  }
}


int main() {
  SqList L;
  InitList(L);
  ListInsert(L, 2, 8);
  cout<<"Insert element 8 successfully at position 2"<<endl;
  PrintList(L);
  int deleteElem;
  ListDelete(L, 2, deleteElem);
  cout << "The location of the deleted element 2: " << LocateElem(L, 2) << endl;
  PrintList(L);

  SqList2 L2;
  InitList2(L2);
  return 0;
}
