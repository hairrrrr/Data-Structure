#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 200

typedef struct List {
	
	int data[MAXSIZE];
	int last;//���һ��Ԫ�ص��±�
}List;

typedef List* pList;

pList MakeEmpty();//��ʼ��
void Input(pList pL);// ����Ԫ��
int Find(int trg, pList pL);//���ҵ�һ�γ��ֵ�λ��
void Insert(int pst, int add_num, pList pL);//����
void Delete(int pst, pList pL);//ɾ��
int FindKth(int pst, pList pL);//����λ�� pst ����Ԫ��
int Length(pList pL);// ��
void Print(pList pL);// ��ӡ��

int main(void) {

	pList pL;
	int index;

	if ((pL = MakeEmpty()) != NULL) {
		Input(pL);
		index = Find(3, pL);
		if(index != -1)
			printf("Find(3, pL) = %d\n", pL->data[index]);
		index = Find(0, pL);
		if (index != -1)
			printf("Find(0, pL) = %d\n", pL->data[index]);
		Insert(1, 0, pL);
		Print(pL);
		Delete(4, pL);
		Print(pL);
		index = FindKth(2, pL);
		if (index != -1)
			printf("FindKth(2, pL) = %d\n", pL->data[index]);
		Print(pL);
		printf("Length is %d\n", Length(pL));
	}

	return 0;
}

pList MakeEmpty() {
	pList pL;
	pL = (pList)malloc(sizeof(List));
	//��Ҫ���� malloc ����ʧ�ܵ����
	if (pL) 
		pL->last = -1;
	else {
		printf("������ʧ��\n");
		return NULL;
	}
	return pL;
}

void Input(pList pL) {

	int choice;
	int input;

	if (pL->last != -1) {
		printf("�˱��Ѿ��������ݣ��Ƿ������������룿���� 1 ���������������˳�\n");
		scanf("%d", &choice);
		if (choice != 1)
			return;
	}
	printf("��ʼ�������ݣ�����-1�˳�\n");
	do {
		scanf("%d", &input);
		if (input != -1) {
			pL->last++;
			pL->data[pL->last] = input;
		}
	} while (input != -1);
}

int Find(int trg, pList pL) {
	int i = 0;
	while (pL->data[i] != trg && i <= pL->last)
		i++;
	//�˳�ѭ�������ֿ���
	if (i > pL->last) {
		printf("û���ҵ� %d\n", trg);
		return -1;//���������û���ҵ����� -1
	}
	else
		return i;//�ҵ� target �����±�
}

void Insert(int pst, int add_num, pList pL) {

	int i;

	if (pL->last == MAXSIZE - 1) {
		printf("����\n");
		return;
	}
	// pst ָ�Ĳ��������±ꡣ���� a[3] = {1,2}
	//���뽫 0 ���뵽 ��1λ�ϣ�����1����λ�ã�����ô����� pst Ӧ���� 1 �������� 0
	//����Ҫ���Ĳ����ǽ������Ҫ�����λ�ÿ�ʼ�������������Ԫ�����Σ������һ��Ԫ�ؿ�ʼ������ƶ�һλ
	//��ʼ��λ�ö�Ӧ�������±���� pst - 1��pL->last + 1 �����������һ��Ԫ��ʵ�ʵ�λ��
	//last + 2 �ʹ������һ������Ԫ�صĺ�һλ��Ҳ���ǲ������������ 

	if (pst < 1 || pst > pL->last + 2) {
		printf("λ�ò��Ϸ�\n");
		return;
	}

	for (i = pL->last; i >= pst - 1; i--) {
		pL->data[i + 1] = pL->data[i];
	}
	pL->data[pst - 1] = add_num;
	pL->last++;
}

void Delete(int pst, pList pL) {

	int i;

	if (pL->last == -1) {
		printf("���Ѿ���һ���ձ���\n");
		return;
	}

	if (pst < 1 || pst > pL->last + 1) {
		printf("λ�ò��Ϸ�\n");
		return;
	}
	// �������ֻ��һ��Ԫ��
	if (pL->last == 0) {
		pL->last = -1;
	}

	for (i = pst; i <= pL->last; i++)
		pL->data[i - 1] = pL->data[i];

	pL->last--;
}

int FindKth(int pst, pList pL) {

	if (pst < 1 || pst > pL->last + 1) {
		printf("���Ϸ���λ��\n");
		return -1;
	}
	return pL->data[pst - 1];
}

int Length(pList pL) {

	return  pL->last + 1;
}

void Print(pList pL) {

	int i;
	printf("��ӡ���ݣ�\n");
	for (i = 0; i <= pL->last; i++) {
		printf("%d ", pL->data[i]);
	}
	printf("\n");
}




