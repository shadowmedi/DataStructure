#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

void QueueInit(Queue* queue)//队列的初始化
{
	assert(queue);
	queue->phead = queue->tail = NULL;
}

void QueueDestroy(Queue* queue)//队列销毁
{
	assert(queue);
	QNode* cur = queue->phead;//从队列的头指针开始遍历整个队列
	while (cur != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
}

QNode* buyQNode(QDataType x)//申请节点
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	assert(newNode);
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void QueuePush(Queue* queue, QDataType x)//入队列
{
	assert(queue);
	QNode* newNode = buyQNode(x);
	if (QueueEmpty(queue))
	{
		queue->tail = queue->phead = newNode;
	}
	else
	{
		queue->tail->next = newNode;//尾插节点
		queue->tail = newNode;//更新尾指针
	}
}

void QueuePop(Queue* queue)//出队列
{
	assert(queue);
	assert(!QueueEmpty(queue));//队列不为空
	//只有一个节点
	//有多个节点
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

QDataType QueueFront(Queue* queue)//取队头数据
{
	assert(queue);
	assert(!QueueEmpty(queue));
	return queue->phead->data;
}

QDataType QueueBack(Queue* queue)//取队尾数据
{
	assert(queue);
	assert(!QueueEmpty(queue));
	return queue->tail->data;
}

bool QueueEmpty(Queue* queue)
{
	assert(queue);
	return queue->phead == NULL;//头或尾为空说明队列一定为空
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