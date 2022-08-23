#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"
SL seqlist;
/*void testSLPushBack()
{
	SLPushBack(&seqlist, 1);
	SLPushBack(&seqlist, 2);
	SLPushBack(&seqlist, 3);
	SLPushBack(&seqlist, 4);
	SLPushBack(&seqlist, 5);
}*/

void testSLPushFront()
{
	SLPushFront(&seqlist, 6);
	SLPushFront(&seqlist, 7);
	SLPushFront(&seqlist, 8);
	SLPushFront(&seqlist, 9);
	SLPushFront(&seqlist, 10);
}

void testSLPopBack()
{
	SLPopBack(&seqlist);
	SLPopBack(&seqlist);
	SLPopBack(&seqlist);
	SLPopBack(&seqlist);
	SLPopBack(&seqlist);
	//SLPopBack(&seqlist);
}

void testSLPopFront()
{
	SLPopFront(&seqlist);
	SLPopFront(&seqlist);
	SLPopFront(&seqlist);
	SLPopFront(&seqlist);
	SLPopFront(&seqlist);
}

void testSLInsert()
{
	//先尾插4个数据
	SLPushBack(&seqlist, 1);
	SLPushBack(&seqlist, 2);
	SLPushBack(&seqlist, 3);
	SLPushBack(&seqlist, 4);
	SLPrint(&seqlist);// 1  2  3  4
	SLInsert(&seqlist, 0, 5);//相当于头插
	SLPrint(&seqlist);// 5  1  2  3  4
	SLInsert(&seqlist, seqlist.size, 6);//相当于尾插
	SLPrint(&seqlist);// 5  1  2  3  4  6
	SLInsert(&seqlist, 3, 7);//在下标为3的地方插入7
	SLPrint(&seqlist);// 5  1  2  7  3  4  6
}

void testSLErase()
{
	// 5  1  2  7  3  4  6
	SLErase(&seqlist, 0);//相当于头删
	SLPrint(&seqlist);// 1  2  7  3  4  6
	SLErase(&seqlist, seqlist.size - 1);//相当于尾删
	SLPrint(&seqlist);// 1  2  7  3  4
	SLErase(&seqlist, 2);//删除下标为2的数据
	SLPrint(&seqlist);// 1  2  3  4
}

void testSLSearchModify()
{
	// 1  2  3  4
	int x = 0;
	int y = 0;
	printf("请输入你要修改的值以及修改后的值\n");
	scanf("%d  %d", &x, &y);
	int pos = SLSearch(&seqlist, x);
	if (pos != -1)
	{
		SLModify(&seqlist, pos, y);
		SLPrint(&seqlist);
	}
	else
		printf("数据不存在\n");
}

int main()
{
	SLInit(&seqlist);
	//testSLPushBack();
	//testSLPushFront();
	//testSLPopBack();
	//testSLPopFront();
	testSLInsert();
	testSLErase();
	testSLSearchModify();
	//testSLModify();
	SLDestroy(&seqlist);
	return 0;
}