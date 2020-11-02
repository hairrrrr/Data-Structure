#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdbool.h>

typedef int DataType;

typedef struct Node
{
	struct Node* next;
	DataType data;
}Node;

typedef struct Queue
{
	Node* front;
	Node* rear;
	int size;
}Queue;

void queueInit(Queue* q);
// �������н��
Node* creatNode(DataType data);
// ���
void queuePush(Queue* q, DataType data);
// ����
DataType queuePop(Queue* q);
// �п�
bool queueIsEmpty(Queue* q);
// ����
void queueDestory(Queue* q);

#endif 