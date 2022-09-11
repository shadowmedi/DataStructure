#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int QDataType;
typedef struct QueueNode//定义队列的节点
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue//定义队列
{
	QNode* phead;//队头
	QNode* tail;//队尾   在队尾入数据，队头出数据
}Queue;

void QueueInit(Queue* queue);//队列初始化                                              
void QueueDestroy(Queue* queue);//队列销毁

QNode* buyQNode(QDataType x);//申请新节点

void QueuePush(Queue* queue, QDataType x);//固定在队尾入数据
void QueuePop(Queue* queue);//固定删除队头数据

QDataType QueueFront(Queue* queue);//取队头的数据
QDataType QueueBack(Queue* queue);//取队尾的数据

bool QueueEmpty(Queue* queue);//判断队列是否为空
int QueueSize(Queue* queue);//计算队列数据个数

