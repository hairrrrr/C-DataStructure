#include"LinkedList.h"
#include<stdio.h>

int main(void)
{
	llist_node_t* head;

	// 注意要传二级指针
	linked_list_init(&head);

	linked_list_insert(head, 1, 'a');
	linked_list_insert(head, 1, 'b');
	linked_list_insert(head, 2, 'c'); // b c a
	linked_list_insert(head, 4, 'd'); // b c a d
	linked_list_insert(head, 6, 'a'); // ERROR
	linked_list_print(head);

	int ch;
	linked_list_delete(head, 1, &ch); // c a d
	printf("%c\n", ch);
	linked_list_delete(head, 2, &ch); // c d
	linked_list_delete(head, 3, &ch); // ERROR
	linked_list_print(head);

	linked_list_destroy(&head);

	return 0;
}
/* 程序输出
index 6 out of range
b c a d
b
index 3 out of range
c d
*/
