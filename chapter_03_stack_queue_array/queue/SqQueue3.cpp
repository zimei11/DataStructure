/**
 ***************************************************
 * @file           : SqQueue3.cpp
 * @author         : zi_mei
 * @brief          : ѭ�����У�˳���tag��¼����
 * @date           : 2023/8/15
 ***************************************************
 */

#define MaxSize 10
#define ElemType int

typedef struct{
  ElemType data[MaxSize];
  int rear,front;
  int tag;
}SqQueue;

/*
 * ��ʼ��
 * Q.rear=Q.front=0;
 * Q.tag=0;
 *
 * ����Ϊ��
 * Q.rear==Q.front&&Q.tag==0;
 *
 * ����Ϊ��
 * Q.rear==Q.front&&Q.tag==1;
 *
 * ����
 * tag=0;
 *
 * ���
 * tag=1;
 */