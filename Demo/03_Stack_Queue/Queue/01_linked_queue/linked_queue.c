#include"linked_queue.h"
#include<stdio.h>
#include<stdlib.h>

static QNode* MakeNode(QElemType* e)
{
	QNode* new_node = malloc(sizeof(QNode));
	if (!new_node) return OVERFLOW;
	new_node->data = *e;
	new_node->next = NULL;

	return new_node;
}

Status InitQueue(LinkQueue* Q)
{
	// ����һ��ͷ�ڵ㣨ͷ���ͷɾ���õ������ۣ��򻯳���
	int data = 0;
	Q->front = Q->rear = MakeNode(&data);
	return OK;
}

Status DestoryQueue(LinkQueue* Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	// �� Q ��ָ����Ϊ�գ���������ָ��
	Q->front = Q->rear = NULL;

	return OK;
}

Status QueueEmpty(LinkQueue* Q)
{
	return Q->front == Q->rear;
}

Status EnQueue(LinkQueue* Q, QElemType e)
{
	if (!Q->rear) return ERROR;
	QNode* new_node = MakeNode(&e);
	Q->rear->next = new_node;
	Q->rear = new_node;

	return OK;
}

Status DeQueue(LinkQueue* Q, QElemType* e)
{
	if (QueueEmpty(Q)) return ERROR;
	// Q->front ָ�����ͷ�ڵ㣬ɾ����ͷ�ڵ�ĺ����һ���ڵ�
	QNode* del = Q->front->next;
	*e = del->data;
	Q->front->next = del->next;
	// ɾ�����Ƕ��е����һ��Ԫ��
	if (del == Q->rear) Q->rear = Q->front;
	
	return OK;
}