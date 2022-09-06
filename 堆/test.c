#define _CRT_SECURE_NO_WARNINGS
#include "heap.h"
int main()
{
	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37};
	/*Heap hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		HeapPush(&hp, arr[i]);
	}
	HeapPrint(&hp);
	//HeapPush(&hp, 10);
	//HeapPrint(&hp);
	for (int i = 0; i < 10; i++)
	{
		HeapPop(&hp);
		HeapPrint(&hp);
	}*/
	HeapSort(arr, 10);
	//HeapDestroy(&hp);
	return 0;
}