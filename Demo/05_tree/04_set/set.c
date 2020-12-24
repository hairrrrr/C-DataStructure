#define _CRT_SECURE_NO_WARNINGS
#include"set.h"
#include<stdio.h>
#include<stdlib.h>

static void ShowSet(PTree* set)
{
	printf("==========\n");
	for (int i = 0; i < 10; ++i)
		printf("%d %2d %2d\n", i, table[i].data, table[i].parent);
}	

Status InitSet(PTree* set)
{
	if (!table)
	{
		//printf("请输入集合点的个数：\n");
		//int n;
		//scanf("%d", &n);
		table = malloc(sizeof(PTNode) * 10);
		if (!table) return OVERFLOW;
	}
	set->nodes = table;
	//set->root = ;
	//set->size = ;
	
	// 根据用户输入建立集合后面可能会时间，现在就用课本上的例子
	for (int i = 0; i < 10; i++)
	{
		table[i].data	= i + 1;
		table[i].parent = -1;
	}
	table[2].parent = table[5].parent = table[8].parent = 0;
	table[7].parent = table[9].parent = 1;
	// 集合的根用来存储这个集合元素个数
	table[0].parent = 4;
	table[1].parent = 3;

	ShowSet(set);
}

Status DestorySet(PTree* set)
{
	if(table)
		free(table);
}

int FindRoot(PTree* set, int i)
{
	int root = -1;
	if (i < 0 /*|| i > set->size*/) return ERROR;
	// 根节点的值为 7
	for (root = i; set->nodes[root].parent != 7; 
		root = set->nodes[root].parent);
	int nxt;
	// 路径压缩
	for (int j = i; j != root; j = nxt)
	{
		nxt = set->nodes[j].parent;
		set->nodes[j].parent = root;
	}
	ShowSet(set);
	return root;
}

Status MergeSet(PTree* set, int set1, int set2)
{
	if (set1 < 0 || set2 < 0) return ERROR;
	// 按秩归并 
	// set1 元素个数更多，将 set2 归并到 set1 上
	if (set->nodes[set1].parent > set->nodes[set2].parent)
	{
		set->nodes[set1].parent += set->nodes[set2].parent;
		set->nodes[set2].parent = set1;
	}
	else
	{
		set->nodes[set2].parent += set->nodes[set1].parent;
		set->nodes[set1].parent = set2;
	}
	ShowSet(set);

	return OK;
}