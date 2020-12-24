#ifndef _STACK_H_
#define _STACK_H_

#include<myhead/ds.h>
#include"linked_binarytree.h"

// ============  栈的顺序存储表示  ============

#define STACK_INIT_SIZE 100 

typedef BiTree SElemType;

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