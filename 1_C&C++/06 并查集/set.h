#pragma once
#include<iostream>
#include<vector>

using namespace std;

template<class T>
class UnionFindSet
{
public:
	
	UnionFindSet(int size)
		:_size(size)
	{
		// ��ʼ��Ϊ -1
		_v.resize(_size, -1);
	}

	/*
	 * �ҵ�����Ԫ�صĸ�
	 */
	int FindRoot(int x)
	{
		if (x >= _size)
			return -1;

		for (; _v[x] >= 0; x = _v[x])
			;

		return x;
	}

	/*
	 * ���ϵĺϲ�
	 */
	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 == root2) return false;

		_v[root1] += _v[root2];
		_v[root2] = root1;

		return true;
	}

	/*
	 * ���㼯�ϵĸ���
	 */
	size_t Count() const
	{
		size_t count = 0;

		for (const auto& e : _v)
		{
			if(e < 0)
				count++
		}
		return count;
	}

private:
	vector<T> _v;
	int _size;
};
