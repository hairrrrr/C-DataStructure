#include"sort.h"

void ShellInsert(SqList* L, int k)
{
	for (int i = 1 + k; i <= L->length; i += k)
	{
		// 如果 arr[i] < arr[i - k] 需要交换
		if (cmp(&L->arr[i], &L->arr[i - k]))
		{
			L->arr[0] = L->arr[i];
			// 保证下标大于 0
			int j = i;
			// 从 j - k 位开始比较，如果不满足 cmp，直接与 arr[0] 交换
			for (; j > 0 && cmp(&L->arr[0], &L->arr[j - k]); j -= k)
			{
				L->arr[j] = L->arr[j - k];
			}
			L->arr[j] = L->arr[0];
		}
	}
}


void ShellSort(SqList* L, int dlta[], int t)
{
	for (int k = 0; k < t; ++k)
		ShellInsert(L, dlta[k]); // 一趟增量为 dlta[k] 的插入排序
}