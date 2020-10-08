#ifndef _LISTSET_H_
#define _LISTSET_H_

#include<myhead/ds.h>

typedef int ElemType;

typedef struct set_node
{
	ElemType _data;
	struct set_node* _next;
}set_node_t;

/*
 * 题目中说这是一个有序的集合
 * 有序所以我们不需要自己排序
 * 集合表明每个集合中没有重复的元素
 */

Status list_set_create(set_node_t* s);

/*
 * 并集
 */
Status list_set_union(set_node_t* lhs, set_node_t* rhs, set_node_t* sum);

/*
 * 交集
 */
Status list_set_inter(set_node_t* lhs, set_node_t* rhs, set_node_t* inter);

/*
 * 差集：并集 - 交集
 */
Status list_set_diff(set_node_t* lhs, set_node_t* rhs, set_node_t* sub);

void list_set_show(set_node_t* s);

Status list_set_destroy(set_node_t* s);

#endif 