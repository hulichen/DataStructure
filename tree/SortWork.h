#ifndef  __SORTWORK_H__
#define __SORTWORK_H__
#include "Queue.h"


// 插入排序
void InsertSort(int* a, int n);

// 希尔排序
void ShellSort(int* a, int n);

// 选择排序
void SelectSort(int* a, int n);

// 堆排序
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// 冒泡排序
void BubbleSort(int* a, int n);

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right);
int _Partion(int* a, int left, int right);
// 快速排序挖坑法
int PartSort2(int* a, int left, int right);
// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
//
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);

// 归并排序递归实现
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);
// 计数排序
void CountSort(int* a, int n);
void PrintArray(int* ar,int n);
int GetMinIndex(int* ar, int left, int right);
void Swap_int(int* a, int* b);

void InsertSort(int* a, int n) {
	for (int i = 1; i < n; i++) {
		int tmp = a[i];
		int j = i;
		while(j > 0 && tmp < a[j - 1]) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = tmp;	
	}
}

void PrintArray(int* ar, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d  ", ar[i]);
	}
	printf("\n");
}

void ShellSort(int* a, int n) {
	int gap = n ;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++) {
				int tmp = a[i];
				int j = i;
				while (j > 0 && tmp < a[j - gap]) {
					a[j] = a[j - gap];
					j = j - gap;
				}
				a[j] = tmp;
		}
	}
}

int GetMinIndex(int* a, int left, int right) {
	int min = a[left];
	int index = left;
	for (int i = left; i < right; i++) {
		if (a[i] < min) {
			min = a[i];
			index = i;
		}	
	}
	return index;
}
void Swap_int(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

	//*a = (*a) ^ (*b);
	//*b = (*a) ^ (*b);
	//*a = (*a) ^ (*b);
}
void SelectSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int index = GetMinIndex(a, i, n);
		if(i!= index)
		Swap_int(&a[i], &a[index]);
	}
}



void AdjustDwon(int* a, int n, int root) {  // 大堆向下调整
	int i = root;
	int j = 2 * i + 1;
	int tmp = a[i];
	while (j < n) {
		if (j+1< n && a[j] < a[j + 1]) {
			j += 1;
		}
		if (tmp < a[j]) {
			a[i] = a[j];
			i = j;
			j = 2 * i + 1;
		}
		else {
			break;
		}
	}
	a[i] = tmp;
}
void HeapSort(int* a, int n) {//升序  大堆向下调整
	int i = 0;
	int j = n / 2 -1;
	while (j >= 0) {
		AdjustDwon(a, n, j);
		j--;
	}
	int end = n - 1;
	while (end > 0) {	
		Swap_int(&a[end], &a[0]);
		AdjustDwon(a, end, 0);
		end--;
	}
}

void BubbleSort(int* a, int n) {
	//for (int i = 0; i < n - 1; i++) {
	//	for (int j = 0; j < n - 1 - i; j++) {
	//		if (a[j] < a[j + 1]) {
	//			Swap_int(&a[j], &a[j + 1]);
	//		}
	//	}
	//}
	int flag = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				Swap_int(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
		else {
			flag = 0;
		}
	}
}

int PartSort1(int* a, int left, int right){
	int low = left;
	int hight = right - 1;
	int key = a[low];
	while (low < hight) {
		while (low < hight && key < a[hight])
			hight--;
		Swap_int(&a[low], &a[hight]);
		while (low < hight && key >= a[low])
			low++;
		Swap_int(&a[low], &a[hight]);
	}
	return low;

}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right){
	int low = left;
	int hight = right - 1;
	int key = a[low];
	while (low < hight) {
		while (low < hight && key < a[hight])
			hight--;
		a[low] = a[hight];
		while (low < hight && key >= a[low])
			low++;
		a[hight] = a[low];
	}
	a[low] = key;
	return low;

}
// 快速排序前后指针法

int PartSort3(int* a, int left, int right) {
	int pos = left;
	int i = pos + 1;
	int key = a[left];
	while (i < right) {
		if (a[i] < key) {
			pos++;
			if (i != pos)
				Swap_int(&a[i], &a[pos]);
		}				
		i++;
	}
	Swap_int(&a[pos], &a[left]);
	return pos;
}

void QuickSort(int* a, int left, int right) {
	if (left >= right)
		return;
	int pos = PartSort3(a, left, right);
	QuickSort(a, left, pos);
	QuickSort(a, pos + 1, right);
}



// 归并排序递归实现
void _MergeSort(int* ar, int left, int right, int* tmp);
void _MergeSort(int* ar, int left, int right, int* tmp) {
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(ar, left, mid, tmp); // 分解左边分支
	_MergeSort(ar, mid + 1, right, tmp); //分解右边分支

	//开始归并
	int begin1, end1, begin2, end2;
	begin1 = left, end1 = mid;
	begin2 = mid + 1, end2 = right;

	int k = left;
	while (begin1 <= end1 && begin2 <= end2) {
		if (ar[begin1] < ar[begin2]) {
			tmp[k++] = ar[begin1++];
		}
		else{
			tmp[k++] = ar[begin2++];
		}
	 }
	while (begin1 <= end1)
		tmp[k++] = ar[begin1++];
	while (begin2 <= end2)
		tmp[k++] = ar[begin2++];

	memcpy(ar + left, tmp + left, sizeof(int) * (right - left + 1));
}
void MergeSort(int* a, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a,0,n-1 ,tmp);
	free(tmp);
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right) {

}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n) {

}

// 计数排序

void CountSort(int* a, int n) {


}
#endif // ! __SORTWORK_H__
