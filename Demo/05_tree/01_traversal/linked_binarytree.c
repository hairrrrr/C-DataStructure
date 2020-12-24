#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"linked_binarytree.h"
#include"sequence_stack.h"
#include"linked_queue.h"

// 按先序次数构建二叉树
// 注意书上的写法只是伪代码，需要注意前面我们说过的二级指针的问题（如果你不知道，请先读完这个项目的 README）
Status CreateBiTree(BiTree* T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '=')
		*T = NULL;
	else
	{
		if (!(*T = malloc(sizeof(BiTNode)))) return OVERFLOW;
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
	return OK;
}

// 后序递归删除二叉树
Status DestoryBiTree(BiTree T)
{
	if (T)
	{
		DestoryBiTree(T->lchild);
		DestoryBiTree(T->rchild);
		free(T);
	}
	return OK;
}
// 二叉树的 前，中，后，层序遍历
Status PreOrderTraverse(BiTree T)
{
	if (T)
	{
		printf("%c", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return OK;
}
Status InOrderTraverse(BiTree T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		printf("%c", T->data);
		InOrderTraverse(T->rchild);
	}
	return OK;
}
Status PostOrderTraverse(BiTree T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	}
	return OK;
}

// 下面是非递归版本
Status PreOrderTraverseNoR(BiTree T)
{
	if (!T) return OK;
	SqStack S;
	InitStack(&S);
	BiTree cur = T;
	while (!StackIsEmpty(&S) || cur)
	{
		while (cur)
		{
			printf("%c", cur->data);
			Push(&S, cur);
			cur = cur->lchild;
		}
		GetTop(&S, &cur);
		Pop(&S);
		cur = cur->rchild;
	}
	DestroyStack(&S);
	return OK;
}

Status InOrderTraverseNoR(BiTree T)
{
	if (!T) return OK;
	SqStack S;
	InitStack(&S);
	BiTree cur = T;
	while (!StackIsEmpty(&S) || cur)
	{
		while (cur)
		{
			Push(&S, cur);
			cur = cur->lchild;
		}
		GetTop(&S, &cur);
		printf("%c", cur->data);
		Pop(&S);
		cur = cur->rchild;
	}
	DestroyStack(&S);
	return OK;
}

Status PostOrderTraverseNoR(BiTree T)
{
	if (!T) return OK;
	SqStack S;
	InitStack(&S);
	BiTree cur = T;
	BiTree prev = NULL;
	while (!StackIsEmpty(&S) || cur)
	{
		while (cur)
		{
			Push(&S, cur);
			cur = cur->lchild;
		}
		GetTop(&S, &cur);
		if (cur->rchild == NULL || cur->rchild == prev)
		{
			printf("%c", cur->data);
			Pop(&S);
			prev = cur;
			cur = NULL;
		}
		else
		{
			cur = cur->rchild;
		}
	}
	DestroyStack(&S);
	return OK;
}

Status LevelOrderTraverseNoR(BiTree T)
{
	if (!T) return OK;
	LinkQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, T);
	while (!QueueEmpty(&Q))
	{
		BiTree cur = NULL;
		DeQueue(&Q, &cur);
		printf("%c", cur->data);
		if (cur->lchild) EnQueue(&Q, cur->lchild);
		if (cur->rchild) EnQueue(&Q, cur->rchild);
	}
	DestoryQueue(&Q);
}