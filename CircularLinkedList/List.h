#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//˫���ͷѭ������
typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType x;
}LTNode;
LTNode* ListInit();//��ʼ������,�����ڱ�λͷ�ڵ�

LTNode* BuyListNode(LTDataType x);

void ListPrint(LTNode* phead);

void ListPushBack(LTNode* phead, LTDataType x);//β��

void ListPushFront(LTNode* phead, LTDataType x);//ͷ��

void ListPopBack(LTNode* phead);//βɾ

void ListPopFront(LTNode* phead);//ͷɾ

void ListInsert(LTNode* pos, LTDataType x);//��pos֮ǰ����

void ListErase(LTNode* pos, LTNode* phead);//ɾ��posλ�õ�ֵ

int ListSize(LTNode* phead);

void ListDestory(LTNode* phead);






