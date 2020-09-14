#include<iostream>
using namespace std;
template <typename Object>
class Vector
{
private:
	Object* data;
	int cap;
	int top;
	void createVector(int s)
	{
		data = new Object[s];
		cap = s;
		top = 0;
	}
	bool isFull()
	{
		return top == cap;
	}
public:
	Vector(int s = 100)
	{
		createVector(s);
	}
	Vector(const Vector &v)
	{
		data = new Object[v.cap];
		cap = v.cap;
		top = v.top;
		for(int i = 0; i < v.top; i++)
			data[i] = v.data[i];
	}
	~Vector()
	{
		delete[] data;
		data = NULL;
	}
	Vector& operator=(const Vector &v)
	{
		if(this != &rhs)
		{
			delete[] data;
			data = new Object[v.cap];
			cap = v.cap;
			top = v.top;
			for (int i = 0; i < v.top; i++)
				data[i] = v.data[i];
		}
		return *this;
	}
	bool isEmpty()
	{
		return top == 0;
	}
	int size()
	{
		return top;
	}
	Object& operator[](int n)
	{
		if (n < 0 || n >= top)
			throw 0;
		return data[n];
	}
	const Object& operator[](int index) const
	{
		if (n < 0 || n >= top)
			throw 0;
		return data[n];
	}
	void push_back(const Object &o)
	{
		if (isFull())
			throw 0;
		data[top++] = o;
	}
	void push_front(const Object &o)
	{
		if (isFull())
			throw 0;
		for (int i = top; i > 0; i--)
			data[i] = data[i - 1];
		data[0] = o;
		top++;
	}
	void pop_back()
	{
		if (isEmpty())
			throw 0;
		top--;
	}
	void pop_front()
	{
		if (isEmpty())
			throw 0;
		for (int i = 0; i < top - 1; i++)
			data[i] = data[i + 1];
		top--;
	}
	const Object& back() const
	{
		if (isEmpty())
			throw 0;
		return data[i - 1];
	}

	typedef Object* Iterator;
	typedef const Object* const_Iterator;

	Iterator begin()
	{
		return &data[0];
	}
	const_Iterator begin() const
	{
		return &data[0];
	}
	Iterator end()
	{
		return &data[top];
	}
	const_Iterator end() const
	{
		return &data[top];
	}
};
int main()
{
	Vector<int> v;
	v.push_back(1);
	v.push_front(2);
	v.push_back(3);
	v.push_front(4);
	v.push_back(5);
	v.push_back(6);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	Vector<int>::Iterator i;
	for (i = v.begin(); i != v.end(); i++)
		cout << *i << endl;
	system("pause");
}