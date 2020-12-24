#include"sequence_stack.h"

#include<stdio.h>
#include<stdlib.h>

Status InitStack(SqStack* S)
{
	S->base = (SElemType*)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
	if (!S->base)
		perror("InitStack: malloc failed"), exit(EXIT_FAILURE);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;

	return OK;
}

Status DestroyStack(SqStack* S)
{
	free(S->base);
	S->base = S->top = NULL;
	S->stacksize = 0;

	return OK;
}

Status ClearStack(SqStack* S)
{
	S->top = S->base;
	return OK;
}

Status StackIsEmpty(const SqStack* S)
{
	return S->top == S->base;
}

Status StackIsFull(const SqStack* S)
{
	return (S->top - S->base) == S->stacksize;
}

Status StackLength(const SqStack* S)
{
	return S->top - S->base;
}

Status GetTop(const SqStack* S, SElemType* e)
{
	if (StackIsEmpty(S))
	{
		printf("ջ��\n");
		return ERROR;
	}
	*e = *(S->top - 1);

	return OK;
}

Status Push(SqStack* S, SElemType e)
{
	if (StackIsFull(S))
	{
		//printf("ջ�������ݣ���ǰ����Ϊ��%d\n", S->stacksize * 2);
		S->base = (SElemType*)realloc(S->base, 2 * S->stacksize * sizeof(SElemType));
		if (!S->base)
			perror("Push: realloc failed"), exit(OVERFLOW);
		S->top = S->base + S->stacksize;
		S->stacksize *= 2;
	}

	*(S->top) = e;
	++(S->top);

	return OK;
}

Status Pop(SqStack* S)
{
	if (StackIsEmpty(S))
	{
		printf("ջ��");
		return ERROR;
	}
	S->top--;

	return OK;
}


Status StackTraverse(const SqStack* S)
{
	if (StackIsEmpty(S))
		return ERROR;

	// top ָ���λ��û�з���Ԫ��
	SElemType* cur = S->top;
	do
	{
		--cur;
		printf("%d", *cur);
	} while (cur != S->base);

	printf("\n");
	return OK;
}
