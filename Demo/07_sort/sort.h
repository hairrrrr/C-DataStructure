#pragma once

#include<myhead/ds.h>
#include<stdio.h>

#define MAXSIZE 20

typedef int KeyType;
typedef int InfoType;

typedef struct
{
	KeyType key;
	InfoType info;
}RedType;

typedef struct
{
	RedType arr[MAXSIZE + 1]; // arr[0] ÏÐÖÃ»òÓÃ×÷ÉÚ±ø
	int length;
}SqList;

bool cmp(const RedType* lhs, const RedType* rhs);

void ShellSort(SqList* L, int dlta[], int t);

void quicksort(SqList* L);
