/**
 ***************************************************
 * @file           : SqQueue3.cpp
 * @author         : zi_mei
 * @brief          : 循环队列（顺序表，tag记录法）
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
 * 初始化
 * Q.rear=Q.front=0;
 * Q.tag=0;
 *
 * 队列为空
 * Q.rear==Q.front&&Q.tag==0;
 *
 * 队列为满
 * Q.rear==Q.front&&Q.tag==1;
 *
 * 出队
 * tag=0;
 *
 * 入队
 * tag=1;
 */