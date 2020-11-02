#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"
#include"binTreeStack.h"
#include"binTreeQueue.h"


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


// ������ǰ��ǵݹ���� 

void BinaryTreePrevOrderNoR(BinTree* root) {

	Stack* S = (Stack*)malloc(sizeof(Stack));
	stackCreate(S, 100);
	
	BinTree* cur = root;
	while ( cur || !stackIsEmpty(S) ) {
		
		while (cur) {
			// ǰ�����
			printf("%c", cur->Val);
			// ��ǰ�����ջ
			stackPush(S, cur);
			cur = cur->Left;
		}
		// ��ȡջ��Ԫ��
		cur = stackPop(S);

		// ����������
		cur = cur->Right;
	}

}


// ������ǰ��ݹ����
// ����ջʵ��
void BinaryTreePrevOrder(BinTree* root) {

	if (root) {
		printf("%c ", root->Val);
		BinaryTreePrevOrder(root->Left);
		BinaryTreePrevOrder(root->Right);
	}
}


// ����������ǵݹ����
// ����ջʵ��
void BinaryTreeInOrderNoR(BinTree* root) {
	
	Stack* S = (Stack*)malloc(sizeof(Stack));
	stackCreate(S, 100);

	BinTree* cur = root;
	while (cur || !stackIsEmpty(S)) {

		while (cur) {
			// ��ǰ�����ջ
			stackPush(S, cur);
			cur = cur->Left;
		}
		// ��ȡջ��Ԫ��
		cur = stackPop(S);
		
		// �������
		printf("%c ", cur->Val);

		// ����������
		cur = cur->Right;
	}

}

// �������������
void BinaryTreeInOrder(BinTree* root) {
	
	if (root) {
		BinaryTreePrevOrder(root->Left);
		printf("%c ", root->Val);
		BinaryTreePrevOrder(root->Right);
	}
}


// ����������ǵݹ����
// ����ջʵ��
void BinaryTreePostOrder(BinTree* root) {

	Stack* S = (Stack*)malloc(sizeof(Stack));
	stackCreate(S, 100);

	BinTree* cur = root;
	BinTree* prev_pop;

	while (cur || !stackIsEmpty(S)) {

		while (cur) {
			// ��ǰ�����ջ
			stackPush(S, cur);
			cur = cur->Left;
		}
		// ��ȡջ��Ԫ��
		cur = stackPop(S);

		// ������Ϊ�ջ��������Ѿ����׳�
		if (cur->Right == NULL || cur->Right == prev_pop) {
			// �������
			printf("%c ", cur->Val);
			prev_pop = cur; // ����
			cur = NULL; // ��������һ��Ԫ�س�ջ�����Ǽ�������������ջ��
		}
		// ��������δ������������������ѹջ
		else {
			stackPush(S, cur);
			cur = cur->Right;
		}

		// ����������
		cur = cur->Right;
	}

}

// �������������
void BinaryTreePostOrder(BinTree* root) {
	if (root) {
		BinaryTreePrevOrder(root->Left);
		BinaryTreePrevOrder(root->Right);
		printf("%c ", root->Val);
	}
}



// �������
// ����ʵ��
void BinaryTreeLevelOrder(BinTree* root) {

	Queue* Q = createQueue();
	BinTree* T;
	
	// ���ø����
	queuePush(Q, root);

	if (!queueIsEmpty(Q)) {
		
		T = queuePop(Q);
		printf("%c ", T->Val);

		// �����ӽڵ�ǿ������
		if (T->Left)
			queuePush(Q, T->Left);
		if (T->Right)
			queuePush(Q, T->Right);
	}
}


// �ж϶������Ƿ�����ȫ������
// ͨ������������������ȫ��������ս�㶼������ҵ���������ǣ���ô�ս��ͷǿս��������һ��
bool BinaryTreeComplete(BinTree* root) {

	Queue* Q = createQueue();
	BinTree* T;

	if (root)
		queuePush(Q, root);

	while(!queueIsEmpty(Q)) {
		
		T = queuePop(Q);
		// ��ǰ���ǿգ��������ӽڵ����
		if (T) {
			queuePush(Q, T->Left);
			queuePush(Q, T->Right);
		}
		// ��ǰ���Ϊ�գ�ֹͣ���
		else
			break;
	}
	
	while (!queueIsEmpty(Q)) {
		T = queuePop(Q);
		
		// ���ַǿս�㣬������ȫ������
		if (T)
			return false;
	}

	// ���ڵ�Ϊ�ջ��߶���ʣ���Ԫ�ض�Ϊ��
	return true;
}
