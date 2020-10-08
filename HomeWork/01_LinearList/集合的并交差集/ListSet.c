#define _CRT_SECURE_NO_WARNINGS

#include"ListSet.h"

#include<stdio.h>
#include<stdlib.h>

static set_node_t* list_set_new_node(ElemType data)
{
	set_node_t* new_node = (set_node_t*)malloc(sizeof(set_node_t));
	if (!new_node)
	{
		perror("malloc failed");
		exit(OVERFLOW);
	}
	new_node->_data = data;
	new_node->_next = NULL;

	return new_node;
}

Status list_set_union(set_node_t* lhs, set_node_t* rhs, set_node_t* sum)
{
	set_node_t* pl = lhs->_next;
	set_node_t* pr = rhs->_next;
	set_node_t* ps = sum;
	
	while (pl && pr)
	{
		if (pl->_data < pr->_data)
		{			
			ps->_next = list_set_new_node(pl->_data);
			ps = ps->_next;
			pl = pl->_next;
		}
		else if (pl->_data == pr->_data)
		{
			// ������������е�Ԫ����ȣ�ֱ�Ӱ�����һ�����ϵ�ָ������ƶ�һλ����ʾ�������ظ�ֵ
			pl = pl->_next;
		}
		else
		{
			ps->_next = list_set_new_node(pr->_data);
			ps = ps->_next;
			pr = pr->_next;
		}
	}

	if (pl)
	{
		while (pl)
		{
			ps->_next = list_set_new_node(pl->_data);
			ps = ps->_next;
			pl = pl->_next;
		}
	}
	else
	{
		while (pr)
		{
			ps->_next = list_set_new_node(pr->_data);
			ps = ps->_next;
			pr = pr->_next;
		}
	}

	return OK;
}

Status list_set_inter(set_node_t* lhs, set_node_t* rhs, set_node_t* inter)
{
	set_node_t* pl = lhs->_next;
	set_node_t* pr = rhs->_next;
	set_node_t* ps = inter;

	while (pl && pr)
	{
		// ��ǰ pl ��ֵ�� pr ��������С��ֵ��ҪС��pr ������һ�������ں͸�ֵ��ȵ�Ԫ��
		if (pl->_data < pr->_data)
		{
			pl = pl->_next;
		}
		else if (pl->_data == pr->_data)
		{			
			ps->_next = list_set_new_node(pr->_data);
			pl = pl->_next;
			pr = pr->_next;
			ps = ps->_next;
		}
		// pl ���ϵ���Сֵ���� pr ��ǰֵ��pr ��ǰֵһ�������� pl��pr �Ľ���
		else
		{
			pr = pr->_next;
		}
	}
	// ��������ļ��ϵ����ֵС��û�б�������ļ��ϵĵ�ǰ����Сֵ�����Ժ����ֵ�����ڽ���
	
	return OK;
}


Status list_set_diff(set_node_t* lhs, set_node_t* rhs, set_node_t* sub)
{
	set_node_t* pl = lhs->_next;
	set_node_t* pr = rhs->_next;
	set_node_t* ps = sub;

	while (pl && pr)
	{
		// ��ǰ pl ��ֵ�� pr ��������С��ֵ��ҪС��pr ������һ�������ں͸�ֵ��ȵ�Ԫ��
		if (pl->_data < pr->_data)
		{
			ps->_next = list_set_new_node(pl->_data);
			ps = ps->_next;
			pl = pl->_next;
		}
		else if (pl->_data == pr->_data)
		{
			pl = pl->_next;
			pr = pr->_next;
		}
		// pl ���ϵ���Сֵ���� pr ��ǰֵ��pr ��ǰֵһ�������� pl��pr �Ľ���
		else
		{
			ps->_next = list_set_new_node(pr->_data);
			ps = ps->_next;
			pr = pr->_next;
		}
	}

	if (pl)
	{
		while (pl)
		{
			ps->_next = list_set_new_node(pl->_data);
			ps = ps->_next;
			pl = pl->_next;
		}
	}
	else
	{
		while (pr)
		{
			ps->_next = list_set_new_node(pr->_data);
			ps = ps->_next;
			pr = pr->_next;
		}
	}

	return OK;
}

Status list_set_create(set_node_t* s)
{
	int num;
	printf("Enter size of your set��");
	scanf("%d", &num);
	if (num <= 0)
	{
		printf("number must be positive\n");
		return ERROR;
	}
	printf("Enter %d element(s): ", num);
	set_node_t* cur = s;
	while (num--)
	{
		int elem;
		scanf("%d", &elem);
		set_node_t* new_node = list_set_new_node(elem);

		cur->_next = new_node;
		cur = new_node;
	}
	return OK;
}

void list_set_show(set_node_t* s)
{
	set_node_t* cur = s->_next;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
}

Status list_set_destroy(set_node_t* s)
{
	set_node_t* cur = s->_next;
	while (cur)
	{
		set_node_t* next = cur->_next;
		free(cur);
		cur = next;
	}
	return OK;
}
