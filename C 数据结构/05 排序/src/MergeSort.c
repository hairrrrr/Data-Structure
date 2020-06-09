#include"sort.h"

/***************************************
*	mergeSort:
*		ʱ�临�Ӷȣ�O(nlogn)
*		�ռ临�Ӷȣ�O(n)
*		�ȶ����ȶ�
*		�������У�������
****************************************/

#include<stdlib.h>
#include<string.h>

void merge(int* array, int* tmp, int begin, int mid, int end)
{
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int idx = begin;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1] <= array[begin2])
			tmp[idx++] = array[begin1++];
		else
			tmp[idx++] = array[begin2++];
	}
	//�鿴�Ƿ���ʣ��Ԫ��
	if (begin1 <= end1)
		memcpy(tmp + idx, array + begin1, sizeof(int) * (end1 - begin1 + 1));
	if(begin2 <= end2)
		memcpy(tmp + idx, array + begin2, sizeof(int) * (end2 - begin2 + 1));
	//������ԭʼ�ռ�
	memcpy(array + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void divideR(int* array, int* tmp, int begin, int end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;

	// �֣����ȱ�֤�������������������������
	divideR(array, tmp, begin, mid);
	divideR(array, tmp, mid + 1, end);
	
	// �Σ��ϲ�����������
	merge(array, tmp, begin, mid, end);
}

void divideNoR(int* array, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	//���ϲ������Ԫ�ظ���
	int k = 1;
	//���ֵĹ鲢
	while (k < n)
	{
		//һ�ֹ鲢
		for (int i = 0; i < n; i += 2 * k)
		{
			//[begin, mid]  [mid + 1, end]
			int begin = i;

			int mid = i + k - 1;
			//�ж�mid�Ƿ�Խ��
			if (mid >= n - 1)
				continue;

			int end = i + 2 * k - 1;
			//�ж�end�Ƿ�Խ��
			if (end >= n)
				end = n - 1;
			merge(array, begin, mid, end, tmp);
		}
		k *= 2;
	}
}

void mergeSort(int* array, int size)
{
	int* tmp = (int*)malloc(sizeof(int) * size);
	divideR(array, tmp, 0, size - 1);
	free(tmp);
}