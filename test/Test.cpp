/**
 ***************************************************
 * @file           : Test.cpp
 * @author         : zi_mei
 * @brief          : None
 * @date           : 2023/7/23
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

void PrintList(SqList L) {
  for (int i = 0; i < L.length; i++) {
    cout << L.data[i] << " ";
  }
  cout << endl;
}

void InitList(SqList &L) {
  L.length = 11;
  L.data[0] = 1, L.data[1] = 2, L.data[2] = 2, L.data[3] = 2, L.data[4] = 2,
  L.data[5] = 3, L.data[6] = 3, L.data[7] = 3, L.data[8] = 4, L.data[9] = 4,
  L.data[10] = 5;
}

void DelSame(SqList &L) {
  int k = 0;
  for (int i = 1; i < L.length; i++) {
    if (L.data[i] != L.data[k]) {
      L.data[k++] = L.data[k];
    }
  }
  L.length = k;
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

  DelSame(list);
  PrintList(list);

  return 0;
}