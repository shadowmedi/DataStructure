#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//双向带头循环链表
typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType x;
}LTNode;
LTNode* ListInit();//初始化链表,返回哨兵位头节点

LTNode* BuyListNode(LTDataType x);

void ListPrint(LTNode* phead);

void ListPushBack(LTNode* phead, LTDataType x);//尾插

void ListPushFront(LTNode* phead, LTDataType x);//头插

void ListPopBack(LTNode* phead);//尾删

void ListPopFront(LTNode* phead);//头删

void ListInsert(LTNode* pos, LTDataType x);//在pos之前插入

void ListErase(LTNode* pos, LTNode* phead);//删除pos位置的值

int ListSize(LTNode* phead);

void ListDestory(LTNode* phead);






