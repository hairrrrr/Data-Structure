#define _CRT_SECURE_NO_WARNINGS 1

// ��ʽ�洢�ĺ��ľ��� Push �� Pop ����Ӧ�ô��������һ�˽���
// �����ǴӼ򻯳����滹�� ��ջ�ġ��������������濼�����Ƕ�Ӧ��ѡ��ӱ�ͷ����

#include<stdio.h>
#include<stdlib.h>

#define ERROR NULL;

typedef int ElementType;

typedef struct Node {
	ElementType Data;
	struct Node* Next;
}Node;

typedef Node* Stack;

int isEmpty(Stack S);
Stack CreatStack();
void Push(Stack S, ElementType item);
ElementType Pop(Stack S) {
	
	ElementType elem;

	if (isEmpty(S)) {
		printf("��ջ�գ�\n");
		return ERROR;
	}
	else {
		// ������ɾ��ͷ�ڵ�Ĳ���
		Stack pop = S->Next;
		elem = pop->Data;
		S->Next = pop->Next;
		free(pop);
		return elem;
	}
}

int main(void) {

	return 0;
}

int isEmpty(Stack S) {
	// �ǿձ��� 1�����Ƿ��� 0
	return (S->Next == NULL);
}

Stack CreatStack() {

	Stack S = (Stack)malloc(sizeof(Node));
	S->Next = NULL;// �мǲ�Ҫ������һ����
	return S;
}

void Push(Stack S, ElementType item) {
	
	//���������ж϶�ջ�Ƿ����

	Stack new = (Stack)malloc(sizeof(Node));
	new->Next = S->Next;
	new->Data = item;
	S->Next = new;
}

