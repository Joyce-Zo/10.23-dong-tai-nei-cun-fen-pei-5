#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

				柔 性 数 组
		结构中最后一个元素是未知大小的数组 - 其为柔性数组成员 - 其大小可以调整
struct S
{
	int a ;
	int arr[];	// 
	int arr[0]; 二者等价
};
int main()
{
	struct S s;
	printf("%d ", sizeof(s));	//4 = int ,不包含柔性数组
	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
		malloc开辟动态空间					4		  + 5*4=20   =  24
	ps->a = 1314;
	int i = 0;
	for (i = 0; i < 5; i++) 
	{
		ps->arr[i] = i;
		printf("%d ", ps->arr[i]);
	}
		如果开辟的动态内存空间不够，可以realloc再次调整
	struct S* ptr = realloc(ps, 44);
	if (ptr != NULL)
	{
		ps = ptr;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
		printf("%d ", ps->arr[i]);
	}
	  释放动态内存开辟的空间 - 只需要一次
	free(ps);
	ps = NULL;
	return 0;
}

struct S
{
	int n;
	int* arr;
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	ps->arr = malloc(5 * sizeof(int));

	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
		printf("%d ", ps->arr[i]);
	}
		调整大小
	int* ptr = realloc(ps->arr, 10 * sizeof(int));
	if (ptr != NULL)
	{
		ps->arr = ptr;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
		printf("%d ", ps->arr[i]);
	}
		释放空间，两次malloc，释放2次 - 需要2次
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}