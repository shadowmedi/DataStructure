#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define MAX 6
typedef struct CircularQueue
{
	int data[MAX];
	int front;//队头下标
	int count;//计数器
	int capacity;
}CQ;

//队列初始化
void QueueInit(CQ* queue);

//队尾入数据
void QueuePush(CQ* queue, int data);

//队头出数据,将删除的值带回
void QueuePop(CQ* queue, int* ret);

//取队头数据
int QueueTop(CQ* queue);

//判断队列是否为空
bool QueueEmpty(CQ* queue);

//判断队列是否已满
bool QueueFull(CQ* queue);
