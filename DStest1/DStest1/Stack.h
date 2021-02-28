#ifndef _STACK_H_
#define _STACK_H_

#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

struct BinTreeNode;
#define StackElemType struct BinTreeNode*

#define SEQSTACK_DEFAULT_SIZE 8

//˳��ջ
typedef struct SeqStack
{
	StackElemType* base; //
	size_t         capacity;
	int            top;
}SeqStack;


void SeqStackInit(SeqStack* pst, int sz);
void SeqStackDestroy(SeqStack* pst);
void SeqStackPush(SeqStack* pst, StackElemType x);
void SeqStackPop(SeqStack* pst);
StackElemType SeqStackTop(SeqStack* pst);
void SeqStackShow(SeqStack* pst);

bool IsFull(SeqStack* pst)
{
	return pst->top >= pst->capacity;
}
bool IsEmpty(SeqStack* pst)
{
	return pst->top == 0;
}

void SeqStackInit(SeqStack* pst, int sz)
{
	assert(pst);
	pst->capacity = sz > SEQSTACK_DEFAULT_SIZE ? sz : SEQSTACK_DEFAULT_SIZE;
	pst->base = (StackElemType*)malloc(sizeof(StackElemType) * pst->capacity);
	assert(pst->base != NULL);
	pst->top = 0;
}

void SeqStackPush(SeqStack* pst, StackElemType x)
{
	assert(pst);
	if (IsFull(pst))
	{
		printf("ջ�ռ�������%d������ջ\n", x);
		return;
	}
	pst->base[pst->top++] = x;
}

void SeqStackPop(SeqStack* pst)
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("ջ�ѿգ����ܳ�ջ.\n");
		return;
	}
	pst->top--;
}

StackElemType SeqStackTop(SeqStack* pst)
{
	assert(pst && !IsEmpty(pst));
	return pst->base[pst->top - 1];
}

void SeqStackShow(SeqStack* pst)
{
	assert(pst);
	for (int i = pst->top - 1; i >= 0; --i)
		printf("%d\n", pst->base[i]);
}

void SeqStackDestroy(SeqStack* pst)
{
	assert(pst);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}

///////////////////////////////////////////////////////////
//��ջ
typedef struct LinkStackNode
{
	StackElemType data;
	struct LinkStackNode* next;
}LinkStackNode;
typedef struct LinkStack
{
	LinkStackNode* head;
}LinkStack;

void LinkStackInit(LinkStack* pst);
void LinkStackDestroy(LinkStack* pst);
void LinkStackPush(LinkStack* pst, StackElemType x);
void LinkStackPop(LinkStack* pst);
StackElemType LinkStackTop(LinkStack* pst);
void LinkStackShow(LinkStack* pst);
bool LinkStackEmpty(LinkStack* pst)
{
	return pst->head == NULL;
}

void LinkStackInit(LinkStack* pst)
{
	assert(pst);
	pst->head = NULL;
}

void LinkStackPush(LinkStack* pst, StackElemType x)
{
	assert(pst);
	LinkStackNode* s = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(s != NULL);
	s->data = x;

	s->next = pst->head;
	pst->head = s;
}

void LinkStackPop(LinkStack* pst)
{
	assert(pst);
	if (pst->head != NULL)
	{
		LinkStackNode* p = pst->head;
		pst->head = p->next;
		free(p);
	}
}

StackElemType LinkStackTop(LinkStack* pst)
{
	assert(pst && pst->head != NULL);
	return pst->head->data;
}

