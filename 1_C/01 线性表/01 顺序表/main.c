#define _CRT_SECURE_NO_WARNINGS 1

/*
 *	Data: 2023/3/27
 *  User: hairrrrr
 *  Description: Sequence list implementation.
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef int DataType;

typedef struct SeqList {

	DataType* array; // ָ��̬���ٵ�����
	size_t size; // ��Ч���ݸ���
	size_t capacity; // �����С
	
	// size_t ���� unsigned int ���ͣ�size��capacity ����������

}SeqList;

typedef SeqList* plist;

void SeqListPushBack(plist sl, DataType data); // β��
void SeqListPushFront(plist sl, DataType data); // ͷ��

void SeqListPopBack(plist sl); // βɾ
void SeqListPopFront(plist sl); // ͷɾ

void SeqListInsert(plist sl, size_t pos, DataType data); // pos λ���� x
void SeqListRemove(plist sl, size_t pos); // pos λɾ��

void SeqListInit(plist sl, size_t capacity); // ��ʼ��
void SeqListDestory(plist sl); // ����

void SeqListPrint(plist sl); // ��ӡ
void SeqListCheckCapacity(plist sl); // ���ռ��Ƿ��Ѿ�����������ˣ�������

int main(void) {

	SeqList s;
	plist sl = &s;

	SeqListInit(sl, 5);

	SeqListPushFront(sl, 1);
	SeqListPushBack(sl, 2);
	SeqListPushBack(sl, 3);
	SeqListPushBack(sl, 4);
	SeqListPushFront(sl, 0);
	
	SeqListPushFront(sl, -1);
	SeqListPushBack(sl, 5);
	// -1 0 1 2 3 4 5

	SeqListPopBack(sl);
	SeqListPopFront(sl);

	// 0 1 2 3 4

	SeqListInsert(sl, 2, 2);
	SeqListInsert(sl, 0, 0);
	SeqListInsert(sl, sl->size, 4);

	// 0 0 1 2 2 3 4 4

	SeqListRemove(sl, 0);
	SeqListRemove(sl, sl->size - 1);
	SeqListRemove(sl, 2);

	// 0 1 2 3 4

	SeqListDestory(sl);

	SeqListPrint(sl);



	return 0;
}

void SeqListInit(plist sl, size_t capacity) {

	sl->array = (DataType*)malloc(sizeof(DataType) * capacity);
	sl->capacity = capacity;
	sl->size = 0;
}

void SeqListPushBack(plist sl, DataType data) {
	
	SeqListInsert(sl, sl->size, data);
}


void SeqListPushFront(plist sl, DataType data) {

	SeqListInsert(sl, 0, data);
}

void SeqListPopBack(plist sl) {

	SeqListRemove(sl, sl->size - 1);
}

void SeqListPopFront(plist sl) {
	
	SeqListRemove(sl, 0);
}


void SeqListInsert(plist sl, size_t pos, DataType data) {

	if (pos < 0 || pos > sl->size) {
		printf("�Ƿ����±꣡");
		return;
	}
	
	SeqListCheckCapacity(sl);

	// ���������һ��Ԫ�ؿ�ʼ����ƶ�
	size_t end = sl->size;
	
	// end �� unsigned int ���ͣ��ж����������� "= 0" ��Ϊ����д���ó��������ѭ����
	// �� end == 0 ʱ�� end-- ������ end С�� 0 ֻ���� end ��� unsigned int ���Ա�ʾ�����ֵ
	while (end > pos) {
		sl->array[end] = sl->array[end - 1];// ��Ҫ��˳��д���ˣ���ǰ���ֵ������
		end--;
	}

	sl->array[pos] = data;

	++sl->size;
}

void SeqListRemove(plist sl, size_t pos) {

	if (pos >= sl->size || pos < 0) {
		printf("�Ƿ����±�!");
		return;
	}
	
	// ������� pos + 1 Ԫ�ؿ�ʼ��ǰ�ƶ�

	size_t start = pos + 1;
	
	while (start < sl->size) {
		sl->array[start - 1] = sl->array[start];
		start++;
	}
	--sl->size;
}

void SeqListCheckCapacity(plist sl) {

	if (sl->capacity <= sl->size) {
		// 2 ������
		DataType* newarr = (DataType*)malloc(sizeof(DataType) * 2 * sl->capacity);
		if (newarr != NULL) {
			memcpy(newarr, sl->array, sl->capacity * sizeof(DataType));
			free(sl->array);
			sl->array = newarr;
			sl->capacity *= 2;
		}
		else {
			printf("��������������ʧ�ܣ�");
			return;
		}
		
	}
	
}

void SeqListDestory(plist sl) {

	free(sl->array);
	sl->capacity = 0;
	sl->size = 0;
}

void SeqListPrint(plist sl) {
	
	for (size_t i = 0; i < sl->size; i++) {
		printf("%d ", sl->array[i]);
	}
}
