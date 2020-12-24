#pragma once
#include<myhead/ds.h>

#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct PTNode
{
	TElemType data;
	int parent; // 该结点的父节点
}PTNode;

typedef struct
{
	PTNode* nodes;
	int root, size; // 集合的根和大小
}PTree;

PTNode* table;

Status InitSet(PTree* set);
Status DestorySet(PTree* set);
int FindRoot(PTree* set, int i);
Status MergeSet(PTree* set, int set1, int set2);
