#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include<myhead/ds.h>
/*
 * ds.h 是我向 VS 的头文件寻找指定目录中加入的头文件
 * 其中定义了 Stutas OK ERROR 等表示状态的类型和宏
 */

typedef int ElemType;

typedef struct node
{
	ElemType _letter;
	struct node* _next;
}llist_node_t;

/*
 * 初始化链表
 */
Status linked_list_init(llist_node_t* head);

/*
 * 在第 pos 个节点前增加节点
 */
Status linked_list_insert(llist_node_t* head, int pos, ElemType val);

/*
 * 删除第 pos 个节点，并将节点的值存放在 val 指向的内存中
 */
Status linked_list_delete(llist_node_t* head, int pos, ElemType* val);

/*
 * 打印链表内容
 */
void linked_list_print(llist_node_t* head);

/*
 * 销毁链表
 */
void linked_list_destroy(llist_node_t* head);

#endif

