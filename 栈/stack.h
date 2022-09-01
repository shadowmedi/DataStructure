#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define InitialCapacity 3
typedef int SKDataType;
typedef struct stack
{
	SKDataType* data;//������ݵĶ�̬�ռ�
	int top;                  //��ʶջ����Ҳ�ܴ���ջ��������
	int capacity;          //����
}SK;

void StackInit(SK* stack);//��ʼ��ջ
void StackDestory(SK* stack);//����ջ

void StackPush(SK* stack, SKDataType x);//��ջ����Ϊջ�����ʹ涨��ֻ����ջ������
void StackPop(SK* stack);//��ջ

SKDataType StackTop(SK* stack);//ȡջ����Ԫ��

bool StackEmpty(SK* stack);//�ж�ջ�Ƿ�Ϊ��

int StackSize(SK* stack);//��ȡջ�����ݸ���