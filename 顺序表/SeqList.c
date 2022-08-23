#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"
void SLInit(SL* seqlist)//顺序表初始化
{
	assert(seqlist);
	seqlist->capacity = 4;
	SLDataType* tem = (SLDataType*)malloc(sizeof(SLDataType) * seqlist->capacity);
	if (tem == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	seqlist->a = tem;
	seqlist->size = 0;
}

void SLDestroy(SL* seqlist)//顺序表的销毁
{
	assert(seqlist);
	free(seqlist->a);
}

void SLPushBack(SL* seqlist, SLDataType x)//顺序表尾插
{
	assert(seqlist);
	SLCheckCapacity(seqlist);
	seqlist->a[seqlist->size] = x;
	seqlist->size++;
}

void SLPushFront(SL* seqlist, SLDataType x)//顺序表头插
{
	assert(seqlist);
	SLCheckCapacity(seqlist);
	//从后往前 向后挪动数据
	int end = seqlist->size - 1;
	while (end >= 0)
	{
		seqlist->a[end + 1] = seqlist->a[end];
		end--;
	}
	seqlist->a[0] = x;
	seqlist->size++;
}

void SLCheckCapacity(SL* seqlist)
{
	assert(seqlist);
	if (seqlist->capacity == seqlist->size)//如果已有的数据个数=容量并且要继续插入,先扩容
	{
		int newcapacity = seqlist->capacity * 2;
		SLDataType* a = (SLDataType*)realloc(seqlist->a, newcapacity * sizeof(SLDataType));
		if (a == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		seqlist->a = a;
		seqlist->capacity *= 2;
	}
}

void SLPopBack(SL* seqlist)//顺序表尾删
{
	assert(seqlist && seqlist->size > 0);//数据量必须大于0
	seqlist->size--;
}

void SLPopFront(SL* seqlist)//顺序表头删
{
	assert(seqlist&&seqlist->size > 0);//数据量必须大于0
	//从前往后 向前挪动数据
	int begin = 0;
	while(begin <seqlist->size - 1)
	{
		seqlist->a[begin] = seqlist->a[begin+1];
		begin++;
	}
	seqlist->size--;
}

void SLPrint(SL* seqlist)//打印顺序表数据
{
	assert(seqlist);
	for (int i = 0; i < seqlist->size; i++)
	{
		printf("%d ", seqlist->a[i]);
	}
	putchar('\n');
}

void SLInsert(SL* seqlist, int pos, SLDataType x)//顺序表任意位置插入数据
{
	assert(seqlist);
	assert(pos >= 0 && pos <= seqlist->size);
	SLCheckCapacity(seqlist);
	//顺序表插入数据是(从后往前) 向后挪数据
	int end = seqlist->size - 1;
	while (end >= pos)
	{
		seqlist->a[end + 1] = seqlist->a[end];
		end--;
	}
	seqlist->a[pos] = x;
	seqlist->size++;
}

void SLErase(SL* seqlist, int pos)//顺序表删除任意位置的数据
{
	assert(seqlist && seqlist->size > 0);
	assert(pos >= 0 && pos < seqlist->size);
	//顺序表删除数据是(从前往后)向前挪数据
	int begin = pos;
	while (begin < seqlist->size - 1)
	{
		seqlist->a[begin] = seqlist->a[begin + 1];
		begin++;
	}
	seqlist->size--;
}


int SLSearch(SL* seqlist, SLDataType x) //顺序表中查找（返回下标）
{
	assert(seqlist);
	for (int i = 0; i < seqlist->size; i++)
	{
		if (x == seqlist->a[i])
			return i;
	}
	return -1;//没有找到返回-1
}

void SLModify(SL* seqlist, int pos, SLDataType x)
{
	assert(seqlist && pos >= 0 && pos < seqlist->size);
	seqlist->a[pos] = x;
}