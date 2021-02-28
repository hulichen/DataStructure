#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

#define ElemTepe  int
#define SEQLIST_DEFAULT_SIZE 4
#define EXPASIONNUM  2

typedef struct SeqList {
	ElemTepe* base;
	int size;
	int cap;
}SeqList;

void SeqListInit(SeqList* psl);// 顺序表初始化
void SeqListShow(SeqList* psl);  //显示
void SeqListPushBack(SeqList* psl);// 顺序表尾插
void SeqListPopBack(SeqList* psl);// 顺序表尾删
void SeqListPushFront(SeqList* psl, ElemTepe x);// 顺序表头插
void SeqListPopFront(SeqList* psl);// 顺序表头删
void SeqListInsert_pos(SeqList* psl, size_t pos, ElemTepe x);// 顺序表在pos位置插入x
void SeqListInsert_val(SeqList* psl, ElemTepe x);// 顺序表排序后插入x
void SeqListReverse(SeqList* psl);  //翻转
int SeqListFind(SeqList * psl, ElemTepe x);//查找
void SeqListDelete_val(SeqList* psl, ElemTepe x,int delselect); //删除指定值
void SeqListDelete_pos(SeqList* psl, int pos); //删除指定位置的值
void SeqListSort(SeqList* psl);//从小到大冒泡排序
int CheckCapacity(SeqList* psl);// 检查空间，如果满了，进行增容
void SeqListRemove_all(SeqList* psl);
void SeqListDestroy(SeqList* psl);


#endif 
