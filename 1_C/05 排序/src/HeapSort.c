#include"sort.h"

/************************************************************************
*	heapSort:
*		ʱ�临�Ӷȣ�O(nlogn)
*		�ռ临�Ӷȣ�O(1)
*		�ȶ��ԣ����ȶ�  --> �����Ĺ��������λ�ÿ��ܻᷢ���仯
*		�������У�������
*************************************************************************/

// �������
void shiftDown(int* array, int size, int parent)
{	
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child + 1] > array[child])
			child++;
		
		if (array[child] > array[parent])
		{
			swap(array, child, parent);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
			
	}
}

void heapSort(int* array, int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		shiftDown(array, size, i);
	}

	// ѭ�� size - 1 ��
	while (size > 1)
	{
		swap(array, 0, size - 1);
		size--;
		shiftDown(array, size, 0);
	}
}