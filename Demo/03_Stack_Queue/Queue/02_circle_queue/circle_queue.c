#include"circle_queue.h"
#include<stdio.h>
#include<stdlib.h>

Status InitQueue(SqQueue* Q)
{
	Q->base = malloc(sizeof(QElemType) * MAXQSIZE);
	if (!Q->base) return OVERFLOW;
	Q->front = Q->rear = 0;
	return OK;
}

Status DestoryQueue(SqQueue* Q)
{
	if (Q->base)
		free(Q->base);
	Q->base = NULL;

	return OK;
}

int QueueLength(SqQueue* Q)
{
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}

bool EmptyQueue(SqQueue* Q)
{
	if (Q->front == Q->rear)
	{
		printf("¶ÓÎª¿Õ£¬É¾³ýÊ§°Ü£¡\n");
		return true;
	}
	return false;
}

bool FullQueue(SqQueue* Q)
{
	if ((Q->rear + 1) % MAXQSIZE == Q->front)
	{
		printf("¶ÓÂú£¬²åÈëÊ§°Ü£¡\n");
		return true;
	}
	return false;
}

Status EnQueue(SqQueue* Q, QElemType e)
{
	if (FullQueue(Q)) return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;

	return OK;
}

Status DeQueue(SqQueue* Q, QElemType* e)
{
	if (EmptyQueue(Q)) return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;

	return OK;
}