#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
  int data;
  struct LNode* next;
}LNode, *LinkList;

void InitList(LinkList &L) {
  L = (LinkList)malloc(sizeof(LNode));    //创建头结点
  L->next = NULL;     //头结点指向空
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
    s = (LinkList)malloc(sizeof(LNode));    //创建一个新的节点s
    s->data = x;    //赋值
    s->next = L->next;  //把新节点的指针域指向当前L的第一节点
    L->next = s;        //把L的指针域指向新节点
    scanf("%d",&x);
  }
  return L;
}

LinkList TailInsert(LinkList &L) {
  int x;  //用来接受数据
  LinkList s, r = L;  //s是新创建的节点，r用来保证每次都指向最后的一个节点
  scanf("%d", &x);
  while(x != 9999) {
    s = (LinkList)malloc(sizeof(LNode));    //创建一个新的节点赋值给s
    s->data = x;    //s.data赋值
    r->next = s;    //r的next指向s
    r = s;          //r指向s，让r始终保持在最后一个
    scanf("%d", &x);
  }
  r->next = NULL; //把r的next赋值为null
  return L;
}

void showList(LinkList L) {
  L = L->next;    //未使用引用，改变L的值，主函数的L不会改变，相当于是L的复制
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

//按序号查找节点值
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

//按值查找
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
    printf("没有查找到该值\n");
  }
  return p;
}

//中间插入
LinkList Midinsert(LinkList &L, int index, int value) {
  int len = getListLength(L);
  if (index < 1 || index > len + 1) {
    printf("输入数据有误\n");
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

//按位删除
void deleteNodeByIndex(LinkList &L, int index) {
  int len = getListLength(L);
  if (index < 1 || index > len) {
    printf("输入数据有误\n");
    return;
  }
  LinkList p = getNodeByIndex(L, index - 1);
  LinkList q = p->next;
  p->next = q->next;
  q->next = NULL;
  free(q);
}


//按值删除
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

//修改节点的值
void updateNodeValue(LinkList &L, int index, int value) {
  int len = getListLength(L);
  if (index < 1 || index > len) {
    printf("输入数据有误\n");
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
    printf("*************输入s 输出当前表******************\n");
    printf("*************输入h 头插法添加数据***************\n");
    printf("*************输入t 尾插法添加数据***************\n");
    printf("*************输入m 指定位置添加数据*************\n");
    printf("*************输入d 按位删除数据*****************\n");
    printf("*************输入v 按值删除数据*****************\n");
    printf("*************输入i 判断链表是否为空**************\n");
    printf("*************输入u 修改链表的值*****************\n");
    printf("*************输入l 输出链表的长度****************\n");
    printf("*************输入q 退出表**********************\n");
    printf("请输入想要的操作\n");
    scanf("%c", &c);
    scanf("%c", &d);
    switch (c) {
    case 's':
      showList(L);
      break;
    case 'h':
      printf("头插法插入链表,请输入插入的值\n");
      HeadInsert(L);
      scanf("%c", &d);
      break;
    case 't':
      printf("尾插发插入链表,请输入插入的值\n");
      TailInsert(L);
      scanf("%c", &d);
      break;
    case 'm':
      printf("指定位置插入链表,请输入插入的位置和值\n");
      scanf("%d%d",&index,&value);
      scanf("%c",d);
      Midinsert(L,index,value);
      break;
    case 'd':
      printf("请输入要删除的位置\n");
      scanf("%d", &index);
      scanf("%c", &d);
      deleteNodeByIndex(L, index);
      break;
    case 'v':
      printf("请输入要删除的值\n");
      scanf("%d", &value);
      scanf("%c", &d);
      deleteNodeByValue(L, value);
      break;
    case 'i':
      if (isEmpty) {
        printf("链表为空\n");
      }else{
        printf("链表不为空");
      }
      break;
    case 'u':
      printf("请输入要修改的位置和修改后的值\n");
      scanf("%d%d", &index, &value);
      scanf("%c", d);
      updateNodeValue(L,index, value);
      break;
    case 'l':
      len = getListLength(L);
      printf("长度是%d\n",len);
      break;
    case 'q':
      return 0;
    default:
      printf("请合法输入字符\n");
      break;
    }
  }

}

