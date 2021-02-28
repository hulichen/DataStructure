#ifndef __STACK_H__
#define __STACK_H__

#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

////�������ѭ������ҵ
////MyCircularQueue(k): �����������ö��г���Ϊ k ��
////Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
////Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
////enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
////deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
////isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
////isFull() : ���ѭ�������Ƿ�������
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
