/**
 ***************************************************
 * @file           : LinkList2.cpp
 * @author         : zi_mei
 * @brief          : ������ģ�壨����ͷ��㣩
 * @date           : 2023/8/2
 ***************************************************
 */
#include<iostream>
#include<cstring>
#include<algorithm>

#define ElemType int

using namespace std;

typedef struct LNode{
  ElemType data;
  struct LNode *next;
}LNode,*LinkList;

//��ʼ��
bool InitList(LinkList &L){
  L=NULL;
  return true;
}

//�п�
bool IsEmpty(LinkList L){
  if(L==NULL) return true;
  return false;
}

//��λ�����
bool ListInsert(LinkList &L,int i,ElemType e){
  if(i<1)
    return false;
  if(i==1){
    LNode *s=new LNode ;
    s->data=e;
    s->next=L;
    L=s;
    //����s����ֱ��delete�ͷţ���Ϊs����L
    return true;
  }

  LNode *p=L;
  for(int j=0;j<i-2&&p!=NULL;j++){
    p=p->next;
  }
//  ����д���������������ͷ��㲻ͬ�����˲���ͷ��һ��ѭ��
//  for(int j=1;j<i-1&&p!=NULL;j++){
//    p=p->next;
//  }
  if(p==NULL)
    return false;
  LNode *s=new LNode ;
  s->data=e;
  s->next=p->next;
  p->next=s;
  return true;
}

//��λ��ɾ��
bool ListDelete(LinkList &L,int i,ElemType &e){
  if(i<1)
    return false;
  if(i==1){
    LNode *s=L;
    L=s->next;
    e=s->data;
    delete s;
    return true;
  }
//  ������ ͵�컻�� �汾��д��
//  if(i==1){
//    e=L->data;
//
//    LNode *s=L->next;
//    L->data=s->data;
//    L->next=s->next;
//    delete s;
//    return true;
//  }
  LNode *p=L;
  for(int j=0;j<i-2&&p!=NULL;j++){
    p=p->next;
  }
  if(p==NULL)
     return false;
  LNode *s=p->next;
  e=s->data;
  p->next=s->next;
  delete s;
  return true;
}

//��ӡ
void PrintList(LinkList L){
  LNode *p=L;//�����ֱ����L,����ʹ��p,��Ϊ��ֵ����
  while(p!=NULL){
    cout<<p->data<<" ";
    p=p->next;
  }
  cout<<endl;
}

int main(){
  LinkList L;
  InitList(L);
  ListInsert(L,1,2);
  ListInsert(L,2,3);
  ListInsert(L,2,1);
  PrintList(L);

  int elem;
  ListDelete(L,1,elem);
  cout<<"delete elem:"<<elem<<endl;
  PrintList(L);

  ListDelete(L,2,elem);
  cout<<"delete elem:"<<elem<<endl;
  PrintList(L);
  return 0;
}