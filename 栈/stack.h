#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define InitialCapacity 3
typedef int SKDataType;
typedef struct stack
{
	SKDataType* data;//存放数据的动态空间
	int top;                  //标识栈顶，也能代表栈的数据量
	int capacity;          //容量
}SK;

void StackInit(SK* stack);//初始化栈
void StackDestory(SK* stack);//销毁栈

void StackPush(SK* stack, SKDataType x);//入栈，因为栈的性质规定它只能在栈顶插入
void StackPop(SK* stack);//出栈

SKDataType StackTop(SK* stack);//取栈顶的元素

bool StackEmpty(SK* stack);//判断栈是否为空

int StackSize(SK* stack);//获取栈的数据个数