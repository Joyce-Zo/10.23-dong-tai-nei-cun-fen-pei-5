#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

				�� �� �� ��
		�ṹ�����һ��Ԫ����δ֪��С������ - ��Ϊ���������Ա - ���С���Ե���
struct S
{
	int a ;
	int arr[];	// 
	int arr[0]; ���ߵȼ�
};
int main()
{
	struct S s;
	printf("%d ", sizeof(s));	//4 = int ,��������������
	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
		malloc���ٶ�̬�ռ�					4		  + 5*4=20   =  24
	ps->a = 1314;
	int i = 0;
	for (i = 0; i < 5; i++) 
	{
		ps->arr[i] = i;
		printf("%d ", ps->arr[i]);
	}
		������ٵĶ�̬�ڴ�ռ䲻��������realloc�ٴε���
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
	  �ͷŶ�̬�ڴ濪�ٵĿռ� - ֻ��Ҫһ��
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
		������С
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
		�ͷſռ䣬����malloc���ͷ�2�� - ��Ҫ2��
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}