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
	//��β��4������
	SLPushBack(&seqlist, 1);
	SLPushBack(&seqlist, 2);
	SLPushBack(&seqlist, 3);
	SLPushBack(&seqlist, 4);
	SLPrint(&seqlist);// 1  2  3  4
	SLInsert(&seqlist, 0, 5);//�൱��ͷ��
	SLPrint(&seqlist);// 5  1  2  3  4
	SLInsert(&seqlist, seqlist.size, 6);//�൱��β��
	SLPrint(&seqlist);// 5  1  2  3  4  6
	SLInsert(&seqlist, 3, 7);//���±�Ϊ3�ĵط�����7
	SLPrint(&seqlist);// 5  1  2  7  3  4  6
}

void testSLErase()
{
	// 5  1  2  7  3  4  6
	SLErase(&seqlist, 0);//�൱��ͷɾ
	SLPrint(&seqlist);// 1  2  7  3  4  6
	SLErase(&seqlist, seqlist.size - 1);//�൱��βɾ
	SLPrint(&seqlist);// 1  2  7  3  4
	SLErase(&seqlist, 2);//ɾ���±�Ϊ2������
	SLPrint(&seqlist);// 1  2  3  4
}

void testSLSearchModify()
{
	// 1  2  3  4
	int x = 0;
	int y = 0;
	printf("��������Ҫ�޸ĵ�ֵ�Լ��޸ĺ��ֵ\n");
	scanf("%d  %d", &x, &y);
	int pos = SLSearch(&seqlist, x);
	if (pos != -1)
	{
		SLModify(&seqlist, pos, y);
		SLPrint(&seqlist);
	}
	else
		printf("���ݲ�����\n");
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