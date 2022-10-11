#define _CRT_SECURE_NO_WARNINGS
#include "CircularQueue.h"
//队列初始化
void QueueInit(CQ* queue)
{
	assert(queue);
	queue->front = 0;
	queue->capacity = MAX;
	queue->count = 0;
}

//队尾入数据
void QueuePush(CQ* queue, int num)
{
	assert(queue && !QueueFull(queue));
	
	int tail = (queue->front + queue->count - 1);
	if(queue->front <= tail)
		queue->data[(tail + 1) % queue->capacity] = num;
	else
	{
		tail = (queue->front + queue->count - 1) % queue->capacity;
		queue->data[tail + 1] = num;
	}
	queue->count++;
}

//队头出数据,将删除的值带回
void QueuePop(CQ* queue, int* ret)
{
	assert(queue && !QueueEmpty(queue));
	*ret = QueueTop(queue);
	queue->front++;
	queue->front =queue->front % queue->capacity;
	queue->count--;
}

int QueueTop(CQ* queue)
{
	assert(queue);
	return queue->data[queue->front];
}

//判断队列是否为空
bool QueueEmpty(CQ* queue)
{
	assert(queue);
	return queue->count == 0;
}

//判断队列是否已满
bool QueueFull(CQ* queue)
{
	assert(queue);
	return queue->count == queue->capacity;
}