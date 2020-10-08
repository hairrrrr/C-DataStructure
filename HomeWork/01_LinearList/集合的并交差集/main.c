#include"ListSet.h"
#include<stdio.h>

int main(void)
{
	set_node_t s1;
	set_node_t s2;
	set_node_t s3;

	list_set_create(&s1);
	list_set_create(&s2);

	list_set_diff(&s1, &s2, &s3);

	list_set_show(&s3);

	list_set_destroy(&s1);
	list_set_destroy(&s2);
	list_set_destroy(&s3);

	return 0;
}
