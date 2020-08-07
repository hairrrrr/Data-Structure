#include"heap.h"

void heapCreat(Heap* hp, HPDataType* array, int size)
{
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	memcpy(hp->_array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	hp->_capacity = MAX_HEAP;

	// �ӵ�һ����Ҷ�ӽ�㿪ʼ����
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(hp->_array, hp->_size, parent);
	}
}

void insertHeap(Heap* hp, HPDataType data)
{
	if (hp->_size == hp->_capacity)
	{
		printf("Heap is full\n");
		return;
	}

	hp->_array[hp->_size++] = data;

	shiftUp(hp->_array, hp->_size - 1);
}


// ����ʱ����С�ѵ����µ���
// parent: ��ʼ������λ��
void shiftDown(HPDataType* array, int size, int parent)
{
	//����λ��
	int child = 2 * parent + 1;

	while (child < size)
	{
		//�����Һ��Ӻ�����ѡһ����С
		if (child + 1 < size && array[child + 1] < array[child])
			child++;
		
		//�͸��ڵ�Ƚ�
		if (array[child] < array[parent])
		{
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

// ���룺С�����ϵ���
// child: ����Ԫ�ص�λ��
void shiftUp(HPDataType* array, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (array[child] < array[parent])
		{
			Swap(array, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void Swap(HPDataType* array, int idx1, int idx2)
{
	HPDataType tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = tmp;
}

void heapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}

	printf("\n");
}