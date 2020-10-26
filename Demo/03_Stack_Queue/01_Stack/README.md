## 栈的表示和实现

### 一 顺序存储表示和实现

![](https://hairrrrr.github.io/assets/2020-10-26-1.jpg)



*Stack.h*

```c
#ifndef _STACK_H_
#define _STACK_H_

#include<myhead/ds.h>

// ============  栈的顺序存储表示  ============

#define STACK_INIT_SIZE 10

typedef int SElemType;

typedef struct
{
	SElemType* base; // 在栈顶构造之前和销毁之后，base 的值为 NULL
	SElemType* top;  // 栈顶指针
	int stacksize;   // 当前分配的空间，以元素为单位
}SqStack;


// ============  基本操作的函数原型  ============

Status InitStack(SqStack* S);

// 销毁栈
Status DestroyStack(SqStack* S);

// 清空栈
Status ClearStack(SqStack* S);

Status StackIsEmpty(const SqStack* S);

Status StackIsFull(const SqStack* S);

Status StackLength(const SqStack* S);

// 获取栈顶元素
Status GetTop(const SqStack* S, SElemType* e);

// 压栈
Status Push(SqStack* S, SElemType e);

// 出栈
Status Pop(SqStack* S);

// 遍历栈
Status StackTraverse(const SqStack* S);

/*
 * 注:
 * 1. 传参时，全部传入栈的指针。这样可以提高效率，如果不需要堆栈做出改变，
 *    则将函数原型中的形参声明为 const
 * 2. 修改 Pop 函数，直接删除栈顶元素即可，获取栈顶元素使用接口 GetTop()
 * 3. 修改 StackTraverse() 函数，改为从栈顶到栈底遍历栈（这是栈的出栈顺序）
 *    感觉 visit 没有，删除之
 */
#endif 
```



*Stack.c*

```c
#include"Stack.h"

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
		printf("栈空\n");
		return ERROR;
	}
	*e = *(S->top - 1);

	return OK;
}

Status Push(SqStack* S, SElemType e)
{
	if (StackIsFull(S))
	{
		//printf("栈满，增容，当前容量为：%d\n", S->stacksize * 2);
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
		printf("栈空");
		return ERROR;
	}
	S->top--;

	return OK;
}


Status StackTraverse(const SqStack* S)
{
	if (StackIsEmpty(S))
		return ERROR;
	
	// top 指向的位置没有放入元素
	SElemType* cur = S->top;
	do
	{
		--cur; 
		printf("%d", *cur);
	} while (cur != S->base);

	printf("\n");
	return OK;
}

```



*TestStack.c*

```c
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
```

