/************************************************************************************
*	heap.h��
*		��Ҫ�����ѵ����Ͷ��壬һЩ�꣬���ĸ��ӿں���
*		����������һ����װ������ʹ�ò���ȫ���ͣ����ѵ����Ͷ���Ӧ�÷��ڣ�heap.c �У�
************************************************************************************/

#ifndef _HEAP_H_
#define _HEAP_H_

#include<stdlib.h>
#include <memory.h>
#include<stdio.h>

#define MAX_HEAP 100 // �ѵ��������
#define MINHEAP 0 // ��С�ѵı��
#define MAXHEAP 1 // ���ѵı��


typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
}Heap;



/******************** �ӿں��� *******************/

void heapCreat(Heap* hp, HPDataType* array, int size, int flg);

void heapPush(Heap* hp, HPDataType data, int flg);

HPDataType heapPop(Heap* hp, int flg);

void heapPrint(Heap* hp);


#endif 