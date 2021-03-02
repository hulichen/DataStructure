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

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
// ����������
void BinaryTreeDestory(BTNode** root);
// �������ڵ����
int BinaryTreeSize(BTNode* root);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root);
// �������������
void BinaryTreeInOrder(BTNode* root);
// �������������
void BinaryTreePostOrder(BTNode* root);
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);



//��s�ڵ�ĸ��ڵ�
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



// ���������� /////�е�����
void BinaryTreeDestory(BTNode** bt)
{

	if (*bt != NULL) {	
		BinaryTreeDestory(&(*bt)->_left); //����Ϊ����ָ��
		BinaryTreeDestory(&(*bt)->_right);
		free(*bt);
		*bt = NULL;
	}

}


// �������ڵ����
int BinaryTreeSize(BTNode* bt) {
	if (bt == NULL)
		return 0;
	else
		return BinaryTreeSize(bt->_left) + BinaryTreeSize(bt->_right) + 1;
}


// ������Ҷ�ӽڵ����

int BinaryTreeLeafSize(BTNode* bt) {
	if (bt == NULL)
		return 0;
	if (bt->_left == NULL && bt->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(bt->_left) + BinaryTreeLeafSize(bt->_right);

}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* bt, int k) {
	if (bt==NULL || k <=0 )
		return 0;
	if (k ==1 )
		return 1;
	return BinaryTreeLevelKSize(bt->_left, k - 1) + BinaryTreeLevelKSize(bt->_right, k - 1);
}


// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* bt, BTDataType x) {
	BTNode* p;
	if (bt == NULL)
		return	NULL;
	else if (bt->_data == x)
		return bt;
	else
		p= BinaryTreeFind(bt->_left, x);
		if(NULL!=p)   //�����ҵ��˷���bt    ���򲻷��أ�p==NULL��������������
			return p;
		else
			return BinaryTreeFind(bt->_right, x);		
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* bt) {
	if (bt == NULL)
		return NULL;
	else {
		printf("%c", bt->_data);
		BinaryTreePrevOrder(bt->_left);
		BinaryTreePrevOrder(bt->_right);
	}
}
// �������������
void BinaryTreeInOrder(BTNode* bt) {
	if (bt != NULL) {
		BinaryTreeInOrder(bt->_left);
		printf("%c", bt->_data);
		BinaryTreeInOrder(bt->_right);
	}
}
// �������������
void BinaryTreePostOrder(BTNode* bt) {
	if (bt != NULL) {
		BinaryTreePostOrder(bt->_left);
		BinaryTreePostOrder(bt->_right);
		printf("%c", bt->_data);
	}
}

// �������
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
// �ж϶������Ƿ�����ȫ������
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

//�Ҹ��ڵ�
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
//	printf("\n�ڵ����%d\n", BinaryTreeSize(bt));
//
//	BTNode* findbt = BinaryTreeFind(bt, 'B');
//	printf("find�ڵ�:  %c\n", findbt->_data);
//
//	BTNode* sparent = FindParent(bt, findbt);
//	printf("find %c �ĸ��ڵ�:  %c\n", findbt->_data, sparent->_data);
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
//	printf("\n��k��ڵ���%d\n", BinaryTreeLevelKSize(bt, 4));
//
//
//	BinaryTreeDestory(bt);//������
//
//
//	return 0;
//}
