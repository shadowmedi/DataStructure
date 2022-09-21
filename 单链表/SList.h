#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDataType;
typedef struct SingleListNode//������
{
	SLTDataType data;
	struct SingleListNode* next;
}SLTNode;

void SLTPrint(SLTNode* phead);

//O(N)
void SLTPushBack(SLTNode** pphead, SLTDataType x);//β��
void SLTPopBack(SLTNode** pphead);//βɾ

//O(1)
void SLTPushFront(SLTNode** pphead, SLTDataType x);//ͷ��
void SLTPopFront(SLTNode** pphead);//ͷɾ

//O(N)
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);//����

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//posλ��֮ǰ����

void SLTErase(SLTNode** pphead, SLTNode* pos);//ɾ��posλ�õĽڵ�



