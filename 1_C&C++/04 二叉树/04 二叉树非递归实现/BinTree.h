#ifndef _BINTREE_H_
#define _BINTREE_H_

#include<stdbool.h>

typedef char BTDataType;

typedef struct BinTree{
	BTDataType Val;
	struct BinTree* Left;
	struct BinTree* Right;
}BinTree;

/******************* ������ʵ�� ************************/

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

/******************* ���������� ************************/

// ������ǰ��ǵݹ����
void BinaryTreePrevOrderNoR(BinTree* root);

// ������ǰ�����
void BinaryTreePrevOrder(BinTree* root);



// ����������ǵݹ����
void BinaryTreeInOrderNoR(BinTree* root);

// �������������
void BinaryTreeInOrder(BinTree* root);



// ����������ǵݹ����
void BinaryTreePostOrderNoR(BinTree* root);

// �������������
void BinaryTreePostOrder(BinTree* root);


// �������
void BinaryTreeLevelOrder(BinTree* root);


// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BinTree* root);

#endif 

