#pragma once
#include<myhead/ds.h>

// �����г���
#define MAXQSIZE 3

typedef int QElemType;

typedef struct
{
	QElemType* base; // ��ʼ����̬����洢�ռ�
	int front;		 // ͷָ�룬ָ���ͷԪ�ص��±�
	int rear;		 // βָ�룬ָ���βԪ�ص���һ��Ԫ�ص��±�
}SqQueue;

Status InitQueue(SqQueue* Q);
Status DestoryQueue(SqQueue* Q);
int QueueLength(SqQueue* Q);
bool EmptyQueue(SqQueue* Q);
bool FullQueue(SqQueue* Q);
Status EnQueue(SqQueue* Q, QElemType e);
Status DeQueue(SqQueue* Q, QElemType* e);



