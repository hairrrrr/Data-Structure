#define _CRT_SECURE_NO_WARNINGS 1

//��������������һ������ʵ��������ջ��Ҫ��������������ռ䣬ʹ������ֻҪ�пռ���ջ�����Ϳ��Գɹ���

//˼·��������ջ�ֱ���������˿�ʼ�������м���������������ջ��ջ����Ӧ�������±�֮��Ϊ 1 ʱ����ʾ������ջջ����������ջ����

#include<stdio.h>

#define MAXSIZE 100
#define ERROR NULL;

typedef int ElementType;

typedef struct TNode {
	ElementType Data[MAXSIZE];
	int Top1; // ջ1 ��ջ������Ԫ�ص��±���ջʱ Top == -1
	int Top2; // ջ2 ��ջʱ Top == MAXSIZE  
}TNode;

typedef struct TNode* TStack;

void Push(TStack PtrS, ElementType item, int Tag);// ѹջ
ElementType Pop(TStack PtrS);// ��ջ

int main(void) {
	
	return 0;
}

void Push(TStack PtrS, ElementType item, int Tag) {

	// �ж�ջ�Ƿ���
	if (PtrS->Top2 - PtrS->Top1 == 1) {
		printf("��ջ��\n");
		return;
	}
	// Tag == 1 ��ʾ����� ջ1 
	if (Tag == 1) {
		PtrS->Data[++(PtrS->Top1)] = item;
	}
	else {
		PtrS->Data[--(PtrS->Top2)] = item;
	}
}

ElementType Pop(TStack PtrS, int Tag) {
	
	if (Tag == 1) {
		if (PtrS->Top1 == -1) {
			printf("��ջ��!");
			return ERROR;
		}
		else {
			return PtrS->Data[(PtrS->Top1)--];
		}
	}
	else {
		if (PtrS->Top1 == MAXSIZE) {
			printf("��ջ��!");
			return ERROR;
		}
		else {
			return PtrS->Data[(PtrS->Top1)++];
		}
	}
}

