#pragma once
#include<myhead/ds.h>

typedef int QElemType;

typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front; // ��ͷָ��
	QueuePtr rear;  // ��βָ��
}LinkQueue;

Status InitQueue(LinkQueue* Q);
Status DestoryQueue(LinkQueue* Q);
Status QueueEmpty(LinkQueue* Q);
Status EnQueue(LinkQueue* Q, QElemType e);
Status DeQueue(LinkQueue* Q, QElemType* e);

