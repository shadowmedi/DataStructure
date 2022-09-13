#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

void QueueInit(Queue* queue)//���еĳ�ʼ��
{
	assert(queue);
	queue->phead = queue->tail = NULL;
}

void QueueDestroy(Queue* queue)//��������
{
	assert(queue);
	QNode* cur = queue->phead;//�Ӷ��е�ͷָ�뿪ʼ������������
	while (cur != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
}

QNode* buyQNode(QDataType x)//����ڵ�
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	assert(newNode);
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void QueuePush(Queue* queue, QDataType x)//�����
{
	assert(queue);
	QNode* newNode = buyQNode(x);
	if (QueueEmpty(queue))
	{
		queue->tail = queue->phead = newNode;
	}
	else
	{
		queue->tail->next = newNode;//β��ڵ�
		queue->tail = newNode;//����βָ��
	}
}

void QueuePop(Queue* queue)//������
{
	assert(queue);
	assert(!QueueEmpty(queue));//���в�Ϊ��
	//ֻ��һ���ڵ�
	//�ж���ڵ�
	if (queue->phead == queue->tail)
	{
		free(queue->phead);
		queue->phead = queue->tail = NULL;
	}
	else
	{
		QNode* newHead = queue->phead->next;
		free(queue->phead);
		queue->phead = newHead;
	}
}

QDataType QueueFront(Queue* queue)//ȡ��ͷ����
{
	assert(queue);
	assert(!QueueEmpty(queue));
	return queue->phead->data;
}

QDataType QueueBack(Queue* queue)//ȡ��β����
{
	assert(queue);
	assert(!QueueEmpty(queue));
	return queue->tail->data;
}

bool QueueEmpty(Queue* queue)
{
	assert(queue);
	return queue->phead == NULL;//ͷ��βΪ��˵������һ��Ϊ��
}

int QueueSize(Queue* queue)
{
	assert(queue);
	QNode* cur = queue->phead;
	int num = 0;
	while (cur != NULL)
	{
		num++;
		cur = cur->next;
	}
	return num;
}