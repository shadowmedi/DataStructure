#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#define InitialCapacity 5
typedef int HeapDataType;
typedef struct Heap
{
	HeapDataType* data;//动态开辟的数组空间
	int capacity;//容量
	int num;//已有的数据量
}Heap;

void Swap(HeapDataType* p1, HeapDataType* p2);
void HeapInit(Heap* hp);
void HeapDestroy(Heap* hp);
//不管怎么插入，只要最后整成堆就行，所以尾插更好
void adjustUp(HeapDataType* a, int child);
void HeapPush(Heap* hp, HeapDataType x);

//删除堆顶的数据，删除后要保持继续是个堆，可以选出次大或次小的数
void adjustDown(HeapDataType* a, int num ,int parent);
void HeapPop(Heap* hp);
void HeapPrint(Heap* hp);

HeapDataType HeapTop(Heap* hp);//取堆顶的数据

bool HeapEmpty(Heap* hp);//判断堆是否为空

int HeapSize(Heap* hp);//堆的当前元素个数

void HeapSort(int* arr, int n);//堆排序

void PrintTopk(int* data, int n, int k);//topk问题


