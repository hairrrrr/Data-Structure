#pragma once
#include<iostream>
#include<ctime>
#include"Queue.hpp"
#include"Stack.hpp"

using std::cin;
using std::cout;
using std::endl;

struct Bus
{
	size_t num;
	time_t in_time;
	
	Bus() = default;

	Bus(size_t _num)
		:num(_num)
	{}

	bool operator==(Bus& bus)
	{
		this->num == bus.num;
	}
};

class Park
{
private:
	// �Ʒѹ���3 �� 15 Ԫ������ 3 �밴 3 ����
	enum {FEE = 15, PARK_CAPACITY = 5};
	Stack<Bus> _in;
	Stack<Bus> _out;
	Queue<Bus> _wait;

public:
	Park()
		:_in(PARK_CAPACITY)
		,_out(PARK_CAPACITY)
	{}

	// ͣ��
	void park(size_t num)
	{
		// ͣ������
		Bus bus;
		bus.num = num;
		if (_in.size() == PARK_CAPACITY)
		{
			_wait.push(bus);
		}
		else
		{
			bus.in_time = time(NULL);
			_in.push(bus);
		}
	}

	// ȡ�����Ʒ�
	void unpark(size_t num)
	{
		// 1. ȡ��
		Bus cur;
		while (!_in.empty())
		{
			cur = _in.top();
			_in.pop();
			if (num == cur.num)
				break;
			_out.push(cur);
		}
		// 2. �Ʒ�
		if (num == cur.num)
		{
			time_t all_time = time(NULL) - cur.in_time;
			int fee;
			if (all_time % 3 == 0)
				fee = all_time / 3 * FEE;
			else
				// ���� 3 �밴 3 ����
				fee = (all_time / 3 + 1) * FEE;
			cout << "���Ϊ " << cur.num << " �ĳ�ͣ�� "
				<< all_time << " �룬" << "�շ� "
				<< fee << " Ԫ" << endl;
		}
		else
			cout << "���Ϊ " << num << " �ĳ�������" << endl;

		// 3. ����ĳ����½���ͣ����
		while (!_out.empty())
		{
			_in.push(_out.top());
			_out.pop();
		}

		// 4. ����ȴ��ĳ�����ͣ����
		if (!_wait.empty())
		{
			cur = _wait.front();
			_wait.pop();
			park(cur.num);
		}
	}

};


