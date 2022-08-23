#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"
void testSLTPrint()
{
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n1);
	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n2);
	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n3);
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	SLTPrint(n1);
}

void testSLTPushBack()
{
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n1);
	n1->data = 0;
	n1->next = NULL;
	SLTPushBack(&n1, 1);
	SLTPushBack(&n1, 2);
	SLTPushBack(&n1, 3);
	SLTPushBack(&n1, 4);
	SLTPrint(n1);
}

void testSLTPopBack()
{
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n1);
	n1->data = 0;
	n1->next = NULL;
	SLTPushBack(&n1, 1);
	SLTPushBack(&n1, 2);
	SLTPushBack(&n1, 3);
	SLTPushBack(&n1, 4);
	SLTPrint(n1);
	SLTPopBack(&n1);
	SLTPrint(n1);
	SLTPopBack(&n1);
	SLTPrint(n1);
	SLTPopBack(&n1);
	SLTPrint(n1);
	SLTPopBack(&n1);
	SLTPrint(n1);
	SLTPopBack(&n1);
	SLTPrint(n1);
}

void testSLTPushFront()
{
	SLTNode* phead = (SLTNode*)malloc(sizeof(SLTNode));
	assert(phead);
	phead->next = NULL;
	phead->data = 0;
	SLTPrint(phead);
	SLTPushFront(&phead, 1);
	SLTPrint(phead);
	SLTPushFront(&phead, 2);
	SLTPrint(phead);
}

void testSLTPopFront()
{
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n1);
	n1->data = 0;
	n1->next = NULL;
	SLTPushBack(&n1, 1);
	SLTPushBack(&n1, 2);
	SLTPushBack(&n1, 3);
	SLTPushBack(&n1, 4);
	SLTPrint(n1);
	SLTPopFront(&n1);
	SLTPrint(n1);
	SLTPopFront(&n1);
	SLTPrint(n1);
	SLTPopFront(&n1);
	SLTPrint(n1);
	SLTPopFront(&n1);
	SLTPrint(n1);
	SLTPopFront(&n1);
	SLTPrint(n1);
	
}

void testSLTFindInsert()
{
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n1);
	n1->data = 0;
	n1->next = NULL;
	SLTPushBack(&n1, 1);
	SLTPushBack(&n1, 2);
	SLTPushBack(&n1, 3);
	SLTPushBack(&n1, 4);
	SLTPrint(n1);
	SLTNode* pos = SLTFind(n1, 4);
	SLTInsert(&n1, pos, 5);
	SLTPrint(n1);

}

void testSLTErase()
{
	SLTNode* phead = (SLTNode*)malloc(sizeof(SLTNode));
	assert(phead);
	phead->data = 1;
	phead->next = NULL;
	SLTPushBack(&phead, 2);
	SLTPushBack(&phead, 3);
	SLTPushFront(&phead, 0);
	SLTPrint(phead);
	SLTNode* pos1 = SLTFind(phead, 0);
	SLTNode* pos2 = SLTFind(phead, 1);
	if (pos1 != NULL)
	{
		SLTErase(&phead, pos1);
		SLTPrint(phead);
	}
	if (pos2 != NULL)
	{
		SLTErase(&phead, pos2);
		SLTPrint(phead);
	}
}

int main()
{
	//testSLTPrint();
	//testSLTPushBack();
	//testSLTPopBack();
	//testSLTPushFront();
	//testSLTPopFront();
	//testSLTFindInsert();
	testSLTErase();
	return 0;
}