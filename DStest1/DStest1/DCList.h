#ifndef __DCLIST_H__
#define __DCLIST_H__

#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

#define ElemTepe  int

typedef struct DCListNode
{
	ElemTepe  data;
	struct DCListNode* next;
	struct DCListNode* pre;
}DCListNode;
typedef struct DCList
{
	DCListNode* first;
	DCListNode* last;
	size_t size;
}DCList;




DCListNode* _BuyDCLNode(ElemTepe x) {
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->next = s->pre = NULL;
	s->data = x;
	return s;
}

void DCSListInit(DCList* plist);
void DCListShow(DCList* plist);
void DCListPushBack(DCList* plist, ElemTepe x);
void DCListPushFront(DCList * plist, ElemTepe x);
void DCListPopBack(DCList * plist);
void DCListPopFront(DCList* plist);
void DCListClear(DCList* plist);
void DCListDestroy(DCList* plist);
void DCListReverse(DCList* plist);
void DCListDeleteByVal(DCList* plist, ElemTepe x);
DCListNode*  DCListFind(DCList* plist, ElemTepe x);
void DCListInsertByVal(DCList* plist, ElemTepe x);

void DCListReverse(DCList* plist) {
	assert(plist);
	DCListNode* p = plist->first->next;
	DCListNode* q ;
	if (plist->size <= 1) {
		return;
	}
	//将第一个节点与后面的节点断开
	q = p->next;
	p->next = plist->first;
	plist->first->pre = p;
	plist->last = p;
	
	while (q != plist->first) {//逐个去除后面的节点进行push_front
		p = q;
		q = q->next;
		p->next = plist->first->next;
		plist->first->next = p;
		p->pre = plist->first;
		p->next->pre = p;		
	}
}

void DCListPopBack(DCList* plist) {
	assert(plist);
	if (plist->first == plist->last) {
		printf("数据为空无法删除!\n");
	}
	DCListNode* p = plist->last;
	plist->last = p->pre;
	p->pre->next = p->next;
	p->next->pre = p->pre;
	free(p);
	plist->size--;
}

void DCListPopFront(DCList* plist)
{
	assert(plist);
	if (plist->first == plist->last) {
		printf("数据为空无法删除!\n");
	}
	DCListNode* p = plist->first->next;

	plist->first->next = p->next;
	p->next->pre = plist->first;
	if (p == plist->last) {//只有一个节点
		plist->last = plist->first;
	}
	free(p);
	plist->size--;
}

void DCListClear(DCList* plist) {
	assert(plist);
	DCListNode* p = plist->first->next;
	DCListNode* pre;
	while (p == plist->first) {
		pre = p;
		p = p->next;	
		free(pre);
	}
	plist->last = plist->first;
	plist->first->pre = plist->first->next = plist->first;
	plist->size = 0;
}

void DCListDestroy(DCList* plist) {
	DCListClear(plist);
	free(plist->first);
}


void DCSListInit(DCList* plist) {
	assert(plist);
	DCListNode* p = _BuyDCLNode(0);
	plist->first = plist->last = p;
	plist->first->next = plist->first->pre = p;
	plist->size = 0;
}

void DCListShow(DCList* plist) {
	DCListNode* p = plist->first->next;	
	while (p != plist->first) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("over \n");
}

void DCListPushBack(DCList* plist, ElemTepe x) {
	assert(plist);
	DCListNode* s = _BuyDCLNode(x);
	DCListNode* p = plist->last;
	s->pre = p;
	p->next = s;
	plist->last = s;
	s->next = plist->first;
	plist->first->pre = plist->last;
	plist->size++;
}

void DCListPushFront(DCList* plist, ElemTepe x) {
	assert(plist);
	DCListNode* s = _BuyDCLNode(x);
	DCListNode* p = plist->first;
	s->next = p->next;
	s->pre = p;
	s->pre->next = s;
	s->next->pre = s;
	plist->size++;
	if (plist->first == plist->last) {
		plist->last = s;
	}
}

DCListNode* DCListFind(DCList* plist, ElemTepe key) {
	assert(plist);
	DCListNode* p = plist->first->next;
	while ((plist->first != p)  &&  p->data != key) {
		p = p->next;
	}
	if (p == plist->first) {
		return NULL;
	}
	return p;
}

void DCListDeleteByVal(DCList* plist, ElemTepe key)
{
	assert(plist);
	DCListNode* s = DCListFind(plist, key);
	if (s == NULL) {
		printf("要删的值不存在");
		return;
	}
	if (s == plist->last) {
		plist->last = s->pre;
	}
	s->pre->next = s->next;
	s->next->pre = s->pre;
	free(s);
	plist->size--;
}

void DCListInsertByVal(DCList* plist, ElemTepe key) {
	assert(plist);
	DCListNode* s = _BuyDCLNode(key);
	DCListNode* p = plist->first->next;
	while ((plist->first != p) && p->data < key) {
		p = p->next;
	}

	p->pre->next = s;
	s->pre = p->pre;
	s->next = p;
	p->pre = s;
	if (p == plist->first) { //尾插
		plist->last = plist->first->pre;
	}
	plist->size++;
}

#endif // !__DCLIST_H__


////// 带头+双向+循环链表增删查改实现
//typedef int LTDataType;
//typedef struct ListNode
//{
//	LTDataType _data;
//	struct ListNode* _next;
//	struct ListNode* _prev;
//}ListNode;
//
//// 创建返回链表的头结点.
//ListNode* ListCreate();
//// 双向链表销毁
//void ListDestory(ListNode* pHead);
//// 双向链表打印
//void ListPrint(ListNode* pHead);
//// 双向链表尾插
//void ListPushBack(ListNode* pHead, LTDataType x);
//// 双向链表尾删
//void ListPopBack(ListNode* pHead);
//// 双向链表头插
//void ListPushFront(ListNode* pHead, LTDataType x);
//// 双向链表头删
//void ListPopFront(ListNode* pHead);
//// 双向链表查找
//ListNode* ListFind(ListNode* pHead, LTDataType x);
//// 双向链表在pos的前面进行插入
//void ListInsert(ListNode* pos, LTDataType x);
//// 双向链表删除pos位置的节点
//void ListErase(ListNode* pos);
