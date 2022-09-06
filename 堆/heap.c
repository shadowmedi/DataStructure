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

void adjustUp(HeapDataType* a, int child)//以小堆为例
{
	assert(a);
	//要把孩子调到正确的地方
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;//要调整的孩子更新
			parent = (child - 1) / 2;//父亲更新
		}
		else
			return;
	}
}

void HeapPush(Heap* hp, HeapDataType x)
{
	assert(hp);
	//判断扩容
	if (hp->num == hp->capacity)
	{
		int newCapacity = 2 * hp->capacity;
		HeapDataType* tmp = (HeapDataType*)realloc(hp->data, sizeof(HeapDataType) * newCapacity);
		assert(tmp);
		hp->data = tmp;
		hp->capacity = newCapacity;
	}
	//尾插到数组
	hp->data[hp->num++] = x;
	//重新把数据整成堆
	adjustUp(hp->data, hp->num - 1);
}

void adjustDown(HeapDataType* a, int num, int parent)//有num个元素,从parent开始调整
{
	assert(a);
	int lesschild = parent * 2 + 1;
	while (lesschild <= num - 1)
	{
		if (lesschild + 1 <= num - 1)
		{
			//找出左右孩子中最小的孩子
			if (a[lesschild] > a[lesschild + 1])
				lesschild++;
		}
		//若父亲比孩子大，则交换，否则调整结束
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

void HeapPop(Heap* hp)//删除堆顶的数据，剩下的数依旧保持是小堆
{
	assert(hp);
	assert(hp->num > 0);
	Swap(&hp->data[0], &hp->data[hp->num - 1]);
	hp->num--;
	adjustDown(hp->data, hp->num, 0);
}

HeapDataType HeapTop(Heap* hp)//取堆顶的数据
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->data[0];
}

bool HeapEmpty(Heap* hp)//判断堆是否为空
{
	assert(hp);
	return hp->num == 0;
}

int HeapSize(Heap* hp)//堆的当前元素个数
{
	assert(hp);
	return hp->num;
}

void HeapSort(int* arr, int n)
{
	assert(arr);
	//建堆,以建小堆为例，从高到低排序
	int i = 0;
	/*for (i = 1; i < n; i++)
	{
		//向上调整建堆O(NlogN)
		adjustUp(arr, i);
	}*/
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		//向下调整建堆O(N)
		adjustDown(arr, n, i);
	}
	for (i = n - 1; i > 0; i-- )
	{
		Swap(&arr[0], &arr[i]);
		adjustDown(arr, i , 0);
	}
}