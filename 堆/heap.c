#define _CRT_SECURE_NO_WARNINGS
#include "heap.h"

//��ӡ���е�����
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->num; i++)
	{
		printf("%d ", hp->data[i]);
	}
	printf("\n");
}

//�������е�����
void Swap(HeapDataType* a, HeapDataType* b)
{
	HeapDataType tem = *a;
	*a = *b;
	*b = tem;
}

//�ѵĳ�ʼ��
void HeapInit(Heap* hp)
{
	assert(hp);
	HeapDataType* tmp = (HeapDataType*)malloc(sizeof(HeapDataType) * InitialCapacity);
	assert(tmp);
	hp->data = tmp;
	hp->capacity = InitialCapacity;
	hp->num = 0;
}

//�ѵ�����
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->data);
	hp->data = NULL;
	hp->capacity = hp->num = 0;
}

//���ϵ����㷨
void adjustUp(HeapDataType* a, int insert)//��С��Ϊ��
{
	//����Ľ��ֻ��Ӱ���������Ƚ��
	assert(a);
	//������ĸ���
	int parent = (insert - 1) / 2;
	//������������������ʱ������һ������
	while (insert > 0)
	{
		//���������ֵ�����ĸ���С���򽻻�
		if (a[insert] < a[parent])
		{
			Swap(&a[insert], &a[parent]);
			//��������±����
			insert = parent;
			//������ĸ��׸���
			parent = (insert - 1) / 2;
		}
		else
			return;
	}
}

void HeapPush(Heap* hp, HeapDataType x)
{
	assert(hp);
	//�ж��Ƿ���Ҫ����
	if (hp->num == hp->capacity)
	{
		int newCapacity = 2 * hp->capacity;
		HeapDataType* tmp = (HeapDataType*)realloc(hp->data, sizeof(HeapDataType) * newCapacity);
		assert(tmp);
		hp->data = tmp;
		hp->capacity = newCapacity;
	}
	//β��
	hp->data[hp->num++] = x;
	//���ϵ��������ݵ��ɶ�
	adjustUp(hp->data, hp->num - 1);
}

//���µ����㷨
void adjustDown(HeapDataType* a, int num, int pour)//��num��Ԫ��,�ӽ��pour��ʼ����
{
	//ǰ�᣺pour����������С�ѣ�������Ҳ��С��
	//����˼·��
	//ѡ�����Һ�����С����һ��
	//С���Ǹ����Ӻ�pour�Ƚ�
	//���pour���򽻻�������pour,�������µ���
	//���pourС����������
	assert(a);
	//������С�ĺ���������
	int lesschild = pour * 2 + 1;
	while (lesschild <= num - 1)
	{
		//�ж��Ƿ����Һ���
		if (lesschild + 1 <= num - 1)
		{
			//���������С�ĺ��ӵ���Ϊ�Һ���
			if (a[lesschild] > a[lesschild + 1])
				lesschild++;
		}
		//����������С�ĺ��Ӵ�
		if (a[pour] > a[lesschild])
		{
			Swap(&a[pour], &a[lesschild]);
			//���µ�����±�
			pour = lesschild;
			//���µ����ĺ���
			lesschild = 2 * pour + 1;
		}
		else
			return;
	}
}
//�ݹ���ʽ
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

//ɾ���Ѷ������ݣ�ʣ�µ������ɱ�����С�ѣ�ʹ�����µ����㷨��
void HeapPop(Heap* hp)
{
	//����˼·��
	//�����Ѷ��������һ����㣬����Ľ����-1��֮�������µ����㷨���°���������ɶ�
	assert(hp);
	assert(hp->num > 0);
	//�����Ѷ��������һ�����
	Swap(&hp->data[0], &hp->data[hp->num - 1]);
	//�����-1��ԭ���ĶѶ����ݾͱ�ɾ��
	hp->num--;
	//���µ����㷨
	adjustDown(hp->data, hp->num, 0);
}

//ȡ�Ѷ�������
HeapDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->data[0];
}

//�ж϶��Ƿ�Ϊ��
bool HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->num == 0;
}

//�ѵĵ�ǰԪ�ظ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->num;
}

//���������򽨴�ѣ�����С�ѣ�
void HeapSort(int* arr, int n)
{
	//����˼·��
	//����������ɶѣ�Ȼ�������µ����㷨����ѡ��
	assert(arr);
	//����,�Խ�С��Ϊ�����Ž���
	int i = 0;
	//���ϵ�������O(NlogN)
	/*for (i = 1; i < n; i++)
	{
		adjustUp(arr, i);
	}*/
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		//���µ�������O(N)
		//�ӵ�����һ����Ҷ�ӽ�㿪ʼ����֤arr[i]��������������������С��
		adjustDown(arr, n, i);
	}
	for (i = n - 1; i > 0; i-- )
	{
		//�����Ѷ��������һ����㣬��min�ŵ�����
		Swap(&arr[0], &arr[i]);
		//��ʣ�µ������½��ɶ�
		adjustDown(arr, i , 0);
	}
}

void PrintTopk(int* data, int n, int k)
{
	//ȡǰk�������
	assert(data);
	//1 ����k�����ݴ�С�Ķ�
	int* KMinHeap = (int*)malloc(sizeof(int) * k);
	assert(KMinHeap);
	int i = 0;
	//����ǰk�����ݽ�С��
	for (i = 0; i < k; i++)
	{
		KMinHeap[i] = data[i];
	}
	for (i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		adjustDown(KMinHeap, k, i);
	}
	//��ʣ�µ�(N-k)���������κͶѶ��Ƚϣ����ȶѶ������ݴ����滻���Ѷ�������
	for (i = k; i < n; i++)
	{
		if (data[i] > KMinHeap[0])
		{
			Swap(&data[i], &KMinHeap[0]);
			//���µ������µ��ɶ�
			adjustDown(KMinHeap, k, 0);
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", KMinHeap[i]);
	}
	putchar('\n');
}