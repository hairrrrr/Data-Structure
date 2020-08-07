#ifndef _BINTREE_H_
#define _BINTREE_H_

typedef char BTDataType;

typedef struct BinTree {
	BTDataType Val;
	struct BinTree* Left;
	struct BinTree* Right;
}BinTree;


BinTree* BinaryTreeCreate(BTDataType* str, int* idx);

// ����������
void BinaryTreeDestory(BinTree** root);

// �������ڵ����
int BinaryTreeSize(BinTree* root);

void BianryTreeSize2(BinTree* root, int* num);

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BinTree* root);

// ��������k��ڵ����
int BinaryTreeLevelKSize(BinTree* root, int k);

// ����������ֵΪx�Ľڵ�
BinTree* BinaryTreeFind(BinTree* root, BTDataType x);

#endif