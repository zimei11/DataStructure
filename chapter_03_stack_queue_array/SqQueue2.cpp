/**
 ***************************************************
 * @file           : SqQueue2.cpp
 * @author         : zi_mei
 * @brief          : ѭ�����У�˳���size��¼����
 * @date           : 2023/8/15
 ***************************************************
 */
#define MaxSize 10
#define ElemType int

typedef struct{
  ElemType data[MaxSize];
  int front,rear;
  int size;
}SqQueue;

/*
 * ��ʼ��
 * Q.rear=Q.front=0;
 * Q.size=0;
 *
 * ���
 * Q.size++;
 * ����
 * Q.size--;
 *
 * ����Ϊ��
 * Q.size==0;
 *
 * ����Ϊ��
 * Q.size==MaxSize
 */