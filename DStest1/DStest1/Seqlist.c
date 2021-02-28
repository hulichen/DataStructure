#include"Seqlist.h"
void SeqListInit(SeqList* psl)
{
	psl->base = (ElemTepe*)malloc(sizeof(ElemTepe) * SEQLIST_DEFAULT_SIZE);
	assert(psl->base != NULL);
	memset(psl->base, 0, sizeof(ElemTepe) * SEQLIST_DEFAULT_SIZE);
	psl->cap = SEQLIST_DEFAULT_SIZE;
	psl->size = 0;
}
void Menu(void) {
	printf("############################################\n");
	printf("###1: push _back      2: push _front     ###\n");
	printf("###3: show_list       0: quit_system     ###\n");
	printf("###4: pop_back        5: pop_front       ###\n");
	printf("###6: insert_val      7: insert_pos      ###\n");
	printf("###8:delete_val       9: delete_pos      ###\n");
	printf("###10: sort          11: find            ###\n");
	printf("###12: reverse       13: remove_all      ###\n");
	printf("###14: Destroy                           ###\n");
	printf("############################################\n");
}
void SeqListShow(SeqList* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++) {
		printf("%d ", psl->base[i]);
	}
	printf("\n");
	printf("当前列表 元素个数/容量 为： %d/%d\n", psl->size, psl->cap);
}

static int IsFull(SeqList* psl) {
	if (psl->size ==psl->cap) {
		printf("列表已满!\n");
		return 1;
	}
	return 0;
}
static int IsEmpty(SeqList* psl) {
	if (psl->size == 0) {
		return 1;
	}
	return 0;
}

void SeqListPushBack(SeqList* psl, ElemTepe x) //尾插
{
	if (IsFull(psl)  &&  !CheckCapacity(psl)) {
	}
	psl->base[psl->size] = x;
	psl->size++;
}
void SeqListPushFront(SeqList* pst, ElemTepe x)//前插
{
	assert(pst);
	if(IsFull(pst) && !CheckCapacity(pst)){
	}	
	for (int i = pst->size; i>0; i--) {
		pst->base[i] = pst->base[i-1];
	}
	pst->base[0] = x;
	pst->size++;
}

void SeqListPopBack(SeqList* psl) //尾部删除
{
	assert(psl);
	psl->size--;
	return;
}
void SeqListPopFront(SeqList* psl) {  //头部删除
	assert(psl);
	if (IsEmpty(psl)) {
		printf("列表已空，无法删除\n");
		return;
	}
	for (int i = 0; i < psl->size-1; i++) {
		psl->base[i] = psl->base[i+1];
	}
	psl->size--;
	return;
}

int SeqListFind(SeqList* psl, ElemTepe x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++) {
		if (x == psl->base[i]) {
			return i;  //找到了返回这个元素的索引下标；
		}
	}
	return -1;
}
void SeqListSort(SeqList* psl) {
	assert(psl);
	for (int i = 0; i < psl->size-1; i++) {
		for(int j = 0;j<psl->size - i-1;j++)
			if (psl->base[j] > psl->base[j + 1]) {
				int tmp = psl->base[j + 1];
				psl->base[j + 1] = psl->base[j];
				psl->base[j] = tmp;
			}
	}
	SeqListShow(psl);
}

void SeqListInsert_pos(SeqList* psl, size_t pos, ElemTepe x)// 顺序表在pos位置插入x
{

	assert((NULL  != psl) || pos < psl->size || pos >=0);
	if (IsFull(psl) && !CheckCapacity(psl) ) {
	}

	for (int i = psl->size; i > pos ;  i--) {
		psl->base[i] = psl->base[i - 1];
	}
	psl->base[pos] = x;
	psl->size++;
}
void SeqListInsert_val(SeqList* psl, ElemTepe x) {
	assert(psl);
	if (IsFull(psl) && !CheckCapacity(psl)) {
	}
	SeqListSort(psl);
	int pos = -1;
	if (x < psl->base[0]) {
		SeqListPushFront(psl, x);
	}
	if (x > psl->base[psl->size - 1]) {
		SeqListPushBack(psl, x);
	}
	for (int i = 1; i < psl->size-1; i++) {

		if (x >= psl->base[i] && x <= psl->base[i + 1]) {
			pos = i+1;			
		}
	}
	for (int i = psl->size; i > pos; i--) {
		psl->base[i] = psl->base[i - 1];
	}
	psl->base[pos] = x;
	psl->size++;
}
void SeqListDelete_val(SeqList* psl, ElemTepe x, int delselect) //删除指定值
{
	assert(psl);
	if (1 == delselect) {
		int pos = SeqListFind(psl, x);
		if (pos == -1) {
			printf("要找的值不存在！\n");
			return;
		}
		for (int i = pos; i < psl->size-1; i++) {
			psl->base[i] = psl->base[i + 1];
		}
		psl->size--;
	}
	if (2 == delselect) { 
		while (1) {
			int pos = SeqListFind(psl, x);
			if (-1 == pos) {
				printf("要找的值不存在！\n");
				break;
			}
			for (int i = pos; i < psl->size - 1; i++) {
				psl->base[i] = psl->base[i + 1];
			}
			psl->size--;
		}
	}
	
}
void SeqListDelete_pos(SeqList* psl, int pos)
{
	assert(psl && (pos >= 0) && (pos < psl->size));
	int index = pos - 1;
	for (int i = index; i < psl->size-1; i++) {
		psl->base[index] = psl->base[index + 1];
	}
	psl->size--;
}

void SeqListReverse(SeqList* psl) {
	assert(psl);
	int left = 0;
	int right = psl->size - 1;
	while(left<right){
		int tmp = psl->base[left];
		psl->base[left] = psl->base[right];
		psl->base[right] = tmp;
		left++;
		right--;
	}
}
void SeqListRemove_all(SeqList* psl)
{
	psl->size = 0;
	return;
}
void SeqListDestroy(SeqList* psl)
{
	psl->size = psl ->cap =  0;
	free(psl->base);
	return;
}

int CheckCapacity(SeqList* psl) {
	ElemTepe* p = (ElemTepe*)realloc(psl->base, sizeof(ElemTepe) * (psl->cap + EXPASIONNUM));
	if (p == NULL) {
		printf("扩容失败！\n");
		return 0;
	}
	printf("扩容成功！\n");
	psl->base = p;
	psl->cap += EXPASIONNUM;
	return 1;
}