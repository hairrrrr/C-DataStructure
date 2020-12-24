#include"circle_queue.h"
#include<stdio.h>

int main(void)
{
	SqQueue Q;
	InitQueue(&Q);
	printf("�ӵĳ���Ϊ��%d\n", QueueLength(&Q));
	QElemType data;
	DeQueue(&Q, &data);

	EnQueue(&Q, 1);
	EnQueue(&Q, 2);
	EnQueue(&Q, 3);
	printf("�ӵĳ���Ϊ��%d\n", QueueLength(&Q));
	
	DeQueue(&Q, &data);
	printf("%d\n", data);
	DeQueue(&Q, &data);
	printf("%d\n", data);
	DeQueue(&Q, &data);
	printf("%d\n", data);
	printf("�ӵĳ���Ϊ��%d\n", QueueLength(&Q));

	DestoryQueue(&Q);

	return 0;
}
