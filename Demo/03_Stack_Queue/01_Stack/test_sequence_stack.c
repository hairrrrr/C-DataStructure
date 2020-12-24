#include"Stack.h"
#include<stdio.h>

int main(void)
{
	SqStack S;
	SElemType data;

	InitStack(&S);

	GetTop(&S, &data);

	Push(&S, 3);
	Push(&S, 2);
	Push(&S, 1);

	StackTraverse(&S);

	GetTop(&S, &data);
	Pop(&S);
	StackTraverse(&S);

	Push(&S, 1);
	Push(&S, 0);
	Push(&S, -1);
	StackTraverse(&S);

	DestroyStack(&S);

	return 0;
}