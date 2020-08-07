#define _CRT_SECURE_NO_WARNINGS 1

typedef struct {
	HuffmanTree* Element[100]; 
	//�ѵĽ������ݽṹ�����鷽������ʵ�֣�������Ϊ��Щ����Ժ���ɹ���������һ���֣�
	//���ԣ������Ԫ����Ҫ�� HuffmanTree ��ָ�����ͣ������������� malloc �����ģ�
	// ��ǰ����Ԫ�ص�ֵ Element[i] ��ŵ� Element[i]->Weight ��
	int size;
	int capacity;
}MinHeap;


typedef struct {
	int Weight;
	HuffmanTree *Left, *Right;
}HuffmanTree;



HuffmanTree* huffman(MinHeap* H) {
	int i;
	HuffmanTree* T;
	buildMinHeap(H);// ����Ȩֵ������С��

	// ֻ��Ҫ�ഴ�� H->size - 1 ��㼴��
	for (i = 1; i < H->size; i++) {
		T = malloc(sizeof(HuffmanTree));
		T->Left = deleteHeap(H);
		T->Right = deleteHeap(H);
		T->Weight = T->Left->Weight + T->Right->Weight;

		Insert(H, T); // ���µĽ����뵽��С����
	}

	// ���� size - 1 ��ѭ������С����ֻʣһ��Ԫ�أ�������ͷ

	T = deleteHeap(H);
	return T;
}



