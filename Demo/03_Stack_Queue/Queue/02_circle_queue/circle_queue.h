#pragma once
#include<myhead/ds.h>

// 最大队列长度
#define MAXQSIZE 3

typedef int QElemType;

typedef struct
{
	QElemType* base; // 初始化动态分配存储空间
	int front;		 // 头指针，指向队头元素的下标
	int rear;		 // 尾指针，指向队尾元素的下一个元素的下标
}SqQueue;

Status InitQueue(SqQueue* Q);
Status DestoryQueue(SqQueue* Q);
int QueueLength(SqQueue* Q);
bool EmptyQueue(SqQueue* Q);
bool FullQueue(SqQueue* Q);
Status EnQueue(SqQueue* Q, QElemType e);
Status DeQueue(SqQueue* Q, QElemType* e);



