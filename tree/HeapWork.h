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

// 堆的构建
void Heap_Create(Heap* hp, HPDataType* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int Heap_Size(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);

void Show(Heap* php);
void _Adjustdowm(Heap* hp, int start);
void _Adjustup(Heap* php, int start);

// 对数组进行堆排序
void HeapSort(int* a, int n);

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k);
void TestTopk();





void _Adjustup(Heap* php, int start)
{
	int j = start;  
	int i = (j - 1) / 2; //j的父节点
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

// 堆的构建
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
// 堆的销毁
void HeapDestory(Heap* hp) {
	hp->_size = hp->_capacity = 0;
	free(hp->_a);
	hp->_a = NULL;
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x) {
	if (Heap_Size(hp) == hp->_capacity){//堆空间已满
		printf("堆空间已满\n");
		return;
	}
	
	hp->_a[hp->_size]=x;
	_Adjustup(hp,hp->_size);
	hp->_size++;
}


void _Adjustdowm(Heap* hp, int start) {
	int i = 0;
	int j = 2 * i + 1; //左子树
	while (j < hp->_size) {
		if (j < hp->_size - 1 && hp->_a[j]>hp->_a[j + 1]) {//j < hp->_size - 1   则右树存在
			j++;  //j为左右子树中较小的下标   
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
// 堆的删除
void HeapPop(Heap* hp) {
	if (hp->_size == 0) {
		return ;
	}
	hp->_size --;
	hp->_a[0] = hp->_a[hp->_size];
	_Adjustdowm(hp, 0);


}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp) {
	if (hp->_size == 0) {
		return NULL;
	}
	return hp->_a[0];
}
// 堆的数据个数
int Heap_Size(Heap* hp) {
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp) {
	return hp->_size == 0;
}

// 对数组进行堆排序
void HeapSort(int* a, int n) {

}

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
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