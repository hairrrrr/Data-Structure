#define _CRT_SECURE_NO_WARNINGS 1

//### ��������
//:
//4 2
//3 1 4 2
//3 4 1 2
//3 2 4 1
//2 1
//2 1
//1 2 0
//### �������
//	:
//Yes
//No
//No


#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


typedef int ElementType;

typedef struct {
	ElementType data;
	BSTree* Left;
	BSTree* Right;
	bool isVisit; // �жϽ���Ƿ����
}BSTree;

BSTree* makeTree(int N);
BSTree* newNode(ElementType val);
BSTree* insertNode(BSTree* T, ElementType val);
bool isSameTree(BSTree* T, int N);
bool checkNode(BSTree* T, ElementType val);
void resetTree(BSTree* T);
void freeTree(BSTree* T);

int main(void) {

	int N, L, i;
	BSTree* T;

	scanf("%d", &N);

	while (N) {
		scanf("%d", &L);
		T = makeTree(N);
		for (i = 0; i < L; i++) {
			if (isSameTree(T, N)) printf("Yes\n");
			else printf("No");
			resetTree(T); // ��� T �еļ�¼ isVisit
		}
		freeTree(T);
		scanf("%d", &N); // ��� N Ϊ 0 �˳�
	}

	return 0;
}

// create BST
BSTree* makeTree(int N) {

	ElementType val;
	int i;

	scanf("%d", &val);
	BSTree* T = newNode(val);

	for (i = 1; i < N; i++) {
		scanf("%d", &val);
		T = insertNode(T, val);
	}
	
	return T;
}

// create node
BSTree* newNode(ElementType val) {

	BSTree* new_node = (BSTree*)malloc(sizeof(BSTree));
	
	new_node->data = val;
	new_node->isVisit = false;
	new_node->Left = new_node->Right = NULL;
}


BSTree* insertNode(BSTree* T, ElementType val) {

	if (!T)
		T = newNode(val);

	else {
		if (val > T->data)
			T->Right = insertNode(T->Right, val);
		else
			T->Left = insertNode(T->Left, val);
	}
	
	return T;
}


bool isSameTree(BSTree* T, int N) {

	int i;
	ElementType val;
	bool flg = true; // ��¼�˴������Ƿ���ԭʼ������ͬ

	scanf("%d", &val);

	// ����һ���϶�������ͬ��
	if (T->data != val) 
		return false;
	
	for (i = 1; i < N; i++) {
		scanf("%d", &val);
		// �� flg Ϊ���ҵ�ǰ����Ľ��������λ�ò���ʱ��flg ��Ϊ false
		// ��ʱ���ǲ�Ӧ�� break��Ӧ�ü������뵽�����������
		if (flg && !checkNode(T, val))
			flg = false;
	}


	(flg == true) ? true : false;
}


bool checkNode(BSTree* T, ElementType val) {
	
	if (T->isVisit) {
		if (val < T->data)
			return checkNode(T->Left, val);
		else if (val > T->data)
			return checkNode(T->Right, val);
		// ���ֵ�ظ���������ͬ��
		else
			return false;
	}
	// �ý��û�б�����
	else {
		if (val == T->data) {
			T->isVisit = true;
			return true;
		}
		// Ŀ��ֵ�����в�ͬ���Ҹý��û�б�����
		else
			return false;
	}
}

void resetTree(BSTree* T);
void freeTree(BSTree* T);