void LinkStackShow(LinkStack* pst)
{
	assert(pst);
	LinkStackNode* p = pst->head;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

void LinkStackDestroy(LinkStack* pst)
{
	assert(pst);
	while (pst->head != NULL)
	{
		LinkStackNode* p = pst->head;
		pst->head = p->next;
		free(p);
	}
}

#endif /* _STACK_H_ */












//#ifndef __STACK_H__
//#define __STACK_H__
//
//#include<string.h>
//#include<assert.h>
//#include<stdlib.h>
//#include<stdio.h>
//#include<windows.h>
//#pragma warning(disable:4996)
////
////#define		StackElemTepe  int
////
////#define		SEQSTACK_SIZE   8
//   
//
////
////// ֧�ֶ�̬������ջ
////
////typedef struct SeqStack
////{
////	StackElemTepe* base; //ջָ��
////	int top; // ջ��
////	int capacity; // ����
////} SeqStack;
////// ��ʼ��ջ
////void StackInit(SeqStack* pst , int sz);
//////// ��ջ
//////void StackPush(SeqStack* ps, StackElemTepe  data);
//////// ��ջ
//////void StackPop(SeqStack* ps);
//////// ��ȡջ��Ԫ��
//////StackElemTepe  StackTop(SeqStack* ps);
//////// ��ȡջ����ЧԪ�ظ���
//////int StackSize(Stack* ps);
//////// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
//////int StackEmpty(SeqStack* ps);
//////// ����ջ
//////void StackDestroy(SeqStack* ps);
////
////
////
////
////void StackInit(SeqStack* pst, int sz) {
////	pst->capacity = sz > SEQSTACK_SIZE ? sz : SEQSTACK_SIZE;
////	pst->base = (StackElemTepe*)malloc(sizeof(StackElemTepe) * pst->capacity);
////	assert(pst->base!=NULL);
////	pst->top = 0;
////}
////
////bool  IsFull(SeqStack* pst) {
////
////
////
////}
//
//
//
//////ջ��ҵ
////typedef int STDataType;
////#define STACKSIZE 6
////typedef struct Stack
////{
////	STDataType* _a;
////	int _top;		// ջ��
////	int _capacity;  // ���� 
////}Stack;
////// ��ʼ��ջ 
////void StackInit(Stack* ps);
////// ��ջ 
////void StackPush(Stack* ps, STDataType data);
////// ��ջ 
////void StackPop(Stack* ps);
////// ��ȡջ��Ԫ�� 
////STDataType StackTop(Stack* ps);
////// ��ȡջ����ЧԪ�ظ��� 
////int StackSize(Stack* ps);
////// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
////int StackEmpty(Stack* ps);
////// ����ջ 
////void StackDestroy(Stack* ps);
////void StackShow(Stack* ps);//��ʾ
////
////int StackEmpty(Stack* ps) {
////	assert(ps);
////	if (ps->_top ==0) {
////		return 1;
////	}
////	return 0;
////}
////void StackInit(Stack* ps) {
////	ps->_capacity = STACKSIZE;
////	ps->_a = (STDataType*)malloc(sizeof(STDataType) * ps->_capacity);
////	assert (ps->_a != NULL);
////	ps->_top = 0;
////}
////void StackShow(Stack* ps) {
////	assert(ps);
////	for (int i = ps->_top - 1; i >= 0; i--) {
////		printf("%d \n", ps->_a[i]);
////	}
////}
////
////void  StackPush(Stack* ps, STDataType data) {
////	assert(ps);
////	if (ps->_top >= ps->_capacity) {
////		printf("ջ������\n");
////		return;
////	}
////	ps->_a[ps->_top++] = data;
////}
////void StackDestroy(Stack* ps) {
////	assert(ps);
////	free(ps->_a);
////	ps->_a = NULL;
////	ps->_capacity = ps->_top = 0;
////}
////int StackSize(Stack* ps) {
////	assert(ps);
////	return ps->_top;
////}
////
////void StackPop(Stack* ps) {
////	assert(ps);
////	if (0==StackEmpty(ps)) {
////		ps->_top--;
////	}
////}
////STDataType StackTop(Stack* ps) {
////	assert(ps);
////	if (0==StackEmpty(ps)) {
////		printf("%d \n", ps->_a[ps->_top - 1]);
////	}
////}
////int main()
////{
////	STDataType item, key;
////	Stack mystack;
////	StackInit(&mystack);
////	int select = 1;
////	while (select)
////	{
////		printf("********************************************\n");
////		printf("* [1]��ջ               [2] ��ջ     *\n");
////		printf("* [3]��ǰԪ�� ����      [4] showt      *\n");
////		printf("* [5]ջ��Ԫ��           [6] ����    *\n");
////		printf("********************************************\n");
////		printf("��ѡ��:>");
////		scanf("%d", &select);
////		switch (select)
////		{
////		case 1:
////			printf("������Ҫ���������(��-1����):>");
////			while (scanf("%d", &item), item != -1)
////				StackPush(&mystack, item);
////			break;
////		case 2:
////			StackPop(&mystack);
////			break;
////		case 3:
////			printf("ջ��Ԫ�ظ���Ϊ%d \n", StackSize(&mystack));
////			break;
////		case 4:
////			StackShow(&mystack);
////			break;
////		case 5:
////			StackTop(&mystack);
////			break;
////		case 6:
////			StackDestroy(&mystack);
////			break;
////		default:
////			break;
////		}
////		system("pause");
////		StackShow(&mystack);
////	}
////	return 0;
////}
//
//
////������ҵ
//// ��ʽ�ṹ����ʾ����
//typedef int QDataType;
//#define QUEUE_SIZE  6
//typedef struct QListNode
//{
//	struct QListNode* _next;
//	QDataType _data;
//}QNode;
//
//// ���еĽṹ 
//typedef struct Queue
//{
//	QNode* _front;
//	QNode* _rear;
//}Queue;
//
//// ��ʼ������ 
//void QueueInit(Queue* q);
//// ��β����� 
//void QueuePush(Queue* q, QDataType data);
//// ��ͷ������ 
//void QueuePop(Queue* q);
//// ��ȡ����ͷ��Ԫ�� 
//QDataType QueueFront(Queue* q);
//// ��ȡ���ж�βԪ�� 
//QDataType QueueBack(Queue* q);
//// ��ȡ��������ЧԪ�ظ��� 
//int QueueSize(Queue* q);
//// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
//int QueueEmpty(Queue* q);
//// ���ٶ��� 
//void QueueDestroy(Queue* q);
//void QueueShow(Queue* q);
//
//
//
//
//
//// ��ʼ������ 
//void QueueInit(Queue* q) {
//	assert(q);
//	q->_front = (QDataType*)malloc(sizeof(QDataType) * QUEUE_SIZE);
//	assert(q->_front);
//	q->_front->_data  = NULL;
//	q->_rear = q->_front;
//}
//
//// ��β����� 
//void QueuePush(Queue* q, QDataType data) {
//	assert(q);
//	QNode* p = q->_front;
//	while (p->_next != NULL) {
//		p->_data = data;
//		p = p->_next;
//	}
//}
//
//void QueueShow(Queue* q) {
//	assert(q);
//	QNode* p = q->_front;
//	while (p->_next != NULL) {
//		printf("%d   \n", p->_data);
//		p = p->_next;
//	}
//	printf("\n");
//}
//
//// ��ͷ������ 
//void QueuePop(Queue* q);
//// ��ȡ����ͷ��Ԫ�� 
//QDataType QueueFront(Queue* q);
//// ��ȡ���ж�βԪ�� 
//QDataType QueueBack(Queue* q);
//// ��ȡ��������ЧԪ�ظ��� 
//int QueueSize(Queue* q);
//// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
//int QueueEmpty(Queue* q);
//// ���ٶ��� 
//void QueueDestroy(Queue* q);
//
//
//
//
//
//#endif