## 数制转换

对于输入的任意非负十进制整数，打印输出与其等值的 2 进制，8 进制和 16 进制数。

```c
#define _CRT_SECURE_NO_WARNINGS 
/*
 * 进制转换
 * 题目描述：
 * 对于输入的任意非负十进制整数，打印输出与其等值的 2 进制，8 进制和 16 进制
 */

#include"Stack.h"
#include<stdio.h>


SqStack S;

void conversion(int x, int scale)
{
	while (x != 0)
	{
		// 压入最低位
		Push(&S, x % scale);
		// 除去最低位
		x /= scale;
	}
	
	// 打印对应进制的书写形式
	switch(scale)
	{
		case 8: printf("0"); break;
		case 16:printf("0x"); break;
		default:break;
	}

	// 遍历栈
	StackTraverse(&S);
	
	// 清空栈
	ClearStack(&S);
}

int main(void)
{
	int x;

	InitStack(&S);

	while (scanf("%d", &x) == 1)
	{
		// 传入要转换的数和要转换的机制
		conversion(x, 2);
		conversion(x, 8);
		conversion(x, 16);
	}

	DestroyStack(&S);
}
```

