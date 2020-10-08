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
 * ��Ŀ��˵����һ������ļ���
 * �����������ǲ���Ҫ�Լ�����
 * ���ϱ���ÿ��������û���ظ���Ԫ��
 */

Status list_set_create(set_node_t* s);

/*
 * ����
 */
Status list_set_union(set_node_t* lhs, set_node_t* rhs, set_node_t* sum);

/*
 * ����
 */
Status list_set_inter(set_node_t* lhs, set_node_t* rhs, set_node_t* inter);

/*
 * ������� - ����
 */
Status list_set_diff(set_node_t* lhs, set_node_t* rhs, set_node_t* sub);

void list_set_show(set_node_t* s);

Status list_set_destroy(set_node_t* s);

#endif 