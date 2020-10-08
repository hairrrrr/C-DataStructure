#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include<myhead/ds.h>
/*
 * ds.h ������ VS ��ͷ�ļ�Ѱ��ָ��Ŀ¼�м����ͷ�ļ�
 * ���ж����� Stutas OK ERROR �ȱ�ʾ״̬�����ͺͺ�
 */

typedef int ElemType;

typedef struct node
{
	ElemType _letter;
	struct node* _next;
}llist_node_t;

/*
 * ��ʼ������
 */
Status linked_list_init(llist_node_t* head);

/*
 * �ڵ� pos ���ڵ�ǰ���ӽڵ�
 */
Status linked_list_insert(llist_node_t* head, int pos, ElemType val);

/*
 * ɾ���� pos ���ڵ㣬�����ڵ��ֵ����� val ָ����ڴ���
 */
Status linked_list_delete(llist_node_t* head, int pos, ElemType* val);

/*
 * ��ӡ��������
 */
void linked_list_print(llist_node_t* head);

/*
 * ��������
 */
void linked_list_destroy(llist_node_t* head);

#endif

