#pragma once
#include<iostream>
#include<queue>

using std::cin;
using std::cout;
using std::endl;

template<class T>
struct BSTNode
{
	T _val;
	BSTNode* _left;
	BSTNode* _right;

	BSTNode(const T val)
		:_val(val)
		,_left(nullptr)
		,_right(nullptr)
	{}
};

template<class T>
class BST
{
	typedef BSTNode<T> Node;
private:
	Node* _tree;
public:
	BST()
		:_tree(nullptr)
	{}
	
	~BST() 
	{ 
		destory(_tree);
	}
	
	// ����
	Node* search(const T& val)
	{
		// non-const ��Ա�������� const ��Ա����
		return const_cast<Node*>(
			static_cast<const BST<T>*>(this)->search(val) );
	}

	const Node* search(const T& val) const
	{
		return Search(_tree, val);
	}

	// ����
	bool insert(const T& val)
	{
		Node* cur = _tree;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_val == val)
				return false;
			else if (cur->_val > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		Node* node = new Node(val);
		// ��Ϊ����
		if (parent == nullptr)
			_tree = node;
		else if (parent->_val > val)
			parent->_left = node;
		else
			parent->_right = node;
		return true;
	}

	bool erase(const T& val)
	{
		Node* father;
		Node* del = find(val, &father);
		if (!del)
		{
			cout << "ֵΪ " << val << " �Ľڵ㲻���ڣ�ɾ��ʧ��" << endl;
			return false;
		}

		// cur Ϊ�滻ɾ���ڵ�Ľڵ㣬fa Ϊ�丸�ڵ�
		Node* fa = del, * cur;
		// 1. �����ɾ���ڵ��������������ڣ������������ҽڵ��������������ڵ㶼�����滻�˽ڵ�
		// ѡ���������������ҽڵ�
		if (del->_left && del->_right)
		{
			// cur �ߵ�������
			cur = del->_left;
			while (cur->_right)
			{
				fa = cur;
				cur = cur->_right;
			}
			// �滻�ڵ㲻�Ǵ�ɾ���ڵ����ڵ�ʱ
			if (cur != del->_left)
			{
				fa->_right = cur->_left;
				cur->_left = del->_left;
			}

			cur->_right = del->_right;
		}
		// 2. ֻ��������
		else if (del->_left)
		{
			cur = del->_left;
			while (cur->_right)
			{
				fa = cur;
				cur = cur->_right;
			}
			// �滻�ڵ㲻�Ǵ�ɾ���ڵ����ڵ�ʱ
			if (cur != del->_left)
			{
				fa->_right = cur->_left;
				cur->_left = del->_left;
			}

		}
		// 3. ֻ��������
		else if (del->_right)
		{
			cur = del->_right;
			while (cur->_left)
			{
				fa = cur;
				cur = cur->_left;
			}
			// �滻�ڵ㲻�Ǵ�ɾ���ڵ���ҽڵ�ʱ
			if (cur != del->_right)
			{
				fa->_left = cur->_right;
				cur->_right = del->_right;
			}
		}
		// ��ɾ���ڵ�ΪҶ�ڵ�
		else
			cur = nullptr;
		
		// father �ǿ�ָ�룬��ɾ���Ľڵ������ĸ��ڵ�
		if (!father)
			_tree = cur;
		else
		{
			if (father->_left == del)
				father->_left = cur;
			else
				father->_right = cur;
		}
		delete del;
	}

	// �Ż���� erase
	//bool erase(const T& val) 
	//{
	//	Node* del = nullptr, *pdel = nullptr;
	//	Node* cur = _tree;
	//	while (cur)
	//	{
	//		if (cur->_val == val)
	//		{
	//			del = cur;
	//			break;
	//		}
	//		else if (cur->_val > val)
	//		{
	//			pdel = cur;
	//			cur = cur->_left;
	//		}
	//		else
	//		{
	//			pdel = cur;
	//			cur = cur->_right;
	//		}
	//	}
	//	
	//	if (del == nullptr) return false;

	//	// 1. del ΪҶ�ڵ�
	//	if (!del->_left && !del->_right)
	//	{
	//		if (pdel == nullptr)
	//			_tree = nullptr;
	//		else
	//		{
	//			if (pdel->_left == del)
	//				pdel->_left = nullptr;
	//			else
	//				pdel->_right = nullptr;
	//		}
	//		delete del;
	//	}
	//	// 2. del ������Ϊ��
	//	else if (!del->_left)
	//	{
	//		if (pdel == nullptr)
	//			_tree = _tree->_right;
	//		else
	//		{
	//			if (pdel->_left == del)
	//				pdel->_left = del->_right;
	//			else
	//				pdel->_right = del->_right;
	//		}
	//		delete del;
	//	}
	//	// 3. del ������Ϊ��
	//	else if (!del->_right)
	//	{
	//		if (pdel == nullptr)
	//			_tree = _tree->_left;
	//		else
	//		{
	//			if (pdel->_left == del)
	//				pdel->_left = del->_left;
	//			else
	//				pdel->_right = del->_left;
	//		}
	//		delete del;
	//	}
	//	// 4. del ������������Ϊ��
	//	else
	//	{
	//		// �ҵ������������ҽڵ�
	//		Node* cur = del->_left;
	//		Node* pcur = del;
	//		while (cur->_right)
	//		{
	//			pcur = cur;
	//			cur = cur->_right;
	//		}
	//		del->_val = cur->_val;
	//		if (pcur == del)
	//			pcur->_left = cur->_left;
	//		else
	//			pcur->_right = cur->_left;

	//		delete cur;
	//	}
	//	return true;
	//}

	// �������չʾ������
	void show() const
	{
		// delim ָʾ��������ǰ���������ʱ����������з�
		Node delim(0); //delimiter
		std::queue<Node*> Q;
		
		Q.push(_tree);
		Q.push(&delim);
		while (!Q.empty())
		{
			Node* front = Q.front();
			// ��ʱ�����н�ʣ�� delim��������������ɣ��˳�ѭ��
			if (front == &delim)
				break;
			Q.pop();
			if (front)
			{
				cout << front->_val << " ";
				Q.push(front->_left);
				Q.push(front->_right);
			}
			else
				cout << "NULL ";
			// �����ʱ��ͷ�� delim����ǰ�������ɾ�� delim ���ڶ�β��� delim 
			if (Q.front() == &delim)
			{
				cout << endl;
				Q.pop();
				Q.push(&delim);
			}
		}
	}

private:
	const Node* Search(Node* _tree, const T& val) const
	{
		if (_tree == nullptr || _tree->_val == val)
			return _tree;
		else if (_tree->_val > val)
			return Search(_tree->_left, val);
		else
			return Search(_tree->_right, val);
	}

	// �������ɾ���ڵ�
	void destory(Node* _tree)
	{
		if (_tree)
		{
			destory(_tree->_left);
			destory(_tree->_right);
			delete _tree;
		}
	}

	Node* find(const T& val, Node** father)
	{
		Node* cur = _tree;
		Node* fa = nullptr;
		while (cur)
		{
			if (cur->_val == val)
			{
				// ����Ŀ��ڵ�ĵĸ��ڵ㣬���Ŀ��ڵ�Ϊ���ڵ㣬���ڵ�Ϊ��
				*father = fa;
				return cur;
			}
			else if (cur->_val > val)
			{
				// ���¸��ڵ�
				fa = cur;
				cur = cur->_left;
			}
			else
			{
				fa = cur;
				cur = cur->_right;
			}
		}
		return nullptr;
	}
};
