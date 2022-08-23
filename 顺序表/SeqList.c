#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"
void SLInit(SL* seqlist)//˳����ʼ��
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

void SLDestroy(SL* seqlist)//˳��������
{
	assert(seqlist);
	free(seqlist->a);
}

void SLPushBack(SL* seqlist, SLDataType x)//˳���β��
{
	assert(seqlist);
	SLCheckCapacity(seqlist);
	seqlist->a[seqlist->size] = x;
	seqlist->size++;
}

void SLPushFront(SL* seqlist, SLDataType x)//˳���ͷ��
{
	assert(seqlist);
	SLCheckCapacity(seqlist);
	//�Ӻ���ǰ ���Ų������
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
	if (seqlist->capacity == seqlist->size)//������е����ݸ���=��������Ҫ��������,������
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

void SLPopBack(SL* seqlist)//˳���βɾ
{
	assert(seqlist && seqlist->size > 0);//�������������0
	seqlist->size--;
}

void SLPopFront(SL* seqlist)//˳���ͷɾ
{
	assert(seqlist&&seqlist->size > 0);//�������������0
	//��ǰ���� ��ǰŲ������
	int begin = 0;
	while(begin <seqlist->size - 1)
	{
		seqlist->a[begin] = seqlist->a[begin+1];
		begin++;
	}
	seqlist->size--;
}

void SLPrint(SL* seqlist)//��ӡ˳�������
{
	assert(seqlist);
	for (int i = 0; i < seqlist->size; i++)
	{
		printf("%d ", seqlist->a[i]);
	}
	putchar('\n');
}

void SLInsert(SL* seqlist, int pos, SLDataType x)//˳�������λ�ò�������
{
	assert(seqlist);
	assert(pos >= 0 && pos <= seqlist->size);
	SLCheckCapacity(seqlist);
	//˳������������(�Ӻ���ǰ) ���Ų����
	int end = seqlist->size - 1;
	while (end >= pos)
	{
		seqlist->a[end + 1] = seqlist->a[end];
		end--;
	}
	seqlist->a[pos] = x;
	seqlist->size++;
}

void SLErase(SL* seqlist, int pos)//˳���ɾ������λ�õ�����
{
	assert(seqlist && seqlist->size > 0);
	assert(pos >= 0 && pos < seqlist->size);
	//˳���ɾ��������(��ǰ����)��ǰŲ����
	int begin = pos;
	while (begin < seqlist->size - 1)
	{
		seqlist->a[begin] = seqlist->a[begin + 1];
		begin++;
	}
	seqlist->size--;
}


int SLSearch(SL* seqlist, SLDataType x) //˳����в��ң������±꣩
{
	assert(seqlist);
	for (int i = 0; i < seqlist->size; i++)
	{
		if (x == seqlist->a[i])
			return i;
	}
	return -1;//û���ҵ�����-1
}

void SLModify(SL* seqlist, int pos, SLDataType x)
{
	assert(seqlist && pos >= 0 && pos < seqlist->size);
	seqlist->a[pos] = x;
}