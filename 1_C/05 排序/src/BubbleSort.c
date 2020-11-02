#include"sort.h"

/***************************************************************
*	bubbleSort:
*		ʱ�临�Ӷȣ��O(n^2) ƽ��O(n^2)  ���O(n)
*		�ռ临�Ӷȣ�O(1)
*		�ȶ��ԣ��ȶ�
*		�������У�����
***************************************************************/

void bubbleSort(int* array, int size)
{	
	for (int i = 0; i < size - 1; i++)
	{
		int flg = 1;

		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				flg = 0;
			}
				
		}
		if (flg)
			break;
	}
}