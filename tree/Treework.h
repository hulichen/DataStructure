#ifndef __TREEWORK_H__
#define __TREEWORK_H__
#include "Queue.h"
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
// 二叉树销毁
void BinaryTreeDestory(BTNode** root);
// 二叉树节点个数
int BinaryTreeSize(BTNode* root);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root);
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);



//找s节点的父节点
BTNode* FindParent(BTNode* root, BTNode* s);
bool IsEqual(BTNode* bt1, BTNode* bt2);





BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi) {
	if (a[*pi] == '#') {
		(*pi)++;
		return NULL;
	}
	if ((*pi) == n) {
		return NULL;
	}
	else {
		BTNode* t = (BTNode*)malloc(sizeof(BTNode));
		t->_data = a[*pi];
		(*pi)++;
		t->_left = BinaryTreeCreate( a, n, pi);
		t->_right = BinaryTreeCreate(a, n, pi);
		return t;
	}
}



// 二叉树销毁 /////有点问题
void BinaryTreeDestory(BTNode** bt)
{

	if (*bt != NULL) {	
		BinaryTreeDestory(&(*bt)->_left); //传参为二级指针
		BinaryTreeDestory(&(*bt)->_right);
		free(*bt);
		*bt = NULL;
	}

}


// 二叉树节点个数
int BinaryTreeSize(BTNode* bt) {
	if (bt == NULL)
		return 0;
	else
		return BinaryTreeSize(bt->_left) + BinaryTreeSize(bt->_right) + 1;
}


// 二叉树叶子节点个数

int BinaryTreeLeafSize(BTNode* bt) {
	if (bt == NULL)
		return 0;
	if (bt->_left == NULL && bt->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(bt->_left) + BinaryTreeLeafSize(bt->_right);

}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* bt, int k) {
	if (bt==NULL || k <=0 )
		return 0;
	if (k ==1 )
		return 1;
	return BinaryTreeLevelKSize(bt->_left, k - 1) + BinaryTreeLevelKSize(bt->_right, k - 1);
}


// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* bt, BTDataType x) {
	BTNode* p;
	if (bt == NULL)
		return	NULL;
	else if (bt->_data == x)
		return bt;
	else
		p= BinaryTreeFind(bt->_left, x);
		if(NULL!=p)   //左数找到了返回bt    否则不返回（p==NULL）继续右树查找
			return p;
		else
			return BinaryTreeFind(bt->_right, x);		
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* bt) {
	if (bt == NULL)
		return NULL;
	else {
		printf("%c", bt->_data);
		BinaryTreePrevOrder(bt->_left);
		BinaryTreePrevOrder(bt->_right);
	}
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* bt) {
	if (bt != NULL) {
		BinaryTreeInOrder(bt->_left);
		printf("%c", bt->_data);
		BinaryTreeInOrder(bt->_right);
	}
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* bt) {
	if (bt != NULL) {
		BinaryTreePostOrder(bt->_left);
		BinaryTreePostOrder(bt->_right);
		printf("%c", bt->_data);
	}
}

// 层序遍历
#include "Queue.h"
void BinaryTreeLevelOrder(BTNode* bt) {
	if (bt != NULL) {
		LinkQueue q;
		LinkQueueInit(&q);
		LinkQueueEn(&q, bt);
		while (!LinkQueueEmpty(&q)) {
			BTNode* t = LinkQueueFront(&q);
			LinkQueueDe(&q);
			printf("%c", t->_data);
			if (t->_left != NULL) {
				LinkQueueEn(&q, t->_left);
			}
			if (t->_right != NULL) {
				LinkQueueEn(&q, t->_right);
			}
		}

	}
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* bt) {
	int flag = 0;
	if (bt == NULL)
		return 1;
	if (bt != NULL) {
		LinkQueue q;
		LinkQueueInit(&q);
		LinkQueueEn(&q, bt);
		while (!LinkQueueEmpty(&q)) {
			BTNode* t = LinkQueueFront(&q);
			LinkQueueDe(&q);
			if (t== NULL) {
				flag = 1;
				continue;
			}	
			else if (flag)
					return 0;
			else {
				LinkQueueEn(&q, t->_left);
				LinkQueueEn(&q, t->_right);
			}
		}
	}
	return 1;
}


BTNode* Clone(BTNode* bt);
BTNode* Clone(BTNode* bt) {
	
	if (bt == NULL)
		return NULL;
	else {
		BTNode* newbt = (BTNode*)malloc(sizeof(BTNode));
		newbt->_data = bt->_data;
		newbt->_left = Clone(bt->_left);
		newbt->_right = Clone(bt->_right);
		return newbt;
	}
}

//找父节点
BTNode* FindParent(BTNode* bt, BTNode* s) {
	BTNode* p;
	if (bt == NULL || bt == s)
		return NULL;
	else if (bt->_left == s || bt->_right == s)
		return bt;

	p = FindParent(bt->_left, s);
	if (p != NULL)
		return p;
	else
		return FindParent(bt->_right, s);

}
bool IsEqual(BTNode* bt1, BTNode* bt2) {
	if (bt1 == NULL && bt2 == NULL)
		return true;
	if (bt1 == NULL || bt2 == NULL || bt1->_data != bt2->_data)
		return false;
	//else {
	//	if (bt1->_data == bt2->_data)
	//		return true;
	//}
	return IsEqual(bt1->_left, bt2->_left)&&IsEqual(bt1->_left, bt2->_left);


}


#endif // !__TREEWORK_H__



//
//#include"Treework.h"
//
//
//int main()
//{
//	BTNode* bt = NULL;
//	BTDataType* a = "ABD##E#H##CF##G##";
//	BTDataType* a = "ABD##E#H##CF##G##";
//	int n = sizeof(a);
//	int  pi = 0;
//	bt = BinaryTreeCreate(a, n, &pi);
//	BinaryTreePrevOrder(bt);
//
//	printf("\n节点个数%d\n", BinaryTreeSize(bt));
//
//	BTNode* findbt = BinaryTreeFind(bt, 'B');
//	printf("find节点:  %c\n", findbt->_data);
//
//	BTNode* sparent = FindParent(bt, findbt);
//	printf("find %c 的父节点:  %c\n", findbt->_data, sparent->_data);
//
//
//	BTNode* clonebt = Clone(bt);
//	BinaryTreePrevOrder(clonebt);
//	if (IsEqual(bt, clonebt)) {
//		printf("\n相同\n");
//	}
//
//	printf("层次遍历：");
//	BinaryTreeLevelOrder(clonebt);
//
//
//
//	printf("\n%d\n", BinaryTreeComplete(bt));
//
//	printf("\n叶子节点数%d\n", BinaryTreeLeafSize(bt));
//	printf("\n第k层节点数%d\n", BinaryTreeLevelKSize(bt, 4));
//
//
//	BinaryTreeDestory(bt);//有问题
//
//
//	return 0;
//}
