#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 100
typedef  int SLDataType;
//��̬˳���NС���ܴ治�����ݣ�N̫��ռ��˷ѣ���ʵ��
/*struct SeqList
{
	SLDataType a[N];//�洢˳��������ݵ�����
	int size;    //��ǰ���е����ݸ���
};*/

//��̬˳���
typedef struct SeqList
{
	SLDataType* a;//ָ��̬���ٵĿռ�
	int size;//���е����ݸ���,˳���涨�����ݱ���ӵ�һ��λ�ÿ�ʼ�����洢
	int capacity;//��ǰ�����������е���������������ʱ��Ҫ����
}SL;

//1 ��ʼ��˳�����˳��������
void SLInit(SL* seqlist);
void SLDestroy(SL* seqlist);

//2 β��O(1)
void SLPushBack(SL* seqlist, SLDataType x);

//3 ͷ��O(N)
void SLPushFront(SL* seqlist, SLDataType x);

//ͷ��β�嶼��Ҫ�������
void SLCheckCapacity(SL* seqlist);

//4 βɾO(1)
void SLPopBack(SL* seqlist);

//5 ͷɾO(N)
void SLPopFront(SL* seqlist);

//��ӡ˳��������
void SLPrint(SL* seqlist);

//6 ����λ�ò�������
void SLInsert(SL* seqlist, int pos, SLDataType x);

//7 ɾ������λ�õ�����
void SLErase(SL* seqlist, int pos);

//8 ���ң������±꣩
int SLSearch(SL* seqlist, SLDataType x);

//9 �޸�
void SLModify(SL* seqlist, int pos, SLDataType x);
