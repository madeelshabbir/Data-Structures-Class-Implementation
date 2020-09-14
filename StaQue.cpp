#include<iostream>
using namespace std;
template <typename Object>
class StaQueADT
{
public:
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual long size() const = 0;
	virtual void insert(const Object &o) = 0;
	virtual Object first() const = 0;
	virtual Object last() const = 0;
	virtual Object removeFirst() = 0;
	virtual Object removeLast() = 0;
};
template <typename Object>
class StaQue : public StaQueADT<Object>
{
private:
	Object* data;
	long tsize;
	long rear;
	long front;
	long pos;
	void createStaQue(long s)
	{
		data = new Object[s];
		tsize = s;
		rear = 0;
		front = 0;
		pos = 0;
	}
public:
	StaQue()
	{
		createStaQue(100);
	}
	StaQue(long s)
	{
		createStaQue(s);
	}
	~StaQue()
	{
		delete[] data;
		data = NULL;
	}
	bool isEmpty() const
	{
		return pos == 0;
	}
	bool isFull() const
	{
		return pos == tsize;
	}
	long size() const
	{
		return pos;
	}
	void insert(const Object &o)
	{
		if (isFull())
		{
			throw 0;
		}
		rear %= tsize;
		data[rear++] = o;
		pos++;
	}
	Object first()
	{
		if (isEmpty())
		{
			throw 0;
		}
		front %= tsize;
		return data[front];
	}
	Object last()
	{
		if (isEmpty())
		{
			throw 0;
		}
		if (rear == 0)
		{
			return data[tsize - 1];
		}
		return data[rare - 1];
	}
	Object removeFirst()
	{
		if (isEmpty())
		{
			throw 0;
		}
		front %= tsize;
		pos--;
		return data[front++];
	}
	Object removeLast()
	{
		if (isEmpty())
		{
			throw 0;
		}
		pos--;
		if(rear == 0)
		{
			rear = tsize - 1;
		}
		else
		{
			--rear;
		}
		return data[rear];
	}
};
int main()
{
	StaQueADT<int>* sq = new StaQue<int>(5);
	sq->insert(1);
	sq->insert(2);
	sq->insert(3);
	sq->insert(4);
	sq->insert(5);
	cout << sq->removeFirst() << endl;
	sq->insert(6);
	cout << sq->removeLast() << endl;
	cout << sq->removeLast() << endl;
	system("pause");
}