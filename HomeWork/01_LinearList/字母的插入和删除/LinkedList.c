#include"LinkedList.h"
#include<stdio.h>
#include<stdlib.h>

Status linked_list_init(llist_node_t** head)
{
	*head = (llist_node_t*)malloc(sizeof(llist_node_t));
	if (!head)
	{
		perror("malloc head: out of memory");
		exit(OVERFLOW);
	}
	(*head)->_next = NULL;
	// ͷ�ڵ�������������洢��ǰ�����нڵ����
	(*head)->_letter = 0;
	return OK;
}

Status linked_list_insert(llist_node_t* head, int pos, ElemType val)
{
	if (pos <= 0 || pos > head->_letter + 1)
	{
		printf("index %d out of range\n", pos);
		return ERROR;
	}
	llist_node_t* cur = head;
	// �ڵ� pos ���ڵ�ǰ�壬�൱���� pos - 1 �ڵ���
	// �ҵ� pos - 1 �ڵ����ڵ�λ��
	while (pos - 1 > 0)
	{
		cur = cur->_next;
		pos--;
	}
	llist_node_t* new_node = (llist_node_t*)malloc(sizeof(llist_node_t));
	if (!new_node)
	{
		perror("new_node malloc failed");
		exit(OVERFLOW);
	}
	new_node->_letter = val;
	new_node->_next = NULL;
	
	new_node->_next = cur->_next;
	cur->_next = new_node;
	head->_letter++;

	return OK;
}

Status linked_list_delete(llist_node_t* head, int pos, ElemType* val)
{
	if (pos <= 0 || pos > head->_letter)
	{
		printf("index %d out of range\n", pos);
		return ERROR;
	}
	llist_node_t* cur = head;
	
	while (pos - 1 > 0)
	{
		cur = cur->_next;
		pos--;
	}
	llist_node_t* del = cur->_next;
	
	cur->_next = del->_next;
	*val = del->_letter;
	free(del);
	
	head->_letter--;

	return OK;
}

void linked_list_print(llist_node_t* head)
{
	llist_node_t* cur = head->_next;
	while (cur)
	{
		printf("%c ", cur->_letter);
		cur = cur->_next;
	}
	printf("\n");
}

void linked_list_destroy(llist_node_t** head)
{
	llist_node_t* cur = *head;
	llist_node_t* next = NULL;

	while (cur)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	*head = NULL;
}