#ifndef __myTREE_H__
#define __myTREE_H__

#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#pragma warning(disable:4996)
#include "queue.h"

#define TreeElemType  char
typedef struct	BinTreeNode {
	TreeElemType data;
	struct	BinTreeNode* leftChild;
	struct	BinTreeNode* rightChild;

}BinTreeNode;

//定义树形结构
typedef BinTreeNode* BinTree;

void BinTreeInit(BinTree* t);
void BinTreeCreate_1(BinTree* t);
BinTree BinTreeCreate_2();
BinTree BinTreeCreate_3(const char* str, int* i);
BinTree BinTreeCreate_VLR_LVR(const char* vlr, const char* lvr, int n);
BinTree BinTreeCreate_LVR_LRV(const char* lvr, const char* lrv, int n);

//递归遍历
void PreOrder(BinTree t);
void InOrder(BinTree t);
void PostOrder(BinTree t);
void LevelOrder(BinTree t);

//非递归遍历
void PreOrder_Nor(BinTree t);
void InOrder_Nor(BinTree t);
void PostOrder_Nor(BinTree t);


size_t Size(BinTree t);
size_t Height(BinTree t);
BinTreeNode* Find(BinTree t, TreeElemType key);
BinTreeNode* Parent(BinTree t, BinTreeNode* s);

BinTree Clone(BinTree t);
bool    Equal(BinTree t1, BinTree t2);

void BinTreeInit(BinTree* t)
{
	*t = NULL;
}

void BinTreeCreate_1(BinTree* t) {
	TreeElemType item;
	scanf("%s", &item);
	if (item == '#') {
		*t = NULL;
	}
	else {
		(*t) = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		(*t)->data = item;
		BinTreeCreate_1(&(*t)->leftChild);
		BinTreeCreate_1(&(*t)->rightChild);
	}
}

BinTree BinTreeCreate_2() {
	
	TreeElemType item;
	scanf("%s", &item);
	if (item == '#') {
		return NULL;
	}
	else {
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t);
		t->data = item;
		t->leftChild = BinTreeCreate_2();
		t->rightChild = BinTreeCreate_2();
		return t;
	}

}

BinTree BinTreeCreate_3(const char* str, int* i) {
	if (str[*i] == '#') {
		(*i)++;
		return NULL;
	}
	if (str[*i] == '\0') {
		return NULL;
	}
	else {
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t);
		t->data = str[*i];
		(*i)++;
		t->leftChild = BinTreeCreate_3(str, i);
		t->rightChild = BinTreeCreate_3(str, i);
		return t;
	}

}




BinTree BinTreeCreate_VLR_LVR(const char* vlr, const char* lvr, int n) {
	if (n == 0) {
		return	NULL	;
	}
	int k = 0;
	while (vlr[0] != lvr[k]) {
		k++;
	}
	BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t);
	t->data = lvr[k];
	t->leftChild = BinTreeCreate_VLR_LVR( vlr+1, lvr, k);
	t->rightChild = BinTreeCreate_VLR_LVR( vlr+k+1, lvr+k+1, n-k-1);
	return t;
}


BinTree BinTreeCreate_LVR_LRV(const char* lvr, const char* lrv, int n) {
	if (n == 0) {
		return  NULL;
	}
	int i = 0;
	while (lrv[n-1] != lvr[i]) i++;
	BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t);
	t->data = lvr[i];
	t->rightChild = BinTreeCreate_LVR_LRV(lvr + i + 1, lrv+i, n-i-1);
	t->leftChild = BinTreeCreate_LVR_LRV(lvr, lrv,  i);
	
	return t;
}






void PreOrder(BinTree t) {
	if (t == NULL) {
		return ;
	}
	printf("%c", t->data);
	PreOrder(t->leftChild);
	PreOrder(t->rightChild);
}

void InOrder(BinTree t) {
	if (t == NULL) {
		return;
	}	
	InOrder(t->leftChild);
	printf("%c", t->data);
	InOrder(t->rightChild);
}
void PostOrder(BinTree t) {
	if (t == NULL) {
		return;
	}
	PostOrder(t->leftChild);
	PostOrder(t->rightChild);
	printf("%c", t->data);
}


#include"Queue.h"
void LevelOrder(BinTree t) {
	if (t != NULL) {
		LinkQueue pq;
		LinkQueueInit(&pq);
		LinkQueueEn(&pq, t);  //每次放进去的为树形节点  #define QueueElemType struct BinTreeNode*
		while (!LinkQueueEmpty(&pq)) {
			BinTreeNode* p = LinkQueueFront(&pq);
			printf("%c", p->data);
			LinkQueueDe(&pq);
			if (p->leftChild != NULL) {
				LinkQueueEn(&pq, p->leftChild);
			}
			if (p->rightChild != NULL) {
				LinkQueueEn(&pq, p->rightChild);
			}
		}
	}
}


