#ifndef __LIST_H__
#define __LIST_H__

#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
#define ElemType int

//无头单链表
typedef struct SListNode
{
	ElemType data; //数据域
	struct SListNode* next; //指针域
}SListNode;

typedef struct SList
{
	SListNode* head;  //成员封装
}SList;

void SListInit(SList* plist);
void SListPushBack(SList* plist, ElemType x);
void SListPushFront(SList* plist, ElemType x);
void SListPopBack(SList* plist);
void SListPopFront(SList* plist);
void SListShow(SList* plist);

int SListLength(SList* plist);
SListNode* SListFind(SList* plist, ElemType key);//找到了返回节点的地址   找不到不返回空
void SListClear(SList* plist);
void SListDestroy(SList* plist);

void SListDeleteByVal(SList* plist, ElemType key);//移除第一个key值
void SListInsertByVal(SList* plist, ElemType x);
void SListReverse(SList* plist);
void SListSort(SList* plist);
void SListRemoveAll(SList* plist, ElemType key);//移除所有的key值


SListNode* _Buynode()
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = 0;
	s->next = NULL;
	return s;
}

void SListInit(SList* plist)
{
	plist->head = NULL;
}

void SListPushBack(SList* plist, ElemType x)
{
	assert(plist);
	SListNode* s = _Buynode();
	s->data = x;

	//查找链表的尾部
	SListNode* p = plist->head;

	//插入的节点是第一个节点
	if (p == NULL)
		plist->head = s;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = s;
	}
}

void SListPushFront(SList* plist, ElemType x) {
	assert(plist);
	SListNode* s = _Buynode();
	s->data = x;

	s->next = plist->head;
	plist->head = s;
}

void SListPopBack(SList* plist) {
	assert(plist);	
	SListNode* p = plist->head;
	if (p != NULL) {//要删除的链表不能为空
		if (p->next == NULL) { //只有一个节点的情况
			p = NULL;
			free(p);
		}

		else {
			SListNode* pre = NULL;
			while (p->next != NULL) {
				pre = p;
				p = p->next;
			}
			pre->next = NULL;
			free(p);
		}
	}
}

void SListPopFront(SList* plist) {
	assert(plist);
	SListNode* p = plist->head;
	if (p != NULL) {
		plist->head = p->next;
		free(p);
	}
}

int SListLength(SList* plist) {
	assert(plist);
	SListNode* p = plist->head;
	
	int count = 1 ;
	while (p->next != NULL) {
		count++;
		p = p->next;
	}

	return count;
}

SListNode* SListFind(SList* plist, ElemType key) {
	assert(plist);
	SListNode* p = plist->head;
	while (p  != NULL  && p->data != key) {
		p = p->next;
	}
	return p;
}

void SListDeleteByVal(SList* plist, ElemType key) {
	assert(plist);
	SListNode* p = plist->head;
	SListNode* pre = NULL;
	while (p != NULL && p->data != key) {
		pre = p;
		p = p->next;
	}
	if (p == NULL) {
		return; //遍历完链表，没找到要删的值；
	}
	if (pre == NULL) {//要删除的是第一个节点；
		plist->head = p->next;
	}
	else {
		pre->next = p->next;	
	}
	free(p);
}

void SListInsertByVal(SList* plist, ElemType x) {
	assert(plist);
	SListNode* s = _Buynode();
	s->data = x;
	if (plist->head == NULL) {
		plist->head = s;
	}
	else {
		SListNode* p = plist->head;
		SListNode* pre = NULL;
		
		while (p != NULL  && x>p->data) {
			pre = p;
			p = p->next;
		}	
		if (pre == NULL) {//头部插入
			s->next = p;
			plist->head = s;	
		}
		else {//链表中间插入；			
			s->next = pre->next;
			pre->next = s;
			
		}
	}
}

void SListReverse(SList* plist) {
	assert(plist);
	if (plist->head == NULL) {
		return;
	}
	if (plist->head->next == NULL) {
		return;
	}
	else {
		SListNode* p = plist->head->next;
		plist->head->next = NULL;
		SListNode* q = p;
		while (q != NULL) { 
			q = q->next;
			p->next = plist->head;
			plist->head = p;
			p = q;
		}
	}
}
//
//void SListSort(SList* plist)
//{
//	assert(plist);
//	if (plist->head == NULL) {
//		return;
//	}
//	if (plist->head->next == NULL) {
//		return;
//	}
//	int A[1000] = { 0 };
//	SListNode* p = plist->head;
//	SListNode* q = plist->head;
//	int c = 0;
//	while (p != NULL) {
//		A[c] = p->data;
//		p = p->next;
//		c++;
//	} //c即为数组有用的元素个数
//	for (int i = 0; i < c-1 ; i++) { //冒泡排序
//		for (int j = 0; j < c -i-1 ; j++) {
//			if (A[j] > A[j + 1]) {
//				int tmp = A[j ];
//				A[j] = A[j+1];
//				A[j+1] = tmp;
//			}
//		}
//	}
//	int m = 0;
//	while (q != NULL) {
//		q->data = A[m];
//		q = q->next;
//		m++;
//	}
//}

void SListSort(SList* plist)
{
	assert(plist);
	SListNode* p, * q;
	if (plist->head == NULL || plist->head->next == NULL) {
		return;
	}
	p = plist->head->next;
	plist->head->next = NULL;

	q = p;
	while (p != NULL) {//断开节点
		q = q->next;
		SListNode* t = plist->head;
		SListNode* pre = NULL;
		while (t != NULL && p->data > t->data) {//寻找插入位置
			pre = t;
			t = t->next;
		}
		if (pre == NULL) //上边while条件均不符合则为最小值 前插
		{
			p->next = plist->head;
			plist->head = p;
		}
		else {
			p->next = t->next;
			t->next = p;
		}
		p = q;
	}
}

void SListRemoveAll(SList* plist, ElemType key) {
	assert(plist);
	SListNode*p ,*pre = NULL;
	if (plist->head == NULL) {
		return;
	}
	p = plist->head;
	while (p != NULL) {
		if (p->data == key) {
			if (pre == NULL) { //删头节点
				plist->head = p->next;
		/*		free(p);
				p = plist->head;*/
			}
			else {            //删中间节点
				pre->next = p->next;			
			}
			free(p);
		}
		else {
			pre =p;
		}
		if (pre == NULL) {  //删头节点的情况
			p = plist->head;
		}
		else    
		{
			p = pre->next;
		}
	}



	//while (p != NULL) {
	//	
	//	while (p->data != key) {
	//		pre = p;
	//		p = p->next;
	//	}
	//	if (pre == NULL) {  //头删
	//		plist->head = p->next;
	//		free(p);
	//		p = plist->head;
	//	}
	//	else { //中间删
	//		pre->next = p->next;
	//		free(p);
	//		p = pre->next;
	//	}
	//}


	//while(NULL != SListFind(plist,  key)) {		
	//	SListDeleteByVal(plist, key);
	//}
}

void SListClear(SList* plist) {//释放链表所有节点

	assert(plist);
	SListNode* p = plist->head;

	while (p != NULL) {
		plist->head = p->next;
		free(p);
		p = plist->head;	
	}
}
void SListDestroy(SList* plist) {//释放所有节点
	SListClear(plist);
}

void SListShow(SList* plist)
{
	SListNode* p = plist->head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}


#endif









