#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define MAX 6
typedef struct CircularQueue
{
	int data[MAX];
	int front;//��ͷ�±�
	int count;//������
	int capacity;
}CQ;

//���г�ʼ��
void QueueInit(CQ* queue);

//��β������
void QueuePush(CQ* queue, int data);

//��ͷ������,��ɾ����ֵ����
void QueuePop(CQ* queue, int* ret);

//ȡ��ͷ����
int QueueTop(CQ* queue);

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(CQ* queue);

//�ж϶����Ƿ�����
bool QueueFull(CQ* queue);
