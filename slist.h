#ifndef  __SLIST_H__
#define  __SLIST_H__

#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#pragma warning(disable:4996)

// slist.h
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;



void SListInit(SListNode* plist);


// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);

// 单链表打印
void SListPrint(SListNode* plist);
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表头删
void SListPopFront(SListNode** pplist);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);
// 单链表的销毁

//void SListDestory(SList* plist);

void SListInit(SListNode**plist) {
	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
	p->data = NULL;
	(*plist) = p;
	(*plist)->next = NULL;
}
SListNode* BuySListNode(SLTDateType x) {
	SListNode* p = (SListNode*)malloc(sizeof(SListNode));
	assert(p);
	p->data = x;
	p->next = NULL;
	return p;
}

void SListPrint(SListNode*plist)
{
	SListNode* p = plist;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->next;
	}
}
//单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x) {
	SListNode* p = BuySListNode(x);
	SListNode* q = *pplist;
	if ((*pplist)->data == NULL) {
		(*pplist) = p;
	}	
	else{
	while (q->next != NULL)
		q = q->next;
	}
	q->next = p;

}


void SListPushFront(SListNode** pplist, SLTDateType x) {
	SListNode* p = BuySListNode(x);
	if ((*pplist)->data != NULL) {	
		p->next = *pplist;	
	}
	*pplist = p;
}


// 单链表的尾删
void SListPopBack(SListNode** pplist) {
	if ((*pplist) == NULL) {
		return;
	}
	if ((*pplist)->next == NULL) {
		(*pplist)= NULL;
	}
	else {
		SListNode* q = *pplist;
		SListNode* pre = q;
		while (q->next != NULL) {
			pre = q;
			q = q->next;
		}
		pre->next = NULL;
		free(q);
	}
}
// 单链表头删
void SListPopFront(SListNode** pplist) {
	if ((*pplist) == NULL) {
		return;
	}
	if ((*pplist)->next == NULL) {
		(*pplist) = NULL;
	}
	else {
		SListNode* p = *pplist;
		SListNode* q = (*pplist)->next;
		(*pplist) = q;
		free(p);	
	}
}


// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x) {
	assert(plist);
	SListNode* p = plist;
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}



// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x) {
	assert(pos);
	SListNode* p = BuySListNode(x);
	SListNode* q = pos->next;
	pos->next = p;
	p->next = q;
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos) {
	assert(pos);
	SListNode* p = pos->next;
	pos->next = p->next;
	free(p);
}
// 单链表的销毁

void SListDestory(SListNode** plist) {
	assert(plist);
	SListNode* q;
	while (*plist != NULL) {
		q = *plist;
		(*plist) = (*plist)->next;
		free(q);
	}
}



#endif