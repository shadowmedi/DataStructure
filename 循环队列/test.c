#define _CRT_SECURE_NO_WARNINGS
#include "CircularQueue.h"
void test1()
{
	CQ queue;
	QueueInit(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);//1   2   3   []    []    [] 
	int ret = 0;
	QueuePop(&queue, &ret);//[]  2   3  []   []   [] 
	printf("%d  ", ret);
	QueuePop(&queue, &ret);//[]  []   3  []   []   []
	printf("%d\n", ret);
	QueuePush(&queue, 4);//[]  []  3  4 []  []
	printf("front = %d  count = %d\n", queue.front, queue.count);

}
void test2()
{
	CQ queue;
	QueueInit(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePush(&queue, 5);
	QueuePush(&queue, 6);
	int ret = 0;
	QueuePop(&queue, &ret);
	QueuePop(&queue, &ret);
	QueuePop(&queue, &ret);
	QueuePush(&queue, 7);
	QueuePush(&queue, 8);
	while (!QueueEmpty(&queue))
	{
		QueuePop(&queue, &ret);
		printf("%d ", ret);
	}
}

void PascalTriangle(int n)
{
	printf("1\n");
	if (n == 1)
		return;
	CQ queue;
	QueueInit(&queue);
	int save = 0;
	QueuePush(&queue, 1);
	QueuePush(&queue, 1);
	for (int i = 1; i < n; i++)//循环的次数就是要打印的行数
	{	
		printf("%d ", QueueTop(&queue));
		QueuePop(&queue, &save);
		QueuePush(&queue, save);
		QueuePush(&queue, QueueTop(&queue) + save);
		//两个1中要打印的数据量
		for (int j = 0; j < i - 1; j++)
		{
			printf("%d ", QueueTop(&queue));
			QueuePop(&queue, &save);
			QueuePush(&queue, save + QueueTop(&queue));
		}
		printf("%d\n", QueueTop(&queue));
		QueuePop(&queue, &save);
		QueuePush(&queue, save);
	}
}


void PascalTriangle2(int n)
{
	printf("1\n");
	if (n == 1)
		return;
	CQ queue;
	QueueInit(&queue);
	int save = 0;
	QueuePush(&queue, 1);
	QueuePush(&queue, 1);
	for (int row = 2; row <= n; row++)
	{
		//接下来要打印的行数，每打印完一行要换行
		//处理行首
		printf("%d ", QueueTop(&queue));
		QueuePop(&queue, &save);
		QueuePush(&queue, 1);
		QueuePush(&queue, 1 + QueueTop(&queue));
		
		//处理两个1之间的数据
		for (int i = 0; i < row - 2; i++)
		{
			printf("%d ",QueueTop(&queue));
			QueuePop(&queue, &save);
			QueuePush(&queue,save + QueueTop(&queue));
		}
		//处理行末
		printf("%d\n", QueueTop(&queue));
		QueuePop(&queue, &save);
		QueuePush(&queue, 1);
	}
}

int main()
{
	test1();
	int n = 0;
	
	//scanf("%d", &n);
	PascalTriangle2(n);
	return 0;
}