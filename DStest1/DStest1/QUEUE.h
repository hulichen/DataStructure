#ifndef __STACK_H__
#define __STACK_H__

#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

////力扣设计循队列作业
////MyCircularQueue(k): 构造器，设置队列长度为 k 。
////Front: 从队首获取元素。如果队列为空，返回 - 1 。
////Rear : 获取队尾元素。如果队列为空，返回 - 1 。
////enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
////deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
////isEmpty() : 检查循环队列是否为空。
////isFull() : 检查循环队列是否已满。
//
//typedef struct {
//	int *base;
//	size_t         capacity;
//	int            front;
//	int            rear;
//} MyCircularQueue;
//
//MyCircularQueue* myCircularQueueCreate(int k);
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
//bool myCircularQueueDeQueue(MyCircularQueue* obj);
//int myCircularQueueFront(MyCircularQueue* obj);
//int myCircularQueueRear(MyCircularQueue* obj);
//bool myCircularQueueIsEmpty(MyCircularQueue* obj);
//bool myCircularQueueIsFull(MyCircularQueue* obj);
//void myCircularQueueFree(MyCircularQueue* obj);
//
//
//
//
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//	if (k <= 0) {
//		return NULL;
//	}
//	MyCircularQueue* p = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	if (p != NULL) {
//		p->base = (int*)malloc(sizeof(int) * (k + 1));
//		p->capacity = k+1;
//		p->front = p->rear = 0;
//	}
//	return p;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//	if (myCircularQueueIsFull(obj)) {
//		return false;
//	}
//	obj->base[obj->rear] = value;
//	obj->rear = (obj->rear + 1) % obj->capacity;
//	return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//	if (myCircularQueueIsEmpty(obj)) {
//		return false;
//	}
//	obj->front = (obj->front + 1) % obj->capacity;
//	return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//	if (!myCircularQueueIsEmpty(obj)) {
//		return obj->base[obj->front%obj->capacity];
//	}
//	return -1;
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {	
//	if (!myCircularQueueIsEmpty(obj)) {
//			return obj->base[(obj->rear - 1+obj->capacity)%obj->capacity];
//		}
//	return -1;
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//	if (obj->rear == obj->front) {
//		return true;
//	}
//	return false;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//	if ((obj->rear + 1 )% obj->capacity == obj->front) {
//		return true;
//	}
//	return false;
//}
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//	free(obj->base);
//	obj->base = NULL;
//	free(obj);
//	obj = NULL;
//}


#endif
