
/************************************************************************
*	ֱ��ѡ������:
*			ʱ�临�Ӷȣ��O(n^2) ƽ��O(n^2)  ���O(n^2)
*			�ռ临�Ӷȣ�O(1)
*			�ȶ��ԣ��ȶ�
*			�������У�������
*************************************************************************/

void selectSort(int* array, int size)
{	
	// ���ܶ���ð�������ǲ���������˵��size Ϊ n �����飬ֻ��Ҫ�� n - 1 �˼���
	// ��Ϊ���һ������ֻʣ��һ������δ�������������
	for (int i = 0; i < size - 1; i++)
	{
		// ȡ��δ���������еĵ�һ��Ԫ��
		int start = i;
		// �Ƚ���Ԫ�ؼ���Ϊδ�����������Сֵ
		int min = start;

		for (int j = start + 1; j < size; j++)
		{
			min = array[j] < array[min] ? j : min;
		}

		if (min != start)
		{
			swap(array, start, min);
		}
	}
}


// �Ż���ѡ������
void selectSortOp(int* array, int size)
{
	int begin = 0, end = size - 1;

	while (begin < end)
	{
		int min = begin, max = begin;
		
		for (int i = begin + 1; i <= end; i++)
		{
			if (array[i] < array[min])
			{
				min = i;
			}
			
			// ���ӵ��ںûᵼ�������ȶ�����Ϊ��� begin �����ģ������ỻ�����
			// �� begin �� end ֮��������� begin ��С��ͬ��Ԫ��
			if (array[i] >= array[max])
			{
				max = i;
			}
		}

		swap(array, begin, min);
		// ������Ԫ���±�Ϊ begin����ô��һ�� swap ��ԭ�������ֵ���������� min �±��λ����
		if (max == begin)
		{
			max = min;
		}
		swap(array, end, max);

		begin++, end--;
	}
}