size_t Size(BinTree t) {
	if (t == NULL) {
		return 0;
	}
	return (Size(t->leftChild) + Size(t->rightChild)) + 1;
}
size_t Height(BinTree t) {
	if (t == NULL) {
		return 0;
	}
	return (Height(t->leftChild) > Height(t->rightChild) ? Height(t->leftChild) : Height(t->rightChild)) + 1;
}
int flag = 0;
BinTreeNode* Find(BinTree t, TreeElemType key) {
	BinTreeNode* p;
	if (t == NULL || t->data == key) {
		return t;
	}
	p = Find(t->leftChild, key);
	if (p == NULL) {
		Find(t->rightChild, key);
	}	
}
BinTreeNode* Parent(BinTree t, BinTreeNode* s) {
	BinTreeNode* p;
	if (t==	NULL || s==t) {  //t==s是用于判断是否求的是根节点的父节点
		return NULL;
	}
	if (t->leftChild ==s || t->rightChild == s) {
		return t;
	}
	p = Parent(t->leftChild, s);
	if (p == NULL) {
		Parent(t->rightChild, s);
	}
}


BinTree Clone(BinTree t) {
	BinTreeNode* p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	p = t;
	if (t == NULL) {
		return;
	}
	p->data = t->data;
	p->leftChild=Clone(t->leftChild);
	p->rightChild=Clone(t->rightChild);
	return p;
}
bool    Equal(BinTree t1, BinTree t2) {
	if (t1 == NULL && t2 == NULL) {
		return true;
	}
	if (t1 == NULL || t2 == NULL) {
		return false;
	}
	return  Equal(t1->leftChild, t2->leftChild)
		&& Equal(t1->rightChild, t2->rightChild)
		&& (t1->data == t2->data);


}

//非递归遍历
#include "Stack.h"

//void PreOrder_Nor(BinTree t)
//{
//	if (t != NULL)
//	{
//		LinkStack st;
//		LinkStackInit(&st);
//
//		LinkStackPush(&st, t);
//		while (!LinkStackEmpty(&st))
//		{
//			BinTreeNode* p = LinkStackTop(&st);
//			LinkStackPop(&st);
//
//			printf("%c ", p->data);
//			if (p->rightChild != NULL)
//				LinkStackPush(&st, p->rightChild);
//			if (p->leftChild != NULL)
//				LinkStackPush(&st, p->leftChild);
//		}
//	}
//}


void PreOrder_Nor(BinTree t) {
	if (t != NULL) {
		LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
		LinkStackInit(p);
		LinkStackPush(p, t);
		while (!LinkStackEmpty(p)) {
			BinTreeNode* q = LinkStackTop(p);
			printf("%c", q->data);
			LinkStackPop(p);
			if (q->rightChild != NULL) {
				LinkStackPush(p, q->rightChild);
			}
			if (q->leftChild != NULL) {
				LinkStackPush(p, q->leftChild);
			}
		}
	}
}
void InOrder_Nor(BinTree t) {
	if (t != NULL) {
		LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
		LinkStackInit(p);
		LinkStackPush(p, t);
		while (!LinkStackEmpty(p)) {
			while (t != NULL && t->leftChild != NULL) {
				LinkStackPush(p, t->leftChild);
				t = t->leftChild;
			}
			BinTreeNode* q = LinkStackTop(p);
			printf("%c", q->data);
			LinkStackPop(p);
			
			t = q->rightChild;
			if(t!= NULL){
				LinkStackPush(p, t);
			}
		}
	}
}
void PostOrder_Nor(BinTree t) {
	if (t != NULL) {

		LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
		BinTreeNode* pre= (BinTreeNode*)malloc(sizeof(BinTreeNode));
		LinkStackInit(p);
		LinkStackPush(p, t);

		while (!LinkStackEmpty(p)) {
			while (t != NULL && t->leftChild != NULL) {
				LinkStackPush(p, t->leftChild);
				t = t->leftChild;
			}
			BinTreeNode* q = LinkStackTop(p);

			if (q->rightChild == NULL || q->rightChild == pre) { //q 右树为空或者右树已经访问过 则不进行入栈操作
				printf("%c", q->data);
				LinkStackPop(p);
				pre = q;
			}	
			else
			{
				t = q->rightChild;		 //t不空		
				LinkStackPush(p, t);

			}
		}
	}
}









