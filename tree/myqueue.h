#ifndef __QUEUE_H__
#define __QUEUE_H__

#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#pragma warning(disable:4996)
//


//������ҵ
// ��ʽ�ṹ����ʾ����
typedef int QDataType;
#define QUEUE_SIZE  6
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);
// ��β����� 
void QueuePush(Queue* q, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ��� 
void QueueDestroy(Queue* q);
void QueueShow(Queue* q);





// ��ʼ������ 
void QueueInit(Queue* q) {
	assert(q);
	q->_rear = q->_front = NULL;

}

// ��β����� 
void QueuePush(Queue* q, QDataType data) {
	assert(q);
	QNode* s = (QNode*)malloc(sizeof(QNode));
	assert(s);
	s->_next = NULL;
	s->_data = data;
	if (q->_front == NULL) {
		q->_front = q->_rear = s;
	}
	else {
		q->_rear->_next = s;
		q->_rear = s;
	}
}

void QueueShow(Queue* q) {
	assert(q);
	QNode* p = q->_front;
	while (p != NULL) {
		printf("%d   \n", p->_data);
		p = p->_next;
	}
	printf("\n");
}

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front != NULL) {
		QNode* p = q->_front;
		q->_front = p->_next;
		if (q->_front == NULL) {
			q->_rear = NULL;
		}
		free(p);
	}
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q) {
	assert(q);
	if (q->_front != NULL) {
		return q->_front->_data;
	}
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q) {
	assert(q && q->_rear);
	return q->_rear->_data;
}
int QueueSize(Queue* q) {
	assert(q);
	assert(q->_front);
	QNode* p = q->_front;
	int c = 0;
	while (p != NULL) {
		p = p->_next;
		c++;
	}
	return c;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q) {
	assert(q);
	if (q->_front == NULL) {
		return 1;
	}
	return 0;
}
// ���ٶ��� 
void QueueDestroy(Queue* q) {
	assert(q);

	while (q->_front != NULL) {
		QNode* p = q->_front;
		q->_front = p->_next;
		free(p);
	}
	q->_front = q->_rear = NULL;
}





#endif