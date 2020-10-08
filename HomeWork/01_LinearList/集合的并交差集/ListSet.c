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
			// 如果两个集合中的元素相等，直接把任意一个集合的指针向后移动一位，表示丢弃该重复值
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
		// 当前 pl 的值比 pr 集合中最小的值还要小，pr 集合中一定不存在和该值相等的元素
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
		// pl 集合的最小值大于 pr 当前值，pr 当前值一定不会是 pl，pr 的交集
		else
		{
			pr = pr->_next;
		}
	}
	// 被遍历完的集合的最大值小于没有被遍历完的集合的当前的最小值，所以后面的值不存在交集
	
	return OK;
}


Status list_set_diff(set_node_t* lhs, set_node_t* rhs, set_node_t* sub)
{
	set_node_t* pl = lhs->_next;
	set_node_t* pr = rhs->_next;
	set_node_t* ps = sub;

	while (pl && pr)
	{
		// 当前 pl 的值比 pr 集合中最小的值还要小，pr 集合中一定不存在和该值相等的元素
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
		// pl 集合的最小值大于 pr 当前值，pr 当前值一定不会是 pl，pr 的交集
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
	printf("Enter size of your set：");
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
