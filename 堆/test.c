#define _CRT_SECURE_NO_WARNINGS
#include "heap.h"
void testPrintTopk()
{
	//随机时间种子
	srand(time(0));
	int arr[1000] = { 0 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		//随机生成小于10000的数放到数组中
		arr[i] = rand() % 10000;
	}
	//给任意几个数组位置赋大于10000的值
	arr[99] = 10005;
	arr[50] = 19922;
	arr[577] = 99999;
	arr[578] = 88689;
	arr[55] = 22222;
	//选出前5个大的数
	PrintTopk(arr, sizeof(arr) / sizeof(arr[0]), 5);
}
int main()
{
	testPrintTopk();
	//int arr[] = {27, 15, 19, 18, 28, 34, 65, 49, 25, 37};
	/*Heap hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		HeapPush(&hp, arr[i]);
	}
	HeapPush(&hp, 10);
	HeapPrint(&hp);
	for (int i = 0; i < 10; i++)
	{
		HeapPop(&hp);
		HeapPrint(&hp);
	}*/
	/*HeapSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');*/
	/*HeapDestroy(&hp);*/

	return 0;
}