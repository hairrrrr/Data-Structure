/**********************************************************************************************
*	heap.c��
*			�ѵĽ��������룬ɾ����Ҫǣ���Զѵ��ع��������Ѻ���С�ѵ��ع���ʽ�ǲ�ͬ�ġ�
*			�������Ϊ���Ѻ���С�Ѷ�����ͬ���Ľӿڣ��ᷢ�֣���ʵ�ܶ���붼���ظ��ġ�
*			�ⲻ�������������Ƶ�˼�롪�����á�
*			
*			��ˣ������Ƚϣ��ҷ������Ѻ���С�ѵ�����ֻ���ڱȽ������ڵ��ֵ
*			�����ӽڵ�͸��ڵ㣬����Ӻ��Ҷ��ӣ���������������һ������ָ�����飬
*			�ֱ�ָ�������ֱȽϺ�����ֻ��Ҫ�û�����ͷ�ļ��ж���ĺ� MINHEAP �� MAXHEAP ��
*			����ʵ����ͬ�Ĵ�����ɶԶѵĲ�ͬ������ͬʱ���û���������ڲ���ʵ�֣�Ҳ�����˷�װ�����ʡ�
*			
*			������и��õ����˼·����ӭ�����ң��һ���������֪�Ƽ���
**********************************************************************************************/

#include"heap.h"

#define PUBLIC 
#define PRIVATE static

// ��С�ѵıȽϺ���
int cmp_min(HPDataType data1, HPDataType data2)
{
	return data1 < data2;
}

// ���ѵıȽϺ���
int cmp_max(HPDataType data1, HPDataType data2)
{
	return data1 > data2;
}

PRIVATE void Swap(HPDataType* array, int child, int parent)
{
	HPDataType tmp = array[child];
	array[child] = array[parent];
	array[parent] = tmp;
}

// ������һ������ָ�����飬��ԱΪ��С�ѱȽϺ��������ѱȽϺ���
int (*cmp[2])(HPDataType child, HPDataType parent) = {cmp_min, cmp_max};


PRIVATE void shiftDown(HPDataType* array, int size, int parent, int flg)
{
	int child = 2 * parent + 1;

	while (child < size)
	{
		if (child + 1 < size && cmp[flg](array[child + 1], array[child]))
			child++;
		
		// ���ñȽϺ���
		if (cmp[flg](array[child], array[parent]))
		{
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

PRIVATE void shiftUp(HPDataType* array, int child, int flg)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (cmp[flg](array[child], array[parent]))
		{
			Swap(array, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}


/************************* �ӿں��� *************************/


void heapCreat(Heap* hp, HPDataType* array, int size, int flg)
{
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	memcpy(hp->_array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	hp->_capacity = MAX_HEAP;

	// �ӵ�һ����Ҷ�ӽ�㿪ʼ����
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(hp->_array, hp->_size, parent, flg);
	}
}

void heapPush(Heap* hp, HPDataType data, int flg)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;

		HPDataType* new_arr = (HPDataType*)realloc(hp->_array, hp->_capacity * sizeof(HPDataType));
		
		// ֱ�Ӱ� realloc �ķ���ֵ���� hp->_array����� realloc ʧ�ܣ����ܻ�����ڴ�й©
		if (new_arr == NULL) 
		{
			printf("realloc failed in %s : %s %d\n", __func__, __FILE__, __LINE__);
			free(hp->_array);
			exit(EXIT_FAILURE);
		}
		hp->_array = new_arr;
	}

	hp->_array[hp->_size++] = data;

	shiftUp(hp->_array, hp->_size - 1, flg);
}


HPDataType heapPop(Heap* hp, int flg) {
	
	if (hp->_size <= 0)
	{
		printf("%s failed: heap is empty\n", __func__);
		exit(EXIT_FAILURE);
	}

	HPDataType ret = hp->_array[0];
	hp->_array[0] = hp->_array[--hp->_size];

	shiftDown(hp->_array, hp->_size, 0, flg);

	return ret;
}

void heapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}

	printf("\n");
}

