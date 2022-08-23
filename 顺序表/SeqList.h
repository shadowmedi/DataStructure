#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 100
typedef  int SLDataType;
//静态顺序表：N小可能存不下数据，N太大空间浪费，不实用
/*struct SeqList
{
	SLDataType a[N];//存储顺序表中数据的数组
	int size;    //当前已有的数据个数
};*/

//动态顺序表
typedef struct SeqList
{
	SLDataType* a;//指向动态开辟的空间
	int size;//已有的数据个数,顺序表规定：数据必须从第一个位置开始连续存储
	int capacity;//当前容量，当已有的数据量比容量大时，要扩容
}SL;

//1 初始化顺序表与顺序表的销毁
void SLInit(SL* seqlist);
void SLDestroy(SL* seqlist);

//2 尾插O(1)
void SLPushBack(SL* seqlist, SLDataType x);

//3 头插O(N)
void SLPushFront(SL* seqlist, SLDataType x);

//头插尾插都需要检查容量
void SLCheckCapacity(SL* seqlist);

//4 尾删O(1)
void SLPopBack(SL* seqlist);

//5 头删O(N)
void SLPopFront(SL* seqlist);

//打印顺序表的数据
void SLPrint(SL* seqlist);

//6 任意位置插入数据
void SLInsert(SL* seqlist, int pos, SLDataType x);

//7 删除任意位置的数据
void SLErase(SL* seqlist, int pos);

//8 查找（返回下标）
int SLSearch(SL* seqlist, SLDataType x);

//9 修改
void SLModify(SL* seqlist, int pos, SLDataType x);
