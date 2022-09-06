#define _CRT_SECURE_NO_WARNINGS
#include "heap.h"

void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->num; i++)
	{
		printf("%d ", hp->data[i]);
	}
	printf("\n");
}

void Swap(HeapDataType* a, HeapDataType* b)
{
	HeapDataType tem = *a;
	*a = *b;
	*b = tem;
}

void HeapInit(Heap* hp)
{
	assert(hp);
	HeapDataType* tmp = (HeapDataType*)malloc(sizeof(HeapDataType) * InitialCapacity);
	assert(tmp);
	hp->data = tmp;
	hp->capacity = InitialCapacity;
	hp->num = 0;
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->data);
	hp->data = NULL;
	hp->capacity = hp->num = 0;
}

void adjustUp(HeapDataType* a, int child)//��С��Ϊ��
{
	assert(a);
	//Ҫ�Ѻ��ӵ�����ȷ�ĵط�
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;//Ҫ�����ĺ��Ӹ���
			parent = (child - 1) / 2;//���׸���
		}
		else
			return;
	}
}

void HeapPush(Heap* hp, HeapDataType x)
{
	assert(hp);
	//�ж�����
	if (hp->num == hp->capacity)
	{
		int newCapacity = 2 * hp->capacity;
		HeapDataType* tmp = (HeapDataType*)realloc(hp->data, sizeof(HeapDataType) * newCapacity);
		assert(tmp);
		hp->data = tmp;
		hp->capacity = newCapacity;
	}
	//β�嵽����
	hp->data[hp->num++] = x;
	//���°��������ɶ�
	adjustUp(hp->data, hp->num - 1);
}

void adjustDown(HeapDataType* a, int num, int parent)//��num��Ԫ��,��parent��ʼ����
{
	assert(a);
	int lesschild = parent * 2 + 1;
	while (lesschild <= num - 1)
	{
		if (lesschild + 1 <= num - 1)
		{
			//�ҳ����Һ�������С�ĺ���
			if (a[lesschild] > a[lesschild + 1])
				lesschild++;
		}
		//�����ױȺ��Ӵ��򽻻��������������
		if (a[parent] > a[lesschild])
		{
			Swap(&a[parent], &a[lesschild]);
			parent = lesschild;
			lesschild = 2 * parent + 1;
		}
		else
			return;
	}
}
/*void adjustDown(HeapDataType* a, int num, int parent)
{
	assert(a);
	if (parent*2+1>= num)
		return;
	int lesschild = parent * 2 + 1;
	if (lesschild + 1 < num && a[lesschild] > a[lesschild + 1])
		lesschild++;
	if (a[parent] > a[lesschild])
	{
		Swap(&a[parent], &a[lesschild]);
		adjustDown(a, num, lesschild);
	}
	else
		return;
}*/

void HeapPop(Heap* hp)//ɾ���Ѷ������ݣ�ʣ�µ������ɱ�����С��
{
	assert(hp);
	assert(hp->num > 0);
	Swap(&hp->data[0], &hp->data[hp->num - 1]);
	hp->num--;
	adjustDown(hp->data, hp->num, 0);
}

HeapDataType HeapTop(Heap* hp)//ȡ�Ѷ�������
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->data[0];
}

bool HeapEmpty(Heap* hp)//�ж϶��Ƿ�Ϊ��
{
	assert(hp);
	return hp->num == 0;
}

int HeapSize(Heap* hp)//�ѵĵ�ǰԪ�ظ���
{
	assert(hp);
	return hp->num;
}

void HeapSort(int* arr, int n)
{
	assert(arr);
	//����,�Խ�С��Ϊ�����Ӹߵ�������
	int i = 0;
	/*for (i = 1; i < n; i++)
	{
		//���ϵ�������O(NlogN)
		adjustUp(arr, i);
	}*/
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		//���µ�������O(N)
		adjustDown(arr, n, i);
	}
	for (i = n - 1; i > 0; i-- )
	{
		Swap(&arr[0], &arr[i]);
		adjustDown(arr, i , 0);
	}
}