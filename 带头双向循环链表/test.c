#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
LTNode* testListInit()
{
	LTNode* phead = ListInit();
	return phead;
}
void testListPushBack(LTNode* phead)
{
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 3);
	ListPrint(phead);
}

void testListPopBack(LTNode* phead)
{
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);
}

void testListPopFront(LTNode* phead)
{
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);

}

void testListInsert(LTNode* phead)
{
	
	ListInsert(phead, 2);
	ListPrint(phead);
	ListInsert(phead->next, 3);//3 2
	
	ListPrint(phead);
}

void testListErase(LTNode* phead)
{
	//3 1 2
	ListErase(phead->prev, phead);
	ListPrint(phead);
}

void testListPushFront(LTNode* phead)
{
	ListPushFront(phead, 1);
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPrint(phead);
}

int main()
{
	LTNode* phead = testListInit();
	//testListPushFront(phead);
	//testListPushBack(phead);
	//testListPopBack(phead);
	//testListPopFront(phead);
	testListInsert(phead);
	//testListErase(phead);
	int k = ListSize(phead);
	printf("%d", k);
	ListDestory(phead);
	phead = NULL;
	return 0;
}