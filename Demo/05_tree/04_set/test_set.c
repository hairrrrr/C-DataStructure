#include"set.h"

int main(void)
{
	PTree set;
	InitSet(&set);
	MergeSet(&set, 0, 1);
	FindRoot(&set, 9);

	return 0;
}