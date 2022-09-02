#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int QDataType;
typedef struct QueueNode//������еĽڵ�
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue//�������
{
	QNode* phead;//��ͷ
	QNode* tail;//��β   �ڶ�β�����ݣ���ͷ������
}Queue;

void QueueInit(Queue* queue);//���г�ʼ��                                              
void QueueDestroy(Queue* queue);//��������

QNode* buyQNode(QDataType x);//�����½ڵ�

void QueuePush(Queue* queue, QDataType x);//�̶��ڶ�β������
void QueuePop(Queue* queue);//�̶�ɾ����ͷ����

QDataType QueueFront(Queue* queue);//ȡ��ͷ������
QDataType QueueBack(Queue* queue);//ȡ��β������

bool QueueEmpty(Queue* queue);//�ж϶����Ƿ�Ϊ��
int QueueSize(Queue* queue);//����������ݸ���

