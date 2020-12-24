#pragma once
#include<myhead/ds.h>

#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct PTNode
{
	TElemType data;
	int parent; // �ý��ĸ��ڵ�
}PTNode;

typedef struct
{
	PTNode* nodes;
	int root, size; // ���ϵĸ��ʹ�С
}PTree;

PTNode* table;

Status InitSet(PTree* set);
Status DestorySet(PTree* set);
int FindRoot(PTree* set, int i);
Status MergeSet(PTree* set, int set1, int set2);
