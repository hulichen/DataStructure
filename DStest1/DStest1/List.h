#ifndef __LIST_H__
#define __LIST_H__

#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
#define ElemType int

//��ͷ������
typedef struct SListNode
{
	ElemType data; //������
	struct SListNode* next; //ָ����
}SListNode;

typedef struct SList
{
	SListNode* head;  //��Ա��װ
}SList;

void SListInit(SList* plist);
void SListPushBack(SList* plist, ElemType x);
void SListPushFront(SList* plist, ElemType x);
void SListPopBack(SList* plist);
void SListPopFront(SList* plist);
void SListShow(SList* plist);

int SListLength(SList* plist);
SListNode* SListFind(SList* plist, ElemType key);//�ҵ��˷��ؽڵ�ĵ�ַ   �Ҳ��������ؿ�
void SListClear(SList* plist);
void SListDestroy(SList* plist);

void SListDeleteByVal(SList* plist, ElemType key);//�Ƴ���һ��keyֵ
void SListInsertByVal(SList* plist, ElemType x);
void SListReverse(SList* plist);
void SListSort(SList* plist);
void SListRemoveAll(SList* plist, ElemType key);//�Ƴ����е�keyֵ


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

	//���������β��
	SListNode* p = plist->head;

	//����Ľڵ��ǵ�һ���ڵ�
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
	if (p != NULL) {//Ҫɾ����������Ϊ��
		if (p->next == NULL) { //ֻ��һ���ڵ�����
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
		return; //����������û�ҵ�Ҫɾ��ֵ��
	}
	if (pre == NULL) {//Ҫɾ�����ǵ�һ���ڵ㣻
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
		if (pre == NULL) {//ͷ������
			s->next = p;
			plist->head = s;	
		}
		else {//�����м���룻			
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
//	} //c��Ϊ�������õ�Ԫ�ظ���
//	for (int i = 0; i < c-1 ; i++) { //ð������
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
	while (p != NULL) {//�Ͽ��ڵ�
		q = q->next;
		SListNode* t = plist->head;
		SListNode* pre = NULL;
		while (t != NULL && p->data > t->data) {//Ѱ�Ҳ���λ��
			pre = t;
			t = t->next;
		}
		if (pre == NULL) //�ϱ�while��������������Ϊ��Сֵ ǰ��
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
			if (pre == NULL) { //ɾͷ�ڵ�
				plist->head = p->next;
		/*		free(p);
				p = plist->head;*/
			}
			else {            //ɾ�м�ڵ�
				pre->next = p->next;			
			}
			free(p);
		}
		else {
			pre =p;
		}
		if (pre == NULL) {  //ɾͷ�ڵ�����
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
	//	if (pre == NULL) {  //ͷɾ
	//		plist->head = p->next;
	//		free(p);
	//		p = plist->head;
	//	}
	//	else { //�м�ɾ
	//		pre->next = p->next;
	//		free(p);
	//		p = pre->next;
	//	}
	//}


	//while(NULL != SListFind(plist,  key)) {		
	//	SListDeleteByVal(plist, key);
	//}
}

void SListClear(SList* plist) {//�ͷ��������нڵ�

	assert(plist);
	SListNode* p = plist->head;

	while (p != NULL) {
		plist->head = p->next;
		free(p);
		p = plist->head;	
	}
}
void SListDestroy(SList* plist) {//�ͷ����нڵ�
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









