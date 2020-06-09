#include"sort.h"
#include<stdlib.h>
#include<string.h>
/*******************************************************************
*	�������� ֻ�ʺ�С��Χ���ݣ� �����Χ�󣬿ռ临�ӶȽϸ�:
*		ʱ�临�Ӷȣ�O(max(n, ��Χ))
*		�ռ临�Ӷȣ�O(��Χ)
*		�ȶ���һ��̲���Ϊ���ȶ���(Ƿ��)
*		�������У�������
*******************************************************************/


void countSort(int* array, int size)
{
	int min = array[0], max = array[0];
	int i;

	//ͳ�Ʒ�Χ
	for (i = 0; i < size; i++)
	{
		if (array[i] < min)
			min = array[i];
		if (array[i] > max)
			max = array[i];
	}

	int count_num = max - min + 1;
	//�������ռ䣬���м���
	int* count_arr = malloc(sizeof(int) * count_num);
	//��ʼ��Ϊ0
	memset(count_arr, 0x0, sizeof(int) * count_num);

	if (!count_arr)
		exit(EXIT_FAILURE);
	
	//ͳ�ƴ���
	for (i = 0; i < size; i++)
	{
		count_arr[array[i] - min]++;
	}

	//�ָ����ݣ� ������������
	int idx = 0;
	for (i = 0; i < count_num; i++)
	{
		while (count_arr[i]--)
		{
			array[idx++] = i + min;
		}
	}

	free(count_arr);
}