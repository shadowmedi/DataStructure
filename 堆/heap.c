#define _CRT_SECURE_NO_WARNINGS
#include "heap.h"

//打印堆中的数据
void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->num; i++)
	{
		printf("%d ", hp->data[i]);
	}
	printf("\n");
}

//交换堆中的数据
void Swap(HeapDataType* a, HeapDataType* b)
{
	HeapDataType tem = *a;
	*a = *b;
	*b = tem;
}

//堆的初始化
void HeapInit(Heap* hp)
{
	assert(hp);
	HeapDataType* tmp = (HeapDataType*)malloc(sizeof(HeapDataType) * InitialCapacity);
	assert(tmp);
	hp->data = tmp;
	hp->capacity = InitialCapacity;
	hp->num = 0;
}

//堆的销毁
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->data);
	hp->data = NULL;
	hp->capacity = hp->num = 0;
}

//向上调整算法
void adjustUp(HeapDataType* a, int insert)//以小堆为例
{
	//插入的结点只会影响它的祖先结点
	assert(a);
	//插入结点的父亲
	int parent = (insert - 1) / 2;
	//当插入结点调整到根结点时，调整一定结束
	while (insert > 0)
	{
		//若插入结点的值比它的父亲小，则交换
		if (a[insert] < a[parent])
		{
			Swap(&a[insert], &a[parent]);
			//插入结点的下标更新
			insert = parent;
			//插入结点的父亲更新
			parent = (insert - 1) / 2;
		}
		else
			return;
	}
}

void HeapPush(Heap* hp, HeapDataType x)
{
	assert(hp);
	//判断是否需要扩容
	if (hp->num == hp->capacity)
	{
		int newCapacity = 2 * hp->capacity;
		HeapDataType* tmp = (HeapDataType*)realloc(hp->data, sizeof(HeapDataType) * newCapacity);
		assert(tmp);
		hp->data = tmp;
		hp->capacity = newCapacity;
	}
	//尾插
	hp->data[hp->num++] = x;
	//向上调整把数据调成堆
	adjustUp(hp->data, hp->num - 1);
}

//向下调整算法
void adjustDown(HeapDataType* a, int num, int pour)//有num个元素,从结点pour开始调整
{
	//前提：pour的左子树是小堆，右子树也是小堆
	//总体思路：
	//选出左右孩子中小的那一个
	//小的那个孩子和pour比较
	//如果pour大，则交换，更新pour,继续往下调整
	//如果pour小，调整结束
	assert(a);
	//假设最小的孩子是左孩子
	int lesschild = pour * 2 + 1;
	while (lesschild <= num - 1)
	{
		//判断是否有右孩子
		if (lesschild + 1 <= num - 1)
		{
			//假设错误，最小的孩子调整为右孩子
			if (a[lesschild] > a[lesschild + 1])
				lesschild++;
		}
		//若倒结点比最小的孩子大
		if (a[pour] > a[lesschild])
		{
			Swap(&a[pour], &a[lesschild]);
			//更新倒结点下标
			pour = lesschild;
			//更新倒结点的孩子
			lesschild = 2 * pour + 1;
		}
		else
			return;
	}
}
//递归形式
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

//删除堆顶的数据，剩下的数依旧保持是小堆（使用向下调整算法）
void HeapPop(Heap* hp)
{
	//总体思路：
	//交换堆顶结点和最后一个结点，堆里的结点数-1，之后用向下调整算法重新把数组调整成堆
	assert(hp);
	assert(hp->num > 0);
	//交换堆顶结点和最后一个结点
	Swap(&hp->data[0], &hp->data[hp->num - 1]);
	//结点数-1，原来的堆顶数据就被删除
	hp->num--;
	//向下调整算法
	adjustDown(hp->data, hp->num, 0);
}

//取堆顶的数据
HeapDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->data[0];
}

//判断堆是否为空
bool HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->num == 0;
}

//堆的当前元素个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->num;
}

//堆排序（升序建大堆，降序建小堆）
void HeapSort(int* arr, int n)
{
	//总体思路：
	//把数组调整成堆，然后用向下调整算法依次选数
	assert(arr);
	//建堆,以建小堆为例，排降序
	int i = 0;
	//向上调整建堆O(NlogN)
	/*for (i = 1; i < n; i++)
	{
		adjustUp(arr, i);
	}*/
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		//向下调整建堆O(N)
		//从倒数第一个非叶子结点开始，保证arr[i]的左子树和右子树都是小堆
		adjustDown(arr, n, i);
	}
	for (i = n - 1; i > 0; i-- )
	{
		//交换堆顶结点和最后一个结点，把min放到后面
		Swap(&arr[0], &arr[i]);
		//将剩下的数重新建成堆
		adjustDown(arr, i , 0);
	}
}

void PrintTopk(int* data, int n, int k)
{
	//取前k个大的数
	assert(data);
	//1 建立k个数据大小的堆
	int* KMinHeap = (int*)malloc(sizeof(int) * k);
	assert(KMinHeap);
	int i = 0;
	//先用前k个数据建小堆
	for (i = 0; i < k; i++)
	{
		KMinHeap[i] = data[i];
	}
	for (i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		adjustDown(KMinHeap, k, i);
	}
	//把剩下的(N-k)个数据依次和堆顶比较，若比堆顶的数据大则替换掉堆顶的数据
	for (i = k; i < n; i++)
	{
		if (data[i] > KMinHeap[0])
		{
			Swap(&data[i], &KMinHeap[0]);
			//向下调整重新调成堆
			adjustDown(KMinHeap, k, 0);
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", KMinHeap[i]);
	}
	putchar('\n');
}