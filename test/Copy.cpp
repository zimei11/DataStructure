#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
  int data;
  struct LNode* next;
}LNode, *LinkList;

void InitList(LinkList &L) {
  L = (LinkList)malloc(sizeof(LNode));    //����ͷ���
  L->next = NULL;     //ͷ���ָ���
}

bool isEmpty(LinkList L) {
  if (L->next == NULL) {
    return true;
  }
  return false;
}

LinkList HeadInsert(LinkList &L) {
  LNode* s;
  int x;
  scanf("%d", &x);
  while (x != 9999){
    s = (LinkList)malloc(sizeof(LNode));    //����һ���µĽڵ�s
    s->data = x;    //��ֵ
    s->next = L->next;  //���½ڵ��ָ����ָ��ǰL�ĵ�һ�ڵ�
    L->next = s;        //��L��ָ����ָ���½ڵ�
    scanf("%d",&x);
  }
  return L;
}

LinkList TailInsert(LinkList &L) {
  int x;  //������������
  LinkList s, r = L;  //s���´����Ľڵ㣬r������֤ÿ�ζ�ָ������һ���ڵ�
  scanf("%d", &x);
  while(x != 9999) {
    s = (LinkList)malloc(sizeof(LNode));    //����һ���µĽڵ㸳ֵ��s
    s->data = x;    //s.data��ֵ
    r->next = s;    //r��nextָ��s
    r = s;          //rָ��s����rʼ�ձ��������һ��
    scanf("%d", &x);
  }
  r->next = NULL; //��r��next��ֵΪnull
  return L;
}

void showList(LinkList L) {
  L = L->next;    //δʹ�����ã��ı�L��ֵ����������L����ı䣬�൱����L�ĸ���
  while (L != NULL){
    printf("%3d",L->data);
    L = L->next;
  }
  printf("\n");
}


int getListLength(LinkList L) {
  int i = 0;
  while (L->next != NULL) {
    L = L->next;
    i++;
  }
  return i;
}

//����Ų��ҽڵ�ֵ
LinkList getNodeByIndex(LinkList L, int index) {
  int j = 1;
  LinkList p = L->next;
  if (index == 0) {
    return L;
  }
  if (index < 1) {
    return NULL;
  }
  while (p && j < index){
    p = p->next;
    j++;
  }
  return p;
}

//��ֵ����
LinkList getNodeByValue(LinkList L, int value) {
  LinkList p = L->next;
  bool flag = false;
  while (p != NULL) {
    if (p->data == value) {
      flag = true;
      break;
    }
    p = p->next;
  }
  if (!flag) {
    printf("û�в��ҵ���ֵ\n");
  }
  return p;
}

//�м����
LinkList Midinsert(LinkList &L, int index, int value) {
  int len = getListLength(L);
  if (index < 1 || index > len + 1) {
    printf("������������\n");
    return NULL;
  }
  if (index == 1) {
    HeadInsert(L);
  }
  if (index == len + 1) {
    TailInsert(L);
  }
  LinkList p = getNodeByIndex(L, index - 1);
  LinkList s = (LinkList)malloc(sizeof(LNode));
  s->next = p->next;
  p->next = s;
  s->data = value;
}

//��λɾ��
void deleteNodeByIndex(LinkList &L, int index) {
  int len = getListLength(L);
  if (index < 1 || index > len) {
    printf("������������\n");
    return;
  }
  LinkList p = getNodeByIndex(L, index - 1);
  LinkList q = p->next;
  p->next = q->next;
  q->next = NULL;
  free(q);
}


//��ֵɾ��
void deleteNodeByValue(LinkList &L, int value) {
  int len = getListLength(L);
  LinkList p =  L->next;
  for (int i = 1; i < len; i++){
    if (p->data == value) {
      deleteNodeByIndex(L,i);
      break;
    }
    p = p->next;
  }
}

//�޸Ľڵ��ֵ
void updateNodeValue(LinkList &L, int index, int value) {
  int len = getListLength(L);
  if (index < 1 || index > len) {
    printf("������������\n");
    return;
  }
  LinkList p = getNodeByIndex(L, index);
  p->data = value;
}

int main() {
  LinkList L;
  InitList(L);
  char c, d;
  int index, value;
  int len;
  while (1) {
    printf("*********************************************\n");
    printf("*************����s �����ǰ��******************\n");
    printf("*************����h ͷ�巨�������***************\n");
    printf("*************����t β�巨�������***************\n");
    printf("*************����m ָ��λ���������*************\n");
    printf("*************����d ��λɾ������*****************\n");
    printf("*************����v ��ֵɾ������*****************\n");
    printf("*************����i �ж������Ƿ�Ϊ��**************\n");
    printf("*************����u �޸������ֵ*****************\n");
    printf("*************����l �������ĳ���****************\n");
    printf("*************����q �˳���**********************\n");
    printf("��������Ҫ�Ĳ���\n");
    scanf("%c", &c);
    scanf("%c", &d);
    switch (c) {
    case 's':
      showList(L);
      break;
    case 'h':
      printf("ͷ�巨��������,����������ֵ\n");
      HeadInsert(L);
      scanf("%c", &d);
      break;
    case 't':
      printf("β�巢��������,����������ֵ\n");
      TailInsert(L);
      scanf("%c", &d);
      break;
    case 'm':
      printf("ָ��λ�ò�������,����������λ�ú�ֵ\n");
      scanf("%d%d",&index,&value);
      scanf("%c",d);
      Midinsert(L,index,value);
      break;
    case 'd':
      printf("������Ҫɾ����λ��\n");
      scanf("%d", &index);
      scanf("%c", &d);
      deleteNodeByIndex(L, index);
      break;
    case 'v':
      printf("������Ҫɾ����ֵ\n");
      scanf("%d", &value);
      scanf("%c", &d);
      deleteNodeByValue(L, value);
      break;
    case 'i':
      if (isEmpty) {
        printf("����Ϊ��\n");
      }else{
        printf("����Ϊ��");
      }
      break;
    case 'u':
      printf("������Ҫ�޸ĵ�λ�ú��޸ĺ��ֵ\n");
      scanf("%d%d", &index, &value);
      scanf("%c", d);
      updateNodeValue(L,index, value);
      break;
    case 'l':
      len = getListLength(L);
      printf("������%d\n",len);
      break;
    case 'q':
      return 0;
    default:
      printf("��Ϸ������ַ�\n");
      break;
    }
  }

}

