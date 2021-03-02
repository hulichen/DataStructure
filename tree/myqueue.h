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


//队列作业
// 链式结构：表示队列
typedef int QDataType;
#define QUEUE_SIZE  6
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* q);
// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
// 队头出队列 
void QueuePop(Queue* q);
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列 
void QueueDestroy(Queue* q);
void QueueShow(Queue* q);





// 初始化队列 
void QueueInit(Queue* q) {
	assert(q);
	q->_rear = q->_front = NULL;

}

// 队尾入队列 
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

// 队头出队列 
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
// 获取队列头部元素 
QDataType QueueFront(Queue* q) {
	assert(q);
	if (q->_front != NULL) {
		return q->_front->_data;
	}
}
// 获取队列队尾元素 
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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q) {
	assert(q);
	if (q->_front == NULL) {
		return 1;
	}
	return 0;
}
// 销毁队列 
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