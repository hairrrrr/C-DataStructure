#include<stdio.h>
#include"linked_binarytree.h"

int main(void)
{
	BiTree t = NULL;

	CreateBiTree(&t);
	printf("=============== Traversal By Recursive ===============\n");
	PreOrderTraverse(t);
	printf("\n");
	InOrderTraverse(t);
	printf("\n");
	PostOrderTraverse(t);
	printf("\n");
	printf("=============== Traversal By Stack ===============\n");
	PreOrderTraverseNoR(t);
	printf("\n");
	InOrderTraverseNoR(t);
	printf("\n");
	PostOrderTraverseNoR(t);
	printf("\n");
	printf("=============== Traversal By Queue ===============\n");
	LevelOrderTraverseNoR(t);
	getchar();
	return 0;
}