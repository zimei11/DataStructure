/**
 ***************************************************
 * @file           : SLinkList.cpp
 * @author         : zi_mei
 * @brief          : ��̬����
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
 * ��ʼ����̬����
 * 1.�� a[0] �� next ��Ϊ -1
 * 2.���������� next ��Ϊһ������ֵ������ʾ�����У��� -2
 *
 * ����λ��Ϊ i �Ľ�㣺
 * 1.�ҵ�һ���յĽ�㣬��������Ԫ��
 * 2.��ͷ�������ҵ�λ��Ϊ i-1 �Ľ��
 * 3.�޸��½��� next
 * 4.�޸� i-1 �Ž��� next
 *
 * ɾ��ĳ����㣺
 * 1.��ͷ�������ҵ�ǰ�����
 * 2.�޸�ǰ�������α�
 * 3.��ɾ����� next ��Ϊ -2
**/

int main(){
  SLinkList L;
  return 0;
}