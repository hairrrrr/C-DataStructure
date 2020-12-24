#include"sort.h"

void ShellInsert(SqList* L, int k)
{
	for (int i = 1 + k; i <= L->length; i += k)
	{
		// ��� arr[i] < arr[i - k] ��Ҫ����
		if (cmp(&L->arr[i], &L->arr[i - k]))
		{
			L->arr[0] = L->arr[i];
			// ��֤�±���� 0
			int j = i;
			// �� j - k λ��ʼ�Ƚϣ���������� cmp��ֱ���� arr[0] ����
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
		ShellInsert(L, dlta[k]); // һ������Ϊ dlta[k] �Ĳ�������
}