//void BinTreeCreate_1(BinTree* t)//修改参数
//{
//	TreeElemType item;
//	scanf("%c", &item);
//	if (item == '#')
//		*t = NULL;
//	else
//	{
//		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		assert(*t != NULL);
//		(*t)->data = item;
//		BinTreeCreate_1(&((*t)->leftChild));
//		BinTreeCreate_1(&((*t)->rightChild));
//	}
//}
//
//BinTree BinTreeCreate_2() { //返回值接收节点
//	TreeElemType item;
//	scanf("%c", &item);
//	if (item == '#') {
//		return NULL;
//	}
//	else {
//		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		assert(t != NULL);
//		t->data = item;
//		t->leftChild =  BinTreeCreate_2();
//		t->rightChild =  BinTreeCreate_2();
//		return t;
//	}
//
//}
//
////abc##de##f##g#h##
//BinTree BinTreeCreate_3(const char* str,int *i) {
//	if (str[*i] == '#' || str[*i] == '\0') {
//		return NULL;
//	}
//	else {
//		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		assert(t != NULL);
//		t->data = str[*i];
//		(*i)++;
//		t->leftChild = BinTreeCreate_3(str,i);
//		(*i)++;
//		t->rightChild = BinTreeCreate_3(str,i);
//		(*i)++;
//		return t;
//	}
//}
//size_t Size(BinTree t) {
//	if (t == NULL) {
//		return 0;
//	}
//	else{
//		return	Size(t->leftChild) + Size(t->rightChild) + 1;
//	}
//
//
//}
//size_t Hight(BinTree t) {
//	if (t == NULL) {
//		return 0;
//	}
//	else {
//		int left_h = Hight(t->leftChild);
//		int right_h = Hight(t->rightChild);
//		return  left_h > right_h ? left_h+1 : right_h+1;
//	}
//}
//
//BinTreeNode* Find(BinTree t, TreeElemType key) {
//	if (t == NULL || t->data == key) {
//		return t;
//	}
//	else {
//		BinTreeNode* p = Find(t->leftChild, key);
//		if (p != NULL) {//左侧找不到  再到右侧找
//			return p;
//			return  Find(t->rightChild, key);
//		}
//	}
//}
//BinTreeNode* Parant(BinTree t, BinTreeNode* s) {
//	if (t == NULL|| t ==s) { // t == s判断是否为根节点的父节点
//		return NULL;
//	}
//	BinTreeNode* p = NULL;
//	if (t->leftChild == s || t->leftChild == s) {
//		return t;
//	}
//	p = Parant(t->leftChild, s);
//	if (p != NULL) {//左侧找到了
//		return p;
//	}
//	return Parant(t->rightChild, s);
//}
//
//
//
//BinTree  Clone(BinTree t) {
//
//}
//bool Equal(BinTree t1, BinTree t2) {
//	if (t1 == NULL &&t2 == NULL) {
//		return TRUE;
//	}
//	if (t1->data == t2->data ) {
//		return TRUE;
//	}
//	return (t1->data == t2->data
//		&& Equal(t1->leftChild, t2->leftChild)
//		&& (t1->rightChild, t2->rightChild));
//
//	//if (t1 == NULL &&t2 == NULL) {
//	//	return 1;
//	//}
//	//if (t1->data == t2->data ) {
//	//	return 1;
//	//}
//	//if (t1 ==NULL||t2 == NULL) {
//	//	return 0;
//	//}
//	//int a = Equal(t1->leftChild, t2->leftChild);
//	//if (a == 1) {
//	//	int b= Equal(t1->rightChild, t2->rightChild);
//	//	if (b == 1) {
//	//		return 1;
//	//	}
//	//	return 0;
//	//}
//}
//
//void PreOrder(BinTree t) //qianxu
//{
//	if (t != NULL)
//	{
//		printf("%c ", t->data);
//		PreOrder(t->leftChild);
//		PreOrder(t->rightChild);
//	}
//}
//void InOrder(BinTree t)//中序
//{
//	if (t != NULL)
//	{
//		InOrder(t->leftChild);
//		printf("%c ", t->data);
//		InOrder(t->rightChild);
//	}
//}
//void PostOrder(BinTree t)//后
//{
//	if (t != NULL)
//	{
//		PostOrder(t->leftChild);
//		PostOrder(t->rightChild);
//		printf("%c ", t->data);
//	}
//}

#endif