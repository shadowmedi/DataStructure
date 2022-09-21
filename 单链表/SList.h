#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDataType;
typedef struct SingleListNode//单链表
{
	SLTDataType data;
	struct SingleListNode* next;
}SLTNode;

void SLTPrint(SLTNode* phead);

//O(N)
void SLTPushBack(SLTNode** pphead, SLTDataType x);//尾插
void SLTPopBack(SLTNode** pphead);//尾删

//O(1)
void SLTPushFront(SLTNode** pphead, SLTDataType x);//头插
void SLTPopFront(SLTNode** pphead);//头删

//O(N)
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);//查找

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//pos位置之前插入

void SLTErase(SLTNode** pphead, SLTNode* pos);//删除pos位置的节点



