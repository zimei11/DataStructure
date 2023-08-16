/**
 ***************************************************
 * @file           : SqQueue2.cpp
 * @author         : zi_mei
 * @brief          : 循环队列（顺序表，size记录法）
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
 * 初始化
 * Q.rear=Q.front=0;
 * Q.size=0;
 *
 * 入队
 * Q.size++;
 * 出队
 * Q.size--;
 *
 * 队列为空
 * Q.size==0;
 *
 * 队列为满
 * Q.size==MaxSize
 */