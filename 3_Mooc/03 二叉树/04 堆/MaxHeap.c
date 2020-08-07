#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAXDATA 1000 /* ��ֵӦ���ݾ����������Ϊ���ڶ������п���Ԫ�ص�ֵ */
#define ERROR -1 // ��ʾ����ʧ��

typedef int ElementType;

typedef struct {
	ElementType* Data;
	int Size; // ���е�ǰԪ�ظ���
	int Capacity; // �ѵ��������
}Heap;

typedef Heap MaxHeap; // ����



MaxHeap* createHeap(int size);
void buildMaxHeap(MaxHeap* H);
void percDown(MaxHeap* H, int i);
bool heapIsFull(MaxHeap* H);
bool heapIsEmpty(MaxHeap* H);
bool heapInsert(MaxHeap* H, ElementType X);
ElementType heapDelete(MaxHeap* H);

int main(void) {
	
	int i, two_power = 2;

	MaxHeap* H = createHeap(12);

	for (i = 1; i <= H->Capacity; i++) {
		scanf("%d", &H->Data[i]);
		H->Size++;
	}

	buildMaxHeap(H);

	for (i = 1; i <= H->Capacity; i++) {
		printf("%d ", H->Data[i]);
		if (i == two_power - 1) {
			two_power *= 2;
			printf("\n");
		}
	}


	return 0;
}


MaxHeap* createHeap(int size) {
	
	MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
	
	heap->Data = (ElementType*)malloc(sizeof(ElementType) * (size + 1));
	heap->Size = 0;
	heap->Capacity = size;
	heap->Data[0] = MAXDATA;

	return heap;
}

bool heapIsFull(MaxHeap* H) {

	return H->Size == H->Capacity;
}

bool heapIsEmpty(MaxHeap* H) {

	return H->Size == 0;
}

/* ��Ԫ��X��������H������H->Data[0]�Ѿ�����Ϊ�ڱ� */
bool heapInsert(MaxHeap* H, ElementType X) {

	int i;

	if (heapIsFull(H)) {
		printf("Heap is full\n");
		return false;
	}

	i = ++H->Size;

	// ��Ϊ X �����ܴ��� Data[0]������ i ����СֵΪ 1 
	for (; H->Data[i / 2] < X; i /= 2)
		H->Data[i] = H->Data[i / 2]; // ���ˣ����ڵ��³���
	
	H->Data[i] = X; // ���� x

	return true;
}

/* ������H��ȡ����ֵΪ����Ԫ�أ���ɾ��һ����� */
ElementType heapDelete(MaxHeap* H) {
	
	int Parent, Child;
	ElementType maxItem, lastItem;

	if (heapIsEmpty(H)) {
		printf("heap is empty\n");
		return ERROR;
	}

	maxItem = H->Data[1]; /* ȡ��������ŵ����ֵ */
	
	lastItem = H->Data[H->Size--];  /* ע�⵱ǰ�ѵĹ�ģҪ��С */

	for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {

		Child = 2 * Parent;
		if ((Child != H->Size) && (H->Data[Child] < H->Data[Child + 1]))
			Child++;  /* Childָ�������ӽ��Ľϴ��� */

		if (H->Data[Child] < maxItem)
			break;

		else
			H->Data[Parent] = H->Data[Child]; // ����
	}

	H->Data[Parent] = lastItem;

	return maxItem;
	
}

void percDown(MaxHeap* H, int index_root) {

	int Parent, Child;
	ElementType val_root;

	val_root = H->Data[index_root];

	for (Parent = index_root; Parent * 2 <= H->Size; Parent = Child) {

		Child = 2 * Parent;
		if ((Child != H->Size) && (H->Data[Child] < H->Data[Child + 1]))
			Child++; 
		if (val_root > H->Data[Child]) // ������ڵ��ֵ���������ӽ�㣬�˳�
			break;

		else
			H->Data[Parent] = H->Data[Child]; // ����
	}

	H->Data[Parent] = val_root;
}


void buildMaxHeap(MaxHeap* H) {

	for (int i = H->Size / 2; i > 0; i--)
		percDown(H, i);
}

