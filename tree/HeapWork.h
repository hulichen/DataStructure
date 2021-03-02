#ifndef __HEAPWORK_H__
#define __HEAPWORK_H__
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#pragma warning(disable:4996)



#define HPDataType int
//typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

// �ѵĹ���
void Heap_Create(Heap* hp, HPDataType* a, int n);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int Heap_Size(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);

void Show(Heap* php);
void _Adjustdowm(Heap* hp, int start);
void _Adjustup(Heap* php, int start);

// ��������ж�����
void HeapSort(int* a, int n);

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k);
void TestTopk();





void _Adjustup(Heap* php, int start)
{
	int j = start;  
	int i = (j - 1) / 2; //j�ĸ��ڵ�
	HPDataType tmp = php->_a[j];
	while (j > 0)
	{
		if (tmp < php->	_a[i])
		{
			php->_a[j] = php->_a[i];
			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
	php->_a[j] = tmp;
}
//void _Adjustup(Heap* php, int start) {
//	int j = start;
//	int i = (j - 1)/ 2;
//	while (j > 0) {
//		if (php->_a[j] < php->_a[i]) {
//			HPDataType tmp = php->_a[j];
//			php->_a[j] = php->_a[i];
//			php->_a[i] = tmp;
//			j = i;
//			i = (j - 1) / 2;;		
//		}
//		else {
//			break;
//		}
//	}
//
//}



void Show(Heap* php) {
	for (int i = 0; i < php->_size; i++) {
		printf("%d ", php->_a[i]);
	}
}
void HeapInit(Heap* php, int sz);
void HeapInit(Heap* php, int sz) {
	php->_a = (HPDataType*)malloc(sizeof(HPDataType)*sz);
	assert(php->_a);
	memset(php->_a, 0, sizeof(HPDataType)*sz);
	php->_size = 0;
	php->_capacity = sz;
}

// �ѵĹ���
void Heap_Create(Heap* hp, HPDataType* a, int n) {
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	assert(hp->_a);
	for (int i = 0; i < n; i++) {
		hp->_a[i] = a[i];
	}
	hp->_size = n;

	int cus = n / 2 - 1;
	while (cus >=0) {
		_Adjustdowm(hp, cus);
		cus--;
	}
}
// �ѵ�����
void HeapDestory(Heap* hp) {
	hp->_size = hp->_capacity = 0;
	free(hp->_a);
	hp->_a = NULL;
}
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x) {
	if (Heap_Size(hp) == hp->_capacity){//�ѿռ�����
		printf("�ѿռ�����\n");
		return;
	}
	
	hp->_a[hp->_size]=x;
	_Adjustup(hp,hp->_size);
	hp->_size++;
}


void _Adjustdowm(Heap* hp, int start) {
	int i = 0;
	int j = 2 * i + 1; //������
	while (j < hp->_size) {
		if (j < hp->_size - 1 && hp->_a[j]>hp->_a[j + 1]) {//j < hp->_size - 1   ����������
			j++;  //jΪ���������н�С���±�   
		}
		if (hp->_a[i] > hp->_a[j]) {
			HPDataType tmp = hp->_a[j];
			hp->_a[j] = hp->_a[i];
			hp->_a[i] = tmp;
			 i = j;
			 j = 2 * i + 1;
		}
		else {
			break;
		}
	}
}
// �ѵ�ɾ��
void HeapPop(Heap* hp) {
	if (hp->_size == 0) {
		return ;
	}
	hp->_size --;
	hp->_a[0] = hp->_a[hp->_size];
	_Adjustdowm(hp, 0);


}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp) {
	if (hp->_size == 0) {
		return NULL;
	}
	return hp->_a[0];
}
// �ѵ����ݸ���
int Heap_Size(Heap* hp) {
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp) {
	return hp->_size == 0;
}

// ��������ж�����
void HeapSort(int* a, int n) {

}

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k) {
	Heap hp;
	Heap_Create(&hp, a, n);
		for (int i = 0; i < k; i++) {
			int a = HeapTop(&hp);
			printf("%d ", a);
			HeapPop(&hp);			
		}
}
void TestTopk() {

}






#endif // !__HEAPWORK_H__