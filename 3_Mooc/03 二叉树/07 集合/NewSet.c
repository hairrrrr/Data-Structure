#define MAXN 1000                  /* �������Ԫ�ظ��� */
typedef int ElementType;           /* Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ */
typedef int SetName;               /* Ĭ���ø������±���Ϊ�������� */
typedef ElementType SetType[MAXN]; /* ���輯��Ԫ���±��0��ʼ */
 
void Union(SetType S, SetName root1, SetName root2) {
    
	S[root1] = root2; 
}


SetName setFind(SetType S, ElementType X) {
    
	for (; S[X] >= 0; X = S[X])
		;

	return X;
}
