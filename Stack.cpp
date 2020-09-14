#include<iostream>
using namespace std;
template <typename Object>
class StackADT
{
public:
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual long sSize() const = 0;
	virtual Object peek() const = 0;
	virtual void push(const Object &) = 0;
	virtual Object pop() = 0;
};
template <typename Object>
class Stack : public StackADT<Object>
{
private:
	Object *data;
	long size;
	long top;
	void createStack(long s)
	{
		data = new Object[s];
		size = s;
		top = 0;
	}
public:
	Stack()
	{
		createStack(100);
	}
	Stack(long s)
	{
		createStack(s);
	}
	~Stack()
	{
		delete[] data;
		data = NULL;
	}
	bool isEmpty() const
	{
		return (top == 0);
	}
	bool isFull() const
	{
		return (top == size);
	}
	long sSize() const
	{
		return top;
	}
	Object peek() const
	{
		if (this->isEmpty())
		{
			throw 0;
		}
		return data[top - 1];
	}
	void push(const Object &s)
	{
		if (this->isFull())
		{
			throw 0;
		}
		data[top++] = s;
	}
	Object pop()
	{
		if (this->isEmpty())
		{
			throw 0;
		}
		return data[--top];
	}
};
int main()
{
	StackADT<int>* s = new Stack<int>(6);
	s->push(0);
	s->push(1);
	s->push(2);
	s->push(3);
	s->push(4);
	s->push(5);
	cout << "Is Full : " << s->isFull() << endl;
	cout << s->pop() << endl;
	cout << s->pop() << endl;
	cout << s->pop() << endl;
	cout << "Size : " << s->sSize() << endl;
	cout << s->pop() << endl;
	cout << s->pop() << endl;
	cout << s->pop() << endl;
	cout << "Is Empty : " << s->isEmpty() << endl;
	delete s;
	system("pause");
}