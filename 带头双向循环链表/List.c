#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
LTNode* ListInit()//链表初始化
{
	//malloc一个哨兵位头节点，该节点不存储有效数据
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	assert(phead);
	phead->next = phead;
	phead->prev = phead;
}

LTNode* BuyListNode(LTDataType x)//申请节点
{
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	assert(newNode);
	newNode->x = x;
}

void ListPrint(LTNode* phead)//打印链表
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->x);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(LTNode* phead, LTDataType x)//尾插
{
	/*LTNode* tail = phead->prev;
	LTNode* newNode = BuyListNode(x);
	newNode->prev = tail;
	tail->next = newNode;
	newNode->next = phead;
	phead->prev = newNode;*/
	ListInsert(phead, x);
}

void ListPushFront(LTNode* phead, LTDataType x)//头插
{
	/*LTNode* newNode = BuyListNode(x);
	LTNode* head = phead->next;//记录头节点(非哨兵位)
	newNode->next = head;
	head->prev = newNode;
	newNode->prev = phead;
	phead->next = newNode;*/
	ListInsert(phead->next, x);
}

bool ListEmpty(LTNode* phead)//判断链表是否为空
{
	assert(phead);
	return phead->next == phead;
}

void ListPopBack(LTNode* phead)//尾删
{
	assert(phead);
	assert(!ListEmpty(phead));
	/*LTNode* tail = phead->prev;
	phead->prev = tail->prev;
	tail->prev->next = phead;
	free(tail);*/
	/*LTNode* tailpre = tail->prev;
	tailpre->next = phead;
	phead->prev = tailpre;
	free(tail);*/
	ListErase(phead->prev, phead);
}

void ListPopFront(LTNode* phead)//头删
{
	assert(phead);
	assert(!ListEmpty(phead));
	/*LTNode* head = phead->next;//记录头节点(不特指哨兵位)
	LTNode* headnext = head->next;
	phead->next = headnext;
	headnext->prev = phead;
	free(head);*/
	ListErase(phead->next, phead);
}

void ListInsert(LTNode* pos, LTDataType x)//在pos位置前插入
{
	assert(pos);
	LTNode* newNode = BuyListNode(x);
	LTNode* prev = pos->prev;
	prev->next = newNode;
	newNode->prev = prev;
	newNode->next = pos;
	pos->prev = newNode;
}

void ListErase(LTNode* pos, LTNode* phead)//删除pos位置的节点
{
	assert(pos);
	assert(!ListEmpty(phead));
	LTNode* pre = pos->prev;
	LTNode* next = pos->next;
	pre->next = next;
	next->prev = pre;
	free(pos);
}

int ListSize(LTNode* phead)
{
	LTNode* cur = phead->next;
	int num = 0;
	while (cur != phead)
	{
		cur = cur->next;
		num++;
	}
	return num;
}

void ListDestory(LTNode* phead)//销毁链表
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}