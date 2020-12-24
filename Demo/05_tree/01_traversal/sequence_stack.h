#ifndef _STACK_H_
#define _STACK_H_

#include<myhead/ds.h>
#include"linked_binarytree.h"

// ============  ջ��˳��洢��ʾ  ============

#define STACK_INIT_SIZE 100 

typedef BiTree SElemType;

typedef struct
{
	SElemType* base; // ��ջ������֮ǰ������֮��base ��ֵΪ NULL
	SElemType* top;  // ջ��ָ��
	int stacksize;   // ��ǰ����Ŀռ䣬��Ԫ��Ϊ��λ
}SqStack;


// ============  ���������ĺ���ԭ��  ============

Status InitStack(SqStack* S);

// ����ջ
Status DestroyStack(SqStack* S);

// ���ջ
Status ClearStack(SqStack* S);

Status StackIsEmpty(const SqStack* S);

Status StackIsFull(const SqStack* S);

Status StackLength(const SqStack* S);

// ��ȡջ��Ԫ��
Status GetTop(const SqStack* S, SElemType* e);

// ѹջ
Status Push(SqStack* S, SElemType e);

// ��ջ
Status Pop(SqStack* S);

// ����ջ
Status StackTraverse(const SqStack* S);

/*
 * ע:
 * 1. ����ʱ��ȫ������ջ��ָ�롣�����������Ч�ʣ��������Ҫ��ջ�����ı䣬
 *    �򽫺���ԭ���е��β�����Ϊ const
 * 2. �޸� Pop ������ֱ��ɾ��ջ��Ԫ�ؼ��ɣ���ȡջ��Ԫ��ʹ�ýӿ� GetTop()
 * 3. �޸� StackTraverse() ��������Ϊ��ջ����ջ�ױ���ջ������ջ�ĳ�ջ˳��
 *    �о� visit û�У�ɾ��֮
 */
#endif 