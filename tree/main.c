
















//
//#include"HeapWork.h"
//
//
//int main() 
//{
//	Heap hp;
//
//	HPDataType arr[] = { 27,15,19,18,28,34,65,49,25,37,22,33,55,66,88,44,77,99,66,55,1,21,17 };
//	
//	PrintTopK(arr, sizeof(arr) / sizeof(arr[0]), 10);
//	/*HeapInit(&hp, 20);
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
//		HeapPush(&hp, arr[i]);
//	}*/
//
//	//while (hp._size != 0) {
//	//	int a = HeapTop(&hp);
//	//	printf("%d ", a);
//	//	HeapPop(&hp);
//	//}
//
//	return 0;
//}

//oj��ҵ
//#include<string.h>
//#include<assert.h>
//#include<stdlib.h>
//#include<stdio.h>
//#include<windows.h>
//#include<stdbool.h>
//#pragma warning(disable:4996)
//#pragma warning(disable:4996)
//
//#define TreeElemType  char
//typedef struct	BinTreeNode {
//	TreeElemType data;
//	struct	BinTreeNode* leftChild;
//	struct	BinTreeNode* rightChild;
//
//}BinTreeNode;
//
////�������νṹ
//typedef BinTreeNode* BinTree;
//
//BinTree CreateBinTree(const char* str, int* i)
//{
//	if (str[*i] == '#') {
//		(*i)++;
//		return NULL;
//	}
//	if (str[*i] == '\0') {
//		return NULL;
//	}
//	else {
//		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
//		assert(t);
//		t->data = str[*i];
//		(*i)++;
//		t->leftChild = CreateBinTree(str, i);
//		t->rightChild = CreateBinTree(str, i);
//		return t;
//	}
//}
//
//void InOrder(BinTree t) {
//	if (t != NULL) {
//		InOrder(t->leftChild);
//		printf("%c", t->data);
//		InOrder(t->rightChild);
//	}
//}
//
////void DestroyBinTree(BinTree* t) {
////	if ((*t) != NULL) {
////		DestroyBinTree((*t)->leftChild);
////		DestroyBinTree((*t)->rightChild);
////		free(*t);
////		*t = NULL;
////	}
////}
//int main() {
//	const char* str = "abc##de#g##f###";
//	int i = 0;
//	BinTreeNode* t = CreateBinTree(str, &i);
//	InOrder(t);
//	//DestroyBinTree(&t);
//	return 0;
//}


//#include"Treework.h"
//int main()
//{
//	BTNode* bt = NULL;
//	//BTDataType* a = "ABD##E#H##CF##G##";
//	BTDataType* a = "ABD##E#H##CF##G##";
//	int n = sizeof(a);
//	int  pi = 0;
//	bt = BinaryTreeCreate( a,  n, &pi);
//	BinaryTreePrevOrder(bt);
//
//	printf("\n�ڵ����%d\n", BinaryTreeSize(bt));
//
//	BTNode* findbt = BinaryTreeFind(bt, 'B');
//	printf("find�ڵ�:  %c\n", findbt->_data);
//
//	BTNode* sparent = FindParent(bt, findbt);
//	printf("find %c �ĸ��ڵ�:  %c\n", findbt->_data,sparent->_data);
//
//
//	BTNode* clonebt = Clone(bt);
//	BinaryTreePrevOrder(clonebt);
//	if (IsEqual(bt, clonebt)) {
//		printf("\n��ͬ\n");
//	}
//
//	printf("��α�����");
//	BinaryTreeLevelOrder(clonebt);
//
//
//
//	printf("\n%d\n", BinaryTreeComplete(bt));
//
//	printf("\nҶ�ӽڵ���%d\n", BinaryTreeLeafSize(bt));
//	printf("\n��k��ڵ���%d\n", BinaryTreeLevelKSize(bt,4));
//
//
//	BinaryTreeDestory(bt);
//	
//
//	return 0;
//}




////sort work
//#include"SortWork.h"
//int main()
//{
//	int ar1[] = { 12, 9, 38, 65, 97, 76, 13, 27, 49,0 ,221,66,44,21,1,-2};
//	int ar2[] = { 12, 9, 38, 65, 97, 76, 13, 27, 49,0 ,221,66,44,21,1,-2 };
//	int ar3[] = { 12, 9, 38, 65, 97, 76, 13, 27, 49,0 ,221,66,44,21,1,-2 };
//	int ar4[] = { 12, 9, 38, 65, 97, 76, 13, 27, 49,0 ,221,66,44,21,1,-2 };
//	int ar5[] = { 12, 9, 38, 65, 97, 76, 13, 27, 49,0 ,221,66,44,21,1,-2 };
//	int ar6[] = { 12, 9, 38, 65, 97, 76, 13, 27, 49,0 ,221,66,44,21,1,-2 };
//	int ar7[] = { 12, 9, 38, 65, 97, 76, 13, 27, 49,0 ,221,66,44,21,1,-2 };
//	int ar8[] = { 12, 9, 38, 65, 97, 76, 13, 27, 49,0 ,221,66,44,21,1,-2 };
//	int ar9[] = { 12, 9, 38, 65, 97, 76, 13, 27, 49,0 ,221,66,44,21,1,-2 };
//	int n = sizeof(ar1) / sizeof(ar1[0]);
//	printf("Ԫ���ݣ�");
//	PrintArray(ar1, n);
//	printf("ѡ���ţ�");
//	SelectSort(ar1, n);
//	PrintArray(ar1, n);
//	printf("ϣ���ţ�");
//	ShellSort(ar2, n);
//	PrintArray(ar2, n);
//	printf("�����ţ�");
//	InsertSort(ar3, n);
//	PrintArray(ar3, n);
//
//	printf("�� �ţ� ");
//	HeapSort(ar4, n);
//	PrintArray(ar4, n);
//
//	printf("ð���ţ� ");
//	BubbleSort(ar5, n);
//	PrintArray(ar5, n);
//
//	printf("kuai��1�� ");
//	QuickSort(ar6, 0, n);
//	PrintArray(ar6, n);
//
//
//	MergeSort(ar7, n);
//	PrintArray(ar7, n);
//
//
//
//	return 0;
//}
//




////#include"SeqList.h"
////#include"List.h"
////#include"Stack.h"
////#include"Queue.h"
////#include"Tree.h"
////#include"Heap.h"
//#include"Sort.h"
//
//int main()
//{
//	int ar[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
//	//int ar[] = {12, 38, 65, 97, 100, 200, 300};
//	//int ar[] = {9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
//	int n = sizeof(ar) / sizeof(ar[0]);
//	PrintArray(ar, 0, n);
//
//	//����
//	//InsertSort_1(ar, 0, n);
//	//InsertSort_2(ar, 0, n);
//	//InsertSort_3(ar, 0, n);
//	//BinInsertSort(ar, 0, n);
//	//TwoWayInsertSort(ar, 0, n);
//	//ShellSort(ar, 0, n);
//	//SelectSort(ar, 0, n);
//	HeapSort(ar, 0, n);
//
//	PrintArray(ar, 0, n);
//
//	//����Ч��
//	TestSortEfficient();
//
//	return 0;
//}
//

//int main()
//{
//	int ar[] = {0, 49, 38, 65, 97, 76, 13, 27, 49};
//	int n = sizeof(ar) / sizeof(ar[0]);
//	PrintArray(ar, 1, n);
//	//����
//	//InsertSort_1(ar, 0, n);
//	//InsertSort_2(ar, 0, n);
//	//InsertSort_3(ar, 0, n);
//	InsertSort_4(ar, 1, n);
//	PrintArray(ar, 1, n);
//	//����Ч��
//	TestSortEfficient();
//	return 0;
//}



////#include"SeqList.h"
////#include"List.h"
//#include"Stack.h"
//#include"Queue.h"
//#include"mytree.h"
//
//void main()
//{
//	char* str = "ABC##DE##F##G#H##";
//	BinTree bt;
//	BinTreeInit(&bt);
//
//	//BinTreeCreate_1(&bt);
//	//bt = BinTreeCreate_2();
//
//	int index = 0;
//	bt = BinTreeCreate_3(str, &index);
//	printf("ǰ�� ");
//	PreOrder(bt);
//	printf("\n����: ");
//	InOrder(bt);
//	printf("\n����: ");
//	PostOrder(bt);
//	printf("\n�ǵݹ� �����: \n");
//	LevelOrder(bt);
//	
//
//	printf("Size = %d\n", Size(bt));   //8
//	printf("Height = %d\n", Height(bt));   //
//
//
//
//	char key = 'H';
//	printf("�����ҵ�%c\n", key);
//	BinTreeNode* p = Find(bt, key);
//	printf("%c\n", p->data);
//
//
//
//	printf("��%c���ڵ�\n", p->data);
//	BinTreeNode* pr = Parent(bt, p);
//	printf("%c\n", pr->data);
//
//	BinTree bt1 = Clone(bt);
//	printf("Cloneǰ�� ");
//	PreOrder(bt1);
//
//	bool flag = Equal(bt, bt1);
//	printf("\n�ǵݹ�ǰ��:\n");
//	PreOrder_Nor(bt1);
//	printf("\n�ǵݹ�zhong��:\n");
//
//	InOrder_Nor(bt);
//	printf("\n�ǵݹ�hou��:\n");
//	PostOrder_Nor(bt);
//	const char* vlr ="ABCDEFGH" ;
//	const char* lvr= "CBEDFAGH";
//	const char* lrv= "CEFDBHGA";
//	int n = strlen(lvr);
//	BinTree bt2 = BinTreeCreate_VLR_LVR(vlr, lvr, n);
//	BinTree bt3 = BinTreeCreate_LVR_LRV(lvr, lrv, n);
//	printf("\nvlr_lvr:\n");
//	PreOrder_Nor(bt2);
//	printf("\nlrv_lvr:\n");
//	PreOrder_Nor(bt3);
//
//}



//#include "mytree.h"
//
//int main() {
//	BinTree bt;
//	BinTreeInit(&bt);
//	BinTreeCreate_1(&bt);
//	//abc##de##f##g#h##
//
//
//
//
//	printf("qianxu:\n");
//	void PreOrder(bt);
//	printf("zhongxu\n");
//	void InOrder(bt);
//	printf("houxu\n");
//	PostOrder(bt);
//
//	BinTreeNode* a=Find(bt, 'c');
//	printf("%c\n", a->data);
//
//
//	return 0;
//}