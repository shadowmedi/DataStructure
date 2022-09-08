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
	HeapDataType* data;//��̬���ٵ�����ռ�
	int capacity;//����
	int num;//���е�������
}Heap;

void Swap(HeapDataType* p1, HeapDataType* p2);
void HeapInit(Heap* hp);
void HeapDestroy(Heap* hp);
//������ô���룬ֻҪ������ɶѾ��У�����β�����
void adjustUp(HeapDataType* a, int child);
void HeapPush(Heap* hp, HeapDataType x);

//ɾ���Ѷ������ݣ�ɾ����Ҫ���ּ����Ǹ��ѣ�����ѡ���δ���С����
void adjustDown(HeapDataType* a, int num ,int parent);
void HeapPop(Heap* hp);
void HeapPrint(Heap* hp);

HeapDataType HeapTop(Heap* hp);//ȡ�Ѷ�������

bool HeapEmpty(Heap* hp);//�ж϶��Ƿ�Ϊ��

int HeapSize(Heap* hp);//�ѵĵ�ǰԪ�ظ���

void HeapSort(int* arr, int n);//������

void PrintTopk(int* data, int n, int k);//topk����


