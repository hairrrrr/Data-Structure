#define _CRT_SECURE_NO_WARNINGS 1

// ��ͷ+˫��+ѭ��������ɾ���ʵ��

#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

// �������
typedef struct ListNode
{
	DataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// ��ͷ
typedef struct ListHead {
	ListNode* head;
}ListHead;


// �ӿ�
void ListCreate(ListHead* plist);

void ListDestory(ListHead* plist);

void ListPrint(ListHead* plist);

void ListPushBack(ListHead* plist, DataType data);

void ListPopBack(ListHead* plist);

void ListPushFront(ListHead* plist, DataType data);

void ListPopFront(ListHead* plist);

ListNode* ListFind(ListHead* plist, DataType data);

void ListInsert(ListNode* pos, DataType data);

void ListErase(ListNode* pos);


int main(void) {
	
	ListHead plist;

	ListCreate(&plist);

	ListPushBack(&plist, 1);
	ListPushBack(&plist, 2);

	ListPopBack(&plist);
	ListPopBack(&plist);
	//ListPopBack(&plist);

	ListPushFront(&plist, 1);
	ListPushFront(&plist, 2);

	ListPopFront(&plist);
	ListPopFront(&plist);
	//ListPopFront(&plist);

	ListPushFront(&plist, 1);
	ListInsert(ListFind(&plist, 1), 0);
	ListErase(ListFind(&plist, 1));

	ListPrint(&plist);
	
	ListDestory(&plist);

	return 0;
}

ListNode* CreateNode(DataType data) {

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	
	if (node == NULL) {
		printf("malloc failed in %s\n", __func__);
		exit(EXIT_FAILURE);
	}

	node->data = data;
	node->next = node->prev = NULL;

	return node;
}


// �������������ͷ���.
void ListCreate(ListHead* plist) {
	
	// ������ͷ���
	plist->head = CreateNode(-1);
	// ʹ��ͷ���ѭ��
	plist->head->next = plist->head;
	plist->head->prev = plist->head;
}


// ˫������β��
void ListPushBack(ListHead* plist, DataType data) {

	//ListNode* head = plist->head; //����ͷ���
	//ListNode* last = plist->head->prev; // ����β���
	//ListNode* new_node = CreateNode(data);

	//new_node->next = head;
	//new_node->prev = last;

	//head->prev = new_node;
	//last->next = new_node;

	ListInsert(plist->head, data);
}


// ˫������βɾ
void ListPopBack(ListHead* plist) {

	//ListNode* remove_node = plist->head->prev;

	//// ������
	//if (remove_node == plist->head) {
	//	printf("Empty list exception in %s.\n", __func__);
	//	exit(EXIT_FAILURE);
	//}
	//	
	//ListNode* prev = remove_node->prev;

	//prev->next = plist->head; // �õ����ڶ������ָ��ͷ�ڵ�
	//plist->head->prev = prev; // ��ͷ���ָ�����ڶ������

	//free(remove_node);

	ListErase(plist->head->prev);
}


// ˫������ͷ��
void ListPushFront(ListHead* plist, DataType data) {

	//ListNode* head = plist->head->next; // �����һ�����
	//ListNode* new_node = CreateNode(data);

	//new_node->prev = plist->head;
	//new_node->next = head;

	//plist->head->next = new_node;
	//head->prev = new_node;

	ListInsert(plist->head->next, data);
}


// ˫������ͷɾ
void ListPopFront(ListHead* plist) {
	
	//ListNode* remove_node = plist->head->next; // ɾ����һ�����

	//if (remove_node == plist->head) {
	//	printf("Empty list exception in %s.\n", __func__);
	//	exit(EXIT_FAILURE);
	//}

	//ListNode* new_head = remove_node->next;

	//plist->head->next = new_head;
	//new_head->prev = plist->head;
	//
	//free(remove_node);

	ListErase(plist->head->next);
}


// ˫���������
ListNode* ListFind(ListHead* plist, DataType data) {

	ListNode* cur = plist->head->next;

	for (; cur != plist->head; cur = cur->next)
		if (cur->data == data)
			break;

	return cur;
}


// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, DataType data) {

	if (pos == NULL) {
		printf("nullptr exception in %s.\n", __func__);
		exit(EXIT_FAILURE);
	}

	ListNode* new_node = CreateNode(data);
	ListNode* pos_prev = pos->prev;

	new_node->next = pos;
	new_node->prev = pos_prev;

	pos_prev->next = new_node;
	pos->prev = new_node;
}


// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos) {
	
	if (pos == NULL) {
		printf("nullptr exception in %s.\n", __func__);
		exit(EXIT_FAILURE);
	}

	// �ձ���ɾ��
	if (pos->next == pos) {
		printf("Empty list exception in %s.\n", __func__);
		exit(EXIT_FAILURE);
	}

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	free(pos);
}


// ˫����������
void ListDestory(ListHead* plist) {

	ListNode* cur = plist->head->next;
	ListNode* cur_next;

	for (; cur != plist->head; cur = cur_next) {
		cur_next = cur->next;
		free(cur);
	}

	free(plist->head);
	plist->head = NULL;
}


// ˫�������ӡ
void ListPrint(ListHead* plist) {

	ListNode* cur = plist->head->next;

	for (; cur != plist->head; cur = cur->next)
		printf("%d ", cur->data);
}
