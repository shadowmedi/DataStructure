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

void SLTPushBack(SLTNode** pphead,SLTDataType x)//单链表的尾插
{
	//二级指针一定不为空
	assert(pphead);

	//按需申请节点
	SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode));
	assert(tmp);
	tmp->data = x;
	tmp->next = NULL;

	//若头节点为空，则可以解引用二级指针改变头节点
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

void SLTPushFront(SLTNode** pphead, SLTDataType x)//头插
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

void SLTPopFront(SLTNode** pphead)//头删
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;//保留第二个节点的地址
	SLTNode* phead = *pphead;//第一个节点的地址
	free(phead);//把第一个节点释放掉
	*pphead = next;//头节点改成第二个节点
}

SLTNode* SLTFind(SLTNode* phead, SLTDataType x)//查找,附带修改作用
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

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)//在pos位置之前插入
{
	assert(pos && pphead && *pphead);
	SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode));
	assert(tmp);
	tmp->data = x;
	SLTNode* cur = *pphead;
	if (cur == pos)
	{
		//头插
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

void SLTErase(SLTNode** pphead, SLTNode* pos)//删除pos位置的节点
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
