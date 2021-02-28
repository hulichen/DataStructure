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
		printf("* [1]入队               [2] 出队           *\n");
		printf("* [3]当前元素个数       [4] showt          *\n");
		printf("* [5]销毁               [6] 队头元素       *\n");
		printf("* [7]队尾元素           [8]                *\n");
		printf("********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  
				QueuePush(&myqueue, item);
			break;	
		case 2:
			QueuePop(&myqueue);
			break;		
		case 3:
			printf("栈中元素个数为%d \n", QueueSize(&myqueue));
			break;
		case 4:
			QueueShow(&myqueue);
			break;
		case 5:
			QueueDestroy(&myqueue);
				break;
		case 6:
			printf("队头元素%d \n", QueueFront(&myqueue));
			break;			
		case 7:
			printf("队尾元素%d \n", QueueBack(&myqueue)); 
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
//		printf("请选择:>");
//		scanf("%d", &select);
//		switch (select)
//		{
//		case 1:
//			printf("请输入要插入的数据(以-1结束):>");
//			while (scanf("%d", &item), item != -1)  //逗号表达式
//				DCListPushBack(&mylist, item);
//			break;
//		case 2:
//			printf("请输入要插入的数据(以-1结束):>");
//			while (scanf("%d", &item), item != -1)  //逗号表达式
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
//			printf("表长为:>%d\n", mylist.size);
//			break;		
//		case 7:
//			printf("请输入要插入的值:>");
//			scanf("%d", &item);
//			DCListInsertByVal(&mylist, item);
//			break;
//		case 8:
//			printf("请输入要删除的值:>");
//			scanf("%d", &key);
//			DCListDeleteByVal(&mylist, key);
//			break;		
//		case 9:
//			printf("请输入要查找的值:>");
//			scanf("%d", &key);
//			p = DCListFind(&mylist, key);
//			if (p == NULL)
//				printf("要查找的值%d不存在.\n", key);
//			else
//				printf("要查找的值%d存在.\n", key);
//			break;
//		case 10:
//			DCListSort(&mylist);
//			break;
//		case 11:
//			DCListReverse(&mylist);
//			break;
//		//case 12:
//		//	printf("请输入要删除的值:>");
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
//		printf("请选择:>");
//		scanf("%d", &select);
//		switch (select)
//		{
//		case 1:
//			printf("请输入要插入的数据(以-1结束):>");
//			while (scanf("%d", &item), item != -1)  //逗号表达式
//				SListPushBack(&mylist, item);
//			break;
//		case 2:
//			printf("请输入要插入的数据(以-1结束):>");
//			while (scanf("%d", &item), item != -1)  //逗号表达式
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
//			printf("表长为:>%d\n", SListLength(&mylist));
//			break;		
//		case 7:
//			printf("请输入要插入的值:>");
//			scanf("%d", &item);
//			SListInsertByVal(&mylist, item);
//			break;
//		case 8:
//			printf("请输入要删除的值:>");
//			scanf("%d", &key);
//			SListDeleteByVal(&mylist, key);
//			break;		
//		case 9:
//			printf("请输入要查找的值:>");
//			scanf("%d", &key);
//			p = SListFind(&mylist, key);
//			if (p == NULL)
//				printf("要查找的值%d不存在.\n", key);
//			else
//				printf("要查找的值%d存在.\n", key);
//			break;
//		case 10:
//			SListSort(&mylist);
//			SListShow(&mylist);
//			break;
//		case 11:
//			SListReverse(&mylist);
//			break;
//		case 12:
//			printf("请输入要删除的值:>");
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
//		printf("请选择\n");
//		int select = 0;
//		scanf("%d", &select);
//		switch (select)
//		{
//		case 1:
//			printf("请输入要插入的数据，(以-1结束)：\n");
//			while (scanf("%d", &item), item != -1) {
//				SeqListPushBack(&mylist, item);
//			}
//			break;
//		case 2:
//			printf("请输入要插入的数据，(以-1结束)：\n");
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
//			printf("请输入要插入数据\n");
//			scanf("%d", &item);
//			SeqListInsert_val(&mylist, item);
//			break;
//		case 7:
//			printf("请输入要插入的数据：\n");
//			scanf("%d", &item);
//			printf("请输入要插入的位置：\n");
//			scanf("%d", &pos);
//			SeqListInsert_pos(&mylist, pos, item);		
//			break;
//		case 8:
//			printf("请输入要删除的数据：\n");
//			scanf("%d", &item);
//			printf("请选择1或2：\n");
//			printf(" 1 : 只删除第一个val\n");
//			printf(" 2 : 只删除全部val\n");
//			scanf("%d", &delselect);
//			SeqListDelete_val(&mylist,item,delselect);
//		
//			break;
//		case 9:
//			printf("请输入要删除的数据pos：\n");
//			scanf("%d", &pos);
//			SeqListDelete_pos(&mylist, pos);
//			break;
//		case 10:
//			SeqListSort(&mylist);
//			break;
//		case 11:
//			printf("请输入要查找的数据：\n");
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