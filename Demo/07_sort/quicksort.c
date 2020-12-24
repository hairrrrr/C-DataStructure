#include"sort.h"

// �����������ע�͵�ʮ���������ҾͲ������ע����
int Partition(SqList* L, int low, int high)
{
	L->arr[0] = L->arr[low];
	int key = L->arr[low].key;
	while (low < high)
	{
		while (low < high && L->arr[high].key >= key)
			--high;
		L->arr[low] = L->arr[high];
		while (low < high && L->arr[low].key <= key)
			++low;
		L->arr[high] = L->arr[low];
	}
	L->arr[low] = L->arr[0];
	return low;
}

void QSort(SqList* L, int low, int high)
{
	if (low < high)
	{
		int pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
}

void quicksort(SqList* L)
{
	QSort(L, 1, L->length);
}


