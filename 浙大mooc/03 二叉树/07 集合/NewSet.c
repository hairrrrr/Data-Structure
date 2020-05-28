#define MAX_SET 10

typedef int ElementType;
typedef int SetName; /* Ĭ���ø������±���Ϊ�������� */
// SetType ����Ϊ ElementType[MAX_SET]
typedef ElementType SetType[MAX_SET]; /* ���輯��Ԫ���±��0��ʼ */

// �����ѭ�������õݹ���ʵ��
SetName setFind(SetType S, ElementType X) {
	
	if (S[X] < 0)
		return X;
	else
		setFind(S, S[X]);
}

void Union(SetType S, SetName root1, SetName root2) {
	// Ĭ�� root1 �� root2 ���������ϵĸ��ڵ�
	
	// ���� root1 �ӽڵ���� root2  
	if (S[root1] < S[root2]) {
		S[root1] += S[root2]; // ���� 2 ���뼯�� 1
		S[root2] = root1; 
	}
	else {
		S[root2] += S[root1]; // ���� 1 ���뼯�� 2
		S[root1] = root2;
	}
}
