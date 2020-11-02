#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"


BinTree* BinaryTreeCreate(BTDataType* str, int* idx) {

	// str ӦΪǰ����������
	// '#'��ʾ NULL
	// ������ 
	//    1
	//  2   3
	//4
	// Ӧ��ʾΪ 124##3##

	if (str[*idx] != '#') {
		BinTree* root = (BinTree*)malloc(sizeof(BinTree));
		root->Val = str[*idx];
		(*idx)++;
		root->Left = BinaryTreeCreate(str, idx);
		(*idx)++;
		root->Right = BinaryTreeCreate(str, idx);

		return root;
	}
	else
		return NULL;
}


// ����������
// ��Ϊ�������ͷŽ���ͬʱ�������Ϊ NULL������Ұָ������
// ��������Ҫ�޸Ķ��Ͽռ䣬Ӧ�ô��ݶ���ָ��
void BinaryTreeDestory(BinTree** root) {

	// ����ָ��ת��Ϊһ��ָ��
	BinTree* cur = *root;
	if (cur) {
		// �������ͷŸ��ڵ㣬Ӧ�������ͷ�Ҷ�ڵ㣬���ú������

		BinaryTreeDestory(&cur->Left);
		BinaryTreeDestory(&cur->Right);
		free(cur);
		cur = NULL;
	}
}


// �������ڵ����
int BinaryTreeSize(BinTree* root) {

	if (root) {
		return BinaryTreeSize(root->Left) +
			BinaryTreeSize(root->Right) + 1;
	}
	else
		return 0;
}


// �ǵݹ�ʵ�֣�
int BinaryTreeSize2(BinTree* root, int* num) {
	if (root) {
		(*num)++;
		BinaryTreeSize2(root->Left, num);
		BinaryTreeSize2(root->Right, num);
	}
}


// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BinTree* root) {

	// �ǿ���
	if (root) {
		// ��������Ϊ��
		if (!root->Left && !root->Right) {
			return 1;
		}

		return   BinaryTreeLeafSize(root->Left)
			+ BinaryTreeLeafSize(root->Right);
	}

	return 0;
}


// ��������k��ڵ����
int BinaryTreeLevelKSize(BinTree* root, int k) {

	// �������ĸ��ڵ�Ϊ��һ��
	// �������ĵ�������ڵ�һ����˵�ǵ����㣬���ڵڶ�����˵�ǵڶ��㣬���ڵ�������˵���ǵ�һ��
	// ��ˣ�����ʹ�õݹ����������

	if (root && k >= 1) {
		if (k == 1)
			return 1;

		return BinaryTreeLevelKSize(root->Left, k - 1) +
			BinaryTreeLevelKSize(root->Right, k - 1);
	}

	return 0;
}


// ����������ֵΪx�Ľڵ�
BinTree* BinaryTreeFind(BinTree* root, BTDataType x) {

	if (root == NULL)
		return NULL;

	if (root->Val = x)
		return root;

	BinTree* T = BinaryTreeFind(root->Left, x);
	if (T)
		return T;//�����������ҵ�
	return BinaryTreeFind(root->Right, x);//�����������Ľ��
}


// ������ǰ�����
void BinaryTreePrevOrder(BinTree* root);


// �������������
void BinaryTreeInOrder(BinTree* root);


// �������������
void BinaryTreePostOrder(BinTree* root);


// �������
void BinaryTreeLevelOrder(BinTree* root);


// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BinTree* root);
