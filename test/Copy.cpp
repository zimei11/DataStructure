/**
 ***************************************************
 * @file           : Copy.cpp
 * @author         : zi_mei
 * @brief          : None
 * @date           : 2023/7/25
 ***************************************************
 */

// 线性表前后互换
// 123 4567
#include <bits/stdc++.h>
using namespace std;
#define Max 50
struct sqlist {
  int a[Max] = {1, 2, 3, 4, 5, 6, 7};
  int length = 7;
};
void reverse(sqlist &L, int left, int right) {
  for (int i = 0; i < (right - left + 1) / 2; i++) {
    int t = L.a[left + i];
    L.a[left + i] = L.a[right - i];
    L.a[right - i] = t;
  }
}
void prin(sqlist L) {
  for (int i = 0; i < L.length; i++)
    cout << L.a[i] << " ";
  cout << endl;
}
void change(sqlist &L, int m, int n) {
  cout << "整个逆置：" << endl;
  reverse(L, 0, m + n - 1);
  prin(L);
  cout << "前n个逆置" << endl;
  reverse(L, 0, n - 1);
  prin(L);
  cout << "后m个逆置即最终结果" << endl;
  reverse(L, n, m + n - 1);
  prin(L);
}
int main() {
  sqlist L;
  change(L, 3, 4); // m 123 n  4567
  return 0;
}