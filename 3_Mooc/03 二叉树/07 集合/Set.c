#define MAXSIZE 10 // ����S����󳤶�

typedef int ElementType;

typedef struct {
	ElementType Data;
	int Parent;
}SetType;


/* ������S�в���ֵΪX��Ԫ�������ļ��� */
int setFind(SetType S[], ElementType X) {
	
	int i;

	for (i = 0; i < MAXSIZE && S[i].Data != X; i++)
		;

	/* δ�ҵ�X������-1 */
	if (i >= MAXSIZE) return -1; 

	// ��� i �±��Ӧ������Ԫ�ز��Ǹ��ڵ㣬 ����ǰ���ĸ��ڵ���±긳�� i
	for (; S[i].Parent >= 0; i = S[i].Parent) 
		;

	return i;
}

void Union(SetType S[], ElementType X1, ElementType X2) {

	int root1, root2;

	root1 = setFind(S, X1);
	root2 = setFind(S, X2);

	if (root1 == root2) return;

	S[root1].Parent = root2;
}
