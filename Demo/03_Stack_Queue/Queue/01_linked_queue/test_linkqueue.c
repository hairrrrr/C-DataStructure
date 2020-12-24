#include"linked_queue.h"
#include<stdio.h>

int main(void)
{
	LinkQueue lq;
	InitQueue(&lq);
	QElemType data;
	int ret = DeQueue(&lq, &data);
	if (ret == ERROR)
		printf("¶Ó¿Õ£¬É¾³ýÊ§°Ü£¡\n");
	EnQueue(&lq, 1);
	EnQueue(&lq, 2);
	EnQueue(&lq, 3);
	
	DeQueue(&lq, &data);
	printf("%d\n", data);
	DeQueue(&lq, &data);
	printf("%d\n", data);
	DeQueue(&lq, &data);
	printf("%d\n", data);

	DestoryQueue(&lq);

	return 0;
}