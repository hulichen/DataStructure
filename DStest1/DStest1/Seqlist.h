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

void SeqListInit(SeqList* psl);// ˳����ʼ��
void SeqListShow(SeqList* psl);  //��ʾ
void SeqListPushBack(SeqList* psl);// ˳���β��
void SeqListPopBack(SeqList* psl);// ˳���βɾ
void SeqListPushFront(SeqList* psl, ElemTepe x);// ˳���ͷ��
void SeqListPopFront(SeqList* psl);// ˳���ͷɾ
void SeqListInsert_pos(SeqList* psl, size_t pos, ElemTepe x);// ˳�����posλ�ò���x
void SeqListInsert_val(SeqList* psl, ElemTepe x);// ˳�����������x
void SeqListReverse(SeqList* psl);  //��ת
int SeqListFind(SeqList * psl, ElemTepe x);//����
void SeqListDelete_val(SeqList* psl, ElemTepe x,int delselect); //ɾ��ָ��ֵ
void SeqListDelete_pos(SeqList* psl, int pos); //ɾ��ָ��λ�õ�ֵ
void SeqListSort(SeqList* psl);//��С����ð������
int CheckCapacity(SeqList* psl);// ���ռ䣬������ˣ���������
void SeqListRemove_all(SeqList* psl);
void SeqListDestroy(SeqList* psl);


#endif 
