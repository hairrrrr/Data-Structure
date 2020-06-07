void Swap(int* array, int left, int right)
{
	int tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}

void shiftDown(int* array, int size, int parent)
{

	int child = 2 * parent + 1;
	while (child < size)
	{

		if (child + 1 < size && array[child + 1] > array[child])
			++child;

		if (array[child] > array[parent])
		{
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

// ������
void heapSort(int* array, int size)
{
	// ����
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(array, parent, size);
	}
	

	while (size > 1)
	{	
		// ɾ������ͷɾ����Ȼ������Ԫ�ز������ڵ�
		Swap(array, 0, size - 1);
		// ���ܵĴ�С��С���൱���ǽ�����Ԫ������������õ�����
		size--;
		// ���µ����������ٴε���Ϊ����
		shiftDown(array, 0, size);

	}
}