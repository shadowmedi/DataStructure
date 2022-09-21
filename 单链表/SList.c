#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

void SLTPrint(SLTNode* phead)
{
	while (phead != NULL)
	{
		printf("%d->", phead->data);
		phead = phead->next;
	}
	printf("NULL\n");
}

void SLTPushBack(SLTNode** pphead,SLTDataType x)//�������β��
{
	//����ָ��һ����Ϊ��
	assert(pphead);

	//��������ڵ�
	SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode));
	assert(tmp);
	tmp->data = x;
	tmp->next = NULL;

	//��ͷ�ڵ�Ϊ�գ�����Խ����ö���ָ��ı�ͷ�ڵ�
	if (*pphead == NULL)
	{
		*pphead = tmp;
	}

	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = tmp;
	}	
}

void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != NULL && cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void SLTPushFront(SLTNode** pphead, SLTDataType x)//ͷ��
{
	assert(pphead);
	SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode));
	assert(tmp);
	tmp->data = x;
	if (*pphead == NULL)
	{
		tmp->next = NULL;
		*pphead = tmp;
	}
	else
	{
		SLTNode* cur = *pphead;
		tmp->next = cur;
		*pphead = tmp;
	}
}

void SLTPopFront(SLTNode** pphead)//ͷɾ
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;//�����ڶ����ڵ�ĵ�ַ
	SLTNode* phead = *pphead;//��һ���ڵ�ĵ�ַ
	free(phead);//�ѵ�һ���ڵ��ͷŵ�
	*pphead = next;//ͷ�ڵ�ĳɵڶ����ڵ�
}

SLTNode* SLTFind(SLTNode* phead, SLTDataType x)//����,�����޸�����
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)//��posλ��֮ǰ����
{
	assert(pos && pphead && *pphead);
	SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode));
	assert(tmp);
	tmp->data = x;
	SLTNode* cur = *pphead;
	if (cur == pos)
	{
		//ͷ��
		SLTPushFront(pphead, x);
	}
	else
	{
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = tmp;
		tmp->next = pos;
	}
}

void SLTErase(SLTNode** pphead, SLTNode* pos)//ɾ��posλ�õĽڵ�
{
	assert(pphead && *pphead && pos);
	if (pos == *pphead)
	{
		SLTNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
