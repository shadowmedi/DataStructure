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
	for (int i = 1; i < n; i++)//ѭ���Ĵ�������Ҫ��ӡ������
	{	
		printf("%d ", QueueTop(&queue));
		QueuePop(&queue, &save);
		QueuePush(&queue, save);
		QueuePush(&queue, QueueTop(&queue) + save);
		//����1��Ҫ��ӡ��������
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
		//������Ҫ��ӡ��������ÿ��ӡ��һ��Ҫ����
		//��������
		printf("%d ", QueueTop(&queue));
		QueuePop(&queue, &save);
		QueuePush(&queue, 1);
		QueuePush(&queue, 1 + QueueTop(&queue));
		
		//��������1֮�������
		for (int i = 0; i < row - 2; i++)
		{
			printf("%d ",QueueTop(&queue));
			QueuePop(&queue, &save);
			QueuePush(&queue,save + QueueTop(&queue));
		}
		//������ĩ
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