#include"sort.h"


void test_shellsort()
{
	SqList L;

	L.arr[1].key = 49;
	L.arr[2].key = 38;
	L.arr[3].key = 65;
	L.arr[4].key = 97;
	L.arr[5].key = 76;
	L.arr[6].key = 13;
	L.arr[7].key = 27;
	L.arr[8].key = 49;
	L.arr[9].key = 55;
	L.arr[10].key = 4;
	L.length = 10;
	
	int dlta[] = { 7, 5, 3, 1 };
	ShellSort(&L, dlta, 4);

	getchar();

}

void test_quicksort()
{
	SqList L;

	L.arr[1].key = 49;
	L.arr[2].key = 38;
	L.arr[3].key = 65;
	L.arr[4].key = 97;
	L.arr[5].key = 76;
	L.arr[6].key = 13;
	L.arr[7].key = 27;
	L.arr[8].key = 49;

	L.length = 8;

	quicksort(&L);

	getchar();
}

int main(void)
{
	//test_shellsort();
	test_quicksort();

	return 0;
}