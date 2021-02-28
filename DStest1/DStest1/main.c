#include"Stack.h"
int main()
{
	QDataType item;
	Queue myqueue;
	QueueInit(&myqueue);
	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("* [1]���               [2] ����           *\n");
		printf("* [3]��ǰԪ�ظ���       [4] showt          *\n");
		printf("* [5]����               [6] ��ͷԪ��       *\n");
		printf("* [7]��βԪ��           [8]                *\n");
		printf("********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  
				QueuePush(&myqueue, item);
			break;	
		case 2:
			QueuePop(&myqueue);
			break;		
		case 3:
			printf("ջ��Ԫ�ظ���Ϊ%d \n", QueueSize(&myqueue));
			break;
		case 4:
			QueueShow(&myqueue);
			break;
		case 5:
			QueueDestroy(&myqueue);
				break;
		case 6:
			printf("��ͷԪ��%d \n", QueueFront(&myqueue));
			break;			
		case 7:
			printf("��βԪ��%d \n", QueueBack(&myqueue)); 
			break;
		default:
			break;
		}
		system("pause");
		QueueShow(&myqueue);
	}
	return 0;
}













//
//#include"DCList.h"
//int main()
//{
//	DCList mylist;
//	DCSListInit(&mylist);
//	ElemTepe item, key;
//	int pos;
//	DCListNode* p;
//	int select = 1;
//	while (select)
//	{
//		printf("********************************************\n");
//		printf("* [0] quit_system      [1] push_back       *\n");
//		printf("* [2] push_front       [3] show_list       *\n");
//		printf("* [4] pop_back         [5] pop_front       *\n");
//		printf("* [6] length           [7] insert_val      *\n");
//		printf("* [8] delete_val       [9] find            *\n");
//		printf("* [10] sort            [11] reverse        *\n");
//		printf("* [12] remove_all      [13] clear          *\n");
//		printf("********************************************\n");
//		printf("��ѡ��:>");
//		scanf("%d", &select);
//		switch (select)
//		{
//		case 1:
//			printf("������Ҫ���������(��-1����):>");
//			while (scanf("%d", &item), item != -1)  //���ű��ʽ
//				DCListPushBack(&mylist, item);
//			break;
//		case 2:
//			printf("������Ҫ���������(��-1����):>");
//			while (scanf("%d", &item), item != -1)  //���ű��ʽ
//				DCListPushFront(&mylist, item);
//			break;
//		case 3:
//			DCListShow(&mylist);
//			break;
//		case 4:
//			DCListPopBack(&mylist);
//			break;
//		case 5:
//			DCListPopFront(&mylist);
//			break;
//		case 6:
//			printf("��Ϊ:>%d\n", mylist.size);
//			break;		
//		case 7:
//			printf("������Ҫ�����ֵ:>");
//			scanf("%d", &item);
//			DCListInsertByVal(&mylist, item);
//			break;
//		case 8:
//			printf("������Ҫɾ����ֵ:>");
//			scanf("%d", &key);
//			DCListDeleteByVal(&mylist, key);
//			break;		
//		case 9:
//			printf("������Ҫ���ҵ�ֵ:>");
//			scanf("%d", &key);
//			p = DCListFind(&mylist, key);
//			if (p == NULL)
//				printf("Ҫ���ҵ�ֵ%d������.\n", key);
//			else
//				printf("Ҫ���ҵ�ֵ%d����.\n", key);
//			break;
//		case 10:
//			DCListSort(&mylist);
//			break;
//		case 11:
//			DCListReverse(&mylist);
//			break;
//		//case 12:
//		//	printf("������Ҫɾ����ֵ:>");
//		//	scanf("%d", &key);
//		//	DCSListRemoveAll(&mylist, key);
//		//	break;
//		case 13:
//			DCListClear(&mylist);
//			break;
//		default:
//			break;
//		}
//		system("pause");
//		DCListShow(&mylist);
//		/*system("cls");*/
//	}
//	DCListDestroy(&mylist);
//	return 0;
//}




//#include"List.h"
//int main()
//{
//	SList mylist;
//	SListInit(&mylist);
//	ElemType item, key;
//	int pos;
//	SListNode* p;
//	int select = 1;
//	while (select)
//	{
//		printf("********************************************\n");
//		printf("* [0] quit_system      [1] push_back       *\n");
//		printf("* [2] push_front       [3] show_list       *\n");
//		printf("* [4] pop_back         [5] pop_front       *\n");
//		printf("* [6] length           [7] insert_val      *\n");
//		printf("* [8] delete_val       [9] find            *\n");
//		printf("* [10] sort            [11] reverse        *\n");
//		printf("* [12] remove_all      [13] clear          *\n");
//		printf("********************************************\n");
//		printf("��ѡ��:>");
//		scanf("%d", &select);
//		switch (select)
//		{
//		case 1:
//			printf("������Ҫ���������(��-1����):>");
//			while (scanf("%d", &item), item != -1)  //���ű��ʽ
//				SListPushBack(&mylist, item);
//			break;
//		case 2:
//			printf("������Ҫ���������(��-1����):>");
//			while (scanf("%d", &item), item != -1)  //���ű��ʽ
//				SListPushFront(&mylist, item);
//			break;
//		case 3:
//			SListShow(&mylist);
//			break;
//		case 4:
//			SListPopBack(&mylist);
//			break;
//		case 5:
//			SListPopFront(&mylist);
//			break;
//		case 6:
//			printf("��Ϊ:>%d\n", SListLength(&mylist));
//			break;		
//		case 7:
//			printf("������Ҫ�����ֵ:>");
//			scanf("%d", &item);
//			SListInsertByVal(&mylist, item);
//			break;
//		case 8:
//			printf("������Ҫɾ����ֵ:>");
//			scanf("%d", &key);
//			SListDeleteByVal(&mylist, key);
//			break;		
//		case 9:
//			printf("������Ҫ���ҵ�ֵ:>");
//			scanf("%d", &key);
//			p = SListFind(&mylist, key);
//			if (p == NULL)
//				printf("Ҫ���ҵ�ֵ%d������.\n", key);
//			else
//				printf("Ҫ���ҵ�ֵ%d����.\n", key);
//			break;
//		case 10:
//			SListSort(&mylist);
//			SListShow(&mylist);
//			break;
//		case 11:
//			SListReverse(&mylist);
//			break;
//		case 12:
//			printf("������Ҫɾ����ֵ:>");
//			scanf("%d", &key);
//			SListRemoveAll(&mylist, key);
//			break;
//		case 13:
//			SListClear(&mylist);
//			break;
//		default:
//			break;
//		}
//		system("pause");
//		system("cls");
//	}
//	SListDestroy(&mylist);
//	return 0;
//}






//#include"Seqlist.h"
//int main()
//{
//	SeqList mylist;
//	int item = 0;
//	int pos = -1;
//	SeqListInit(&mylist);
//	int select = 1;
//	int delselect = 1;
//	while (select) {
//		Menu();
//		printf("��ѡ��\n");
//		int select = 0;
//		scanf("%d", &select);
//		switch (select)
//		{
//		case 1:
//			printf("������Ҫ��������ݣ�(��-1����)��\n");
//			while (scanf("%d", &item), item != -1) {
//				SeqListPushBack(&mylist, item);
//			}
//			break;
//		case 2:
//			printf("������Ҫ��������ݣ�(��-1����)��\n");
//			while (scanf("%d", &item), item != -1) {
//				SeqListPushFront(&mylist, item);
//			}
//			break;
//		case 3:
//			SeqListShow(&mylist);
//			break;
//		case 4:
//			SeqListPopBack(&mylist);
//			break;
//		case 5:
//			SeqListPopFront(&mylist);
//			break;
//		case 6:
//			printf("������Ҫ��������\n");
//			scanf("%d", &item);
//			SeqListInsert_val(&mylist, item);
//			break;
//		case 7:
//			printf("������Ҫ��������ݣ�\n");
//			scanf("%d", &item);
//			printf("������Ҫ�����λ�ã�\n");
//			scanf("%d", &pos);
//			SeqListInsert_pos(&mylist, pos, item);		
//			break;
//		case 8:
//			printf("������Ҫɾ�������ݣ�\n");
//			scanf("%d", &item);
//			printf("��ѡ��1��2��\n");
//			printf(" 1 : ֻɾ����һ��val\n");
//			printf(" 2 : ֻɾ��ȫ��val\n");
//			scanf("%d", &delselect);
//			SeqListDelete_val(&mylist,item,delselect);
//		
//			break;
//		case 9:
//			printf("������Ҫɾ��������pos��\n");
//			scanf("%d", &pos);
//			SeqListDelete_pos(&mylist, pos);
//			break;
//		case 10:
//			SeqListSort(&mylist);
//			break;
//		case 11:
//			printf("������Ҫ���ҵ����ݣ�\n");
//			scanf("%d", &item);
//			printf("%d\n",SeqListFind(&mylist, item)+1);
//			break;
//		case 12:
//			SeqListReverse(&mylist);
//			break;
//		case 13:
//			SeqListRemove_all(&mylist);
//			break;
//		case 14:
//			SeqListDestroy(&mylist);
//			break;
//		default:
//			break;
//		}
//		system("pause");
//		system("cls");
//		SeqListShow(&mylist);
//	}
//	return 0;
//}