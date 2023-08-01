/**
 ***************************************************
 * @file           : Sqlist.cpp
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

typedef struct {
  ElemType data[MaxSize];
  int length;
} SqList;

typedef struct {
  ElemType *data;
  int length;
  //  int MaxSize;
} SqList2;

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

int LocateElem(SqList L, ElemType e) {
  for (int i = 0; i < L.length; i++) {
    if (L.data[i] == e) {
      return i + 1;
    }
  }
  return 0;
}

void PrintList(SqList L) {
  for (int i = 0; i < L.length; i++) {
    cout << L.data[i] << " ";
  }
  cout << endl;
}

void InitList(SqList &L) {
  L.length = 10;
  for (int i = 0; i < L.length; i++) {
    L.data[i] = i + 1;
  }
}

void InitList2(SqList2 &L) {
  L.length = 10;
  L.data = new ElemType[InitSize];
  for (int i = 0; i < L.length; i++) {
    L.data[i] = i + 1;
  }
}

// void ReverseList(SqList &L) {
//   for (int i = 0; i < L.length; i++) {
//     for (int j = 0; j + 1 < L.length - i; j++) {
//       int t = L.data[j];
//       L.data[j] = L.data[j + 1];
//       L.data[j + 1] = t;
//     }
//   }
// }

// bool DelST(SqList &L, ElemType s, ElemType t) {
//   if (s >= t || L.length == 0) {
//     return false;
//   }
//   int k = 0;
//   for (int i = 0; i < L.length; i++) {
//     if (L.data[i] < s || L.data[i] > t) {
//       L.data[k++] = L.data[i];
//     }
//   }
//   L.length = k;
//   return true;
// }

int main() {
  SqList list;
  InitList(list);
  ListInsert(list, 2, 8);
  int deleteElem;
  ListDelete(list, 2, deleteElem);
  cout << "elem 2:" << LocateElem(list, 2) << endl;
  PrintList(list);

  SqList2 list2;
  InitList2(list2);
  cout << list2.data[0] << endl;
  return 0;
}
