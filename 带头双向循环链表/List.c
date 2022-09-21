#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
LTNode* ListInit()//�����ʼ��
{
	//mallocһ���ڱ�λͷ�ڵ㣬�ýڵ㲻�洢��Ч����
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	assert(phead);
	phead->next = phead;
	phead->prev = phead;
}

LTNode* BuyListNode(LTDataType x)//����ڵ�
{
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	assert(newNode);
	newNode->x = x;
}

void ListPrint(LTNode* phead)//��ӡ����
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->x);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(LTNode* phead, LTDataType x)//β��
{
	/*LTNode* tail = phead->prev;
	LTNode* newNode = BuyListNode(x);
	newNode->prev = tail;
	tail->next = newNode;
	newNode->next = phead;
	phead->prev = newNode;*/
	ListInsert(phead, x);
}

void ListPushFront(LTNode* phead, LTDataType x)//ͷ��
{
	/*LTNode* newNode = BuyListNode(x);
	LTNode* head = phead->next;//��¼ͷ�ڵ�(���ڱ�λ)
	newNode->next = head;
	head->prev = newNode;
	newNode->prev = phead;
	phead->next = newNode;*/
	ListInsert(phead->next, x);
}

bool ListEmpty(LTNode* phead)//�ж������Ƿ�Ϊ��
{
	assert(phead);
	return phead->next == phead;
}

void ListPopBack(LTNode* phead)//βɾ
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

void ListPopFront(LTNode* phead)//ͷɾ
{
	assert(phead);
	assert(!ListEmpty(phead));
	/*LTNode* head = phead->next;//��¼ͷ�ڵ�(����ָ�ڱ�λ)
	LTNode* headnext = head->next;
	phead->next = headnext;
	headnext->prev = phead;
	free(head);*/
	ListErase(phead->next, phead);
}

void ListInsert(LTNode* pos, LTDataType x)//��posλ��ǰ����
{
	assert(pos);
	LTNode* newNode = BuyListNode(x);
	LTNode* prev = pos->prev;
	prev->next = newNode;
	newNode->prev = prev;
	newNode->next = pos;
	pos->prev = newNode;
}

void ListErase(LTNode* pos, LTNode* phead)//ɾ��posλ�õĽڵ�
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

void ListDestory(LTNode* phead)//��������
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