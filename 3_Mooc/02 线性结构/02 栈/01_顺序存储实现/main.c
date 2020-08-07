#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#define MAXSIZE 100
#define ERROR NULL;

typedef int ElementType;

typedef struct SNode {
	ElementType Data[MAXSIZE];
	int Top; // ��ǰջ��ŵ����������±�
}SNode;

typedef struct SNode* Stack;

void Push(Stack PtrS, ElementType item);// ѹջ
ElementType Pop(Stack PtrS);// ��ջ

int main(void) {

	

	return 0;
}

void Push(Stack PtrS, ElementType item) {

	// ���Ķ�ջ Top == MAXSIZE - 1
	// �ж�ջ�Ƿ���
	if (PtrS->Top == MAXSIZE - 1) {
		printf("��ջ��\n");
		return;
	}
	else {
		PtrS->Data[++(PtrS->Top)] = item;
		return;
	}
}

ElementType Pop(Stack PtrS) {
	
	// �յĵĶ�ջ Top == -1
	// ��ջ��Ҫ�ж� ��ջ�Ƿ�Ϊ��
	if (PtrS->Top == - 1) {
		printf("��ջ��\n");
		return ERROR;// ERROR �� ElementType ������ֵ����־����
	}
	else {
		return PtrS->Data[(PtrS->Top)--];
	}
}

