#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef int ElementType;

typedef struct {
	ElementType data;
	BinTree* Left; // ������
	BinTree* Right; // ������
}BinTree;

typedef struct {
	BinTree* node;
	BinTree* next;
}Node;

typedef struct Queue
{
	Node* front;
	Node* rear;
	int size;
}Queue;


Queue* createQueue() {

	Queue* queue = (Queue*)malloc(sizeof(Queue));

	queue->front = queue->rear = NULL;
	queue->size = 0;

	return queue;
}

Node* createNode(BinTree* BT) {
	
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->node = BT;
	new_node->next = NULL;

	return new_node;
}

void queuePush(Queue* Q, BinTree* BT) {

	Node* new_node = createNode(BT);

	if (queueIsEmpty(Q)) {
		Q->front = Q->rear = new_node;
	}
	else {
		Q->rear->next = new_node;
		Q->rear = new_node;
	}

	Q->size++;
}

BinTree* queuePop(Queue* Q) {

	if (!queueIsEmpty(Q)) {
		Node* node_pop = Q->front;
		BinTree* ret = node_pop->node;
		
		Q->front = Q->front->next;
		free(node_pop);

		if (Q->front == NULL)
			Q->rear = NULL;

		Q->size--;

		return ret;
	}

	return NULL;
}

bool queueIsEmpty(Queue* Q) {
	
	return Q->size == 0;
}

void levelOrderTraversal(BinTree* BT) {
	
	if (BT == NULL)/* ���ǿ�����ֱ�ӷ��� */
		return;

	BinTree* B;
	Queue* Q = createQueue();/*��������ʼ������Q*/
	queuePush(Q, BT);
	
	while (!queueIsEmpty(Q)) {
		B = queuePop(Q);/*����ȡ�����еĽ��*/
		printf("%d ", B->data);
		if(B->Left)
			queuePush(Q, B->Left);
		if(B->Right)
			queuePush(Q, B->Right);
	}
}
