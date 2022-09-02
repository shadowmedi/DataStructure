#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

void queueTest()
{
	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	int size = QueueSize(&queue);
	while (!QueueEmpty(&queue))
	{
		printf("%d ", QueueFront(&queue));
		QueuePop(&queue);
	}
}
int main()
{
	queueTest();
	return 0;
}
