#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct List {
	int data;
	struct List* next;
}List;
typedef List* pList;

int Length(pList pL);
pList FindKth(int pst, pList pL);//�������
pList Find(int trg, pList pL);// ��ֵ����
pList Insert(int add_num, int pst, pList pL);// ����
pList Delete(int pst, pList pL);
void Print(pList pL);// ��ӡ
int main(void) {

	pList pL = (pList)malloc(sizeof(List));
	pList test;
	pL = NULL;//��һ��һ��Ҫ�У����û����һ���Ǻܿ��µġ�
	//ʵ������� pL �ǲ��ᱻʹ�õģ����������д���� pL ������ʱ��pL->next �ǲ�ȷ���ġ�

	pL = Insert(3, 1, pL);
	pL = Insert(2, 1, pL);
	pL = Insert(1, 1, pL);
	Print(pL);
	if ((test = Find(1, pL)) != NULL) {
		printf("Find(1, pL) = %d\n", test->data);
	}
	pL = Delete(1, pL);
	Print(pL);
	if ((test = FindKth(1, pL)) != NULL) {
		printf("FindKth(1, pL) = %d\n", test->data);
	}

	pL = Delete(1, pL);
	Delete(1, pL);

	return 0;
}


int Length(pList pL) {

	int length = 0;
	pList p = pL;

	assert(pL != NULL);

	while (p) {
		p = p->next;
		length++;
	}

	return length;
}

pList FindKth(int pst, pList pL) {

	int i = 1;
	pList p = pL;

	assert(pL != NULL);

	while (i < pst && p != NULL) {
		i++;
		p = p->next;
	}

	if (i == pst) {
		return p;
	}
	else {
		printf("����û�����Ϊ %d Ԫ��\n", pst);
		return NULL;
	}

	////����� if else ������д��������
	//if (p == NULL)
	//	return NULL;
	//else
	//	return p;
	////��ʱ����ġ�
	////�������� pst = -1����ʱ i > pst ���� while ѭ����
	////���� p��= NULL��Ȼ����� pL Ҳ���Ǳ�ͷ��

}

pList Find(int trg, pList pL) {

	pList p = pL;

	assert(pL != NULL);

	while ((p->data != trg) && (p != NULL)) {
		p = p->next;
	}
	if (p == NULL) {
		printf("����û���� %d\n", trg);
		return NULL;
	}

	return p;
}

pList Insert(int add_num, int pst, pList pL) {

	// pst ��ʾ���������е� pst ���ڵ�
	// ��� pst == 3����ʾ���ڵ��������ĵ� 3 λ�������Ǿ���Ҫ���ҵ�ǰһ����pst - 1���ڵ㣬Ҳ���ǵڶ����ڵ�
	// ��� pst == 1����ʾ���ڵ��������ĵ� 1 λ��������ʱ��û��ǰһ���ڵ��ˣ���ʱ�����Ҫ���⴦��
	pList last, p;

	if (pst == 1) {
		p = (pList)malloc(sizeof(List));
		if (p != NULL) {
			p->data = add_num;
			p->next = pL;
			return p;
		}
		else {
			printf("����ʧ�ܣ��ڴ�����ʧ�ܣ�\n");
			return NULL;
		}
	}

	last = FindKth(pst - 1, pL); // Ѱ�� pst ��һ���ڵ�

	if (last == NULL) {
		printf("����ʧ�ܣ��� %d ���ڵ㲻����\n", pst - 1);
		return NULL;
	}
	else {
		p = (pList)malloc(sizeof(List));
		if (p != NULL) {
			p->next = last->next;
			p->data = add_num;
			last->next = p;
			return pL;
		}
		else {
			printf("����ʧ�ܣ��ڴ�����ʧ�ܣ�\n");
			return NULL;
		}
	}

}

pList Delete(int pst, pList pL) {

	pList last, Next;

	assert(pL != NULL);

	if (pst == 1) {
		Next = pL->next;
		free(pL);
		return Next;
	}

	last = FindKth(pst, pL);
	if (last == NULL) {
		printf("�� %d ���ڵ�ɾ��ʧ�ܣ��� %d ���ڵ㲻����\n", pst, pst - 1);
		return NULL;
	}
	else if (last->next == NULL) {
		printf("�� %d ���ڵ�ɾ��ʧ�ܣ��� %d ���ڵ㲻����\n", pst, pst);
		return NULL;
	}
	Next = last->next;
	last->next = Next->next;
	free(Next);

	return pL;
}

void Print(pList pL) {

	assert(pL != NULL);

	printf("��ӡ����\n");
	pList p = pL;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}
