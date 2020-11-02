#include"sort.h"

/************************************************************************
*	quickSort:
*		ʱ�临�Ӷȣ����O(n^2) ƽ����O(nlogn) ��ã�O(nlogn)
*		�ռ临�Ӷȣ�O(logn) ���O(n^2) һ�㲻�����
*		�ȶ��ԣ����ȶ�
*		�������У�����
*************************************************************************/

// hoare ��
int partion1(int* array, int begin, int end)
{
	// ���û�׼ֵ
	int key = array[begin];
	int start = begin;

	while (begin < end)
	{	
		// �����ȴӺ���ǰ��

		// �Ӻ���ǰ�ҵ�һ���� key С��Ԫ��
		while (begin < end && array[end] >= key)
			end--;

		// ��ǰ����ҵ���һ���� key ���Ԫ��
		while (begin < end && array[begin] <= key)
			begin++;
		
		swap(array, begin, end);
	}

	// ������׼λ�ú�����λ�õ�Ԫ��
	swap(array, start, begin);

	return begin;
}

// �ڿӷ�
int partion2(int* array, int begin, int end)
{
	int key = array[begin];

	while (begin < end)
	{
		// �Ӻ���ǰ��С��
		while (begin < end && array[end] >= key)
			end--;
		array[begin] = array[end];

		// ��ǰ����Ҵ��
		while (begin < end && array[begin] <= key)
			begin++;
		array[end] = array[begin];
	}

	// �����һ���ӣ���ѭ��������begin �� end ����ȵ�
	array[begin] = key; 

	return begin;
}

int partion3(int* array, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int key = array[begin];

	while (cur <= end)
	{
		if (array[cur] < key && ++prev != cur)
		{
			swap(array, prev, cur);
		}
		++cur;
	}
	// �����һ��������ıȻ�׼ֵС��Ԫ�����׼ֵ��������׼ֵǰ�Ķ��ǱȻ�׼ֵС��Ԫ��
	swap(array, prev, begin);

	return prev;
}

int getMid(int* array, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	
	if (array[mid] < array[begin])
	{	
		//mid < begin

		// begin < end
		if (array[begin] < array[end])
			return begin;
		// begin >= end
		else
		{	
			// mid < end
			if (array[mid] < array[end])
				return end;
			else
				return mid;
		}
	}
	// mid >= begin
	else
	{
		if (array[mid] < array[end])
			return mid;
		else
		{
			if (array[end] > array[begin])
				return end;
			else
				return begin;
		}
	}
}


// Ϊ�˽���ʱ�临�Ӷ�Ϊ O(n^2) ��������ѡȡ��׼��ʱ�򣬿��Դ�ŵ��ҵ�һ���м�ֵ
int partion(int* array, int begin, int end)
{	
	int mid = getMid(array, begin, end);

	// ���ҵ��������е� mid �±��Ԫ�غ� begin ���� 
	swap(array, mid, begin);

	// ���û�׼ֵ
	int key = array[begin];
	int start = begin;

	while (begin < end)
	{
		// �����ȴӺ���ǰ��

		// �Ӻ���ǰ�ҵ�һ���� key С��Ԫ��
		while (begin < end && array[end] >= key)
			end--;

		// ��ǰ����ҵ���һ���� key ���Ԫ��
		while (begin < end && array[begin] <= key)
			begin++;

		swap(array, begin, end);
	}

	// ������׼λ�ú�����λ�õ�Ԫ��
	swap(array, start, begin);

	return begin;
}

void quickSort(int* array, int begin, int end)
{
	if (begin >= end)
		return;

	int key_pos = partion(array, begin, end);
	
	// ����������
	quickSort(array, begin, key_pos - 1);
	quickSort(array, key_pos + 1, end);
}



