#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

//
//typedef int ElementType;
//
//typedef struct {
//	ElementType data;
//	BinTree* Left; // ������
//	BinTree* Right; // ������
//}BinTree;
//
//
//// �ݹ�ʵ��
////BinTree* Find(ElementType x, BinTree* BST) {
////
////	if (!BST)
////		return NULL;
////
////	if (x < BST->data)
////		return Find(x, BST->Left);
////
////	else if (x > BST->data)
////		return Find(x, BST->Right);
////
////	else
////		return BST;
////}
//
//
//// ѭ��ʵ��
//BinTree* Find(ElementType x, BinTree* BST) {
//
//	while (BST) {
//
//		if (x < BST->data)
//			BST = BST->Left;
//		else if (x > BST->data)
//			BST = BST->Right;
//		else
//			return BST;
//	}
//
//	return NULL;
//}
//
//// �ݹ�
//BinTree* findMax(BinTree* BST) {
//
//	if (!BST) return NULL;
//	else if (!BST->Right)
//		return BST;
//	else
//		findMax(BST->Right);
//}
//
////ѭ��
//BinTree* FindMax(BinTree* BST) {
//
//	if (BST)
//		while (BST->Right)
//			BST = BST->Right;
//
//	return BST;
//}
//
//
//BinTree* insert(ElementType x, BinTree* BST) {
//
//	if (!BST) {
//		BST = (BinTree*)malloc(sizeof(BinTree));
//		BST->data = x;
//		BST->Left = BST->Right = NULL;
//	}
//	else {
//		if (x > BST->data)
//			BST->Right = insert(x, BST->Right);
//		else if (x < BST->data)
//			BST->Left = insert(x, BST->Left);
//	}
//
//	return BST;
//}
//
//BinTree* delete(ElementType x, BinTree* BST) {
//
//	BinTree* tmp;
//
//	if (x < BST->data)
//		BST->Left = delete(x, BST);
//	else if (x > BST->data)
//		BST->Right = delete(x, BST);
//	else {
//		// BST ������������
//		if (BST->Left && BST->Right) {
//			tmp = findMax(BST->Left);
//			BST->data = tmp->data;
//			delete(BST->data, BST->Left);
//		}
//		// BST ֻ��һ����������û������
//		else {
//			tmp = BST;
//			// ��� BST û��������һ��������һ�� if����ʱ BST ������Ϊ NULL
//			if (!BST->Left)
//				BST = BST->Right;
//			else
//				BST = BST->Right;
//			free(tmp);
//		}
//	}
//
//	return BST;
//}


// ����  �������Ƚ����е��б�
#include<limits.h>

int main(void) {

	int target, min = INT_MIN, max = INT_MAX, bound;

	printf("search: ");
	scanf("%d", &target);

	while (1) {
		printf("bound : ");
		scanf("%d", &bound);

		// Ϊ�˲����ڸ��߽縳�����ֵ֮ǰ�����������ǽ� max �� min �ֱ��� int���� �����ֵ����Сֵ
		if (bound > max || bound < min) {
			printf("illegal bound\n");
			exit(EXIT_FAILURE);
		}

		bound > target ? (max = bound) : (min = bound);
		
	}

	return 0;
}
