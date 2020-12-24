#include"sort.h"

bool cmp(const RedType* lhs, const RedType* rhs)
{
	return lhs->key < rhs->key;
}