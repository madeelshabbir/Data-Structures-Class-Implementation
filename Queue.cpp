#include<iostream>
using namespace std;
template <typename Object>
class QueueADT
{
public:
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual long qSize() const = 0;
	virtual Object peek() const = 0;
	virtual void enqueue(const Object &) = 0;
	virtual Object dequeue() = 0;
	virtual void remove(const Object &) = 0;
};
template <typename Object>
class Queue : public QueueADT<Object>
{
private:
	Object* data;
	long size;
	long rear;
	long front;
	long pos;
	void createQueue(long s)
	{
		data = new Object[s];
		size = s;
		rear = 0;
		front = 0;
		pos = 0;
	}
public:
	Queue()
	{
		createQueue(100);
	}
	Queue(long s)
	{
		createQueue(s);
	}
	~Queue()
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
		return pos == size;
	}
	long qSize() const
	{
		return pos;
	}
	Object peek() const
	{
		if (isEmpty())
		{
			throw 0;
		}
		int tmp = front;
		tmp %= size;
		return data[tmp];
	}
	void enqueue(const Object &q)
	{
		if (isFull())
		{
			throw 0;
		}
		rear %= size;
		data[rear++] = q;
		pos++;
	}
	Object dequeue()
	{
		if (isEmpty())
		{
			throw 0;
		}
		front %= size;
		pos--;
		return data[front++];
	}
	void remove(const Object &v)
	{
		int i = front;
		bool b = 0;
		while (true)
		{
			i %= size;
			if (i == rear - 1)
				break;
			if (data[i] == v || b == 1)
			{
				data[i] = data[(i + 1) % size];
				b = 1;
			}
			i++;
		}
		rear--;
		pos--;
	}
};
int main()
{
	QueueADT<int>* q = new Queue<int>(5);
	cout << "Is Empty : " << q->isEmpty() << endl;
	cout << "Is Full : " << q->isFull() << endl;
	q->enqueue(0);
	q->enqueue(1);
	q->enqueue(2);
	cout << "Is Empty : " << q->isEmpty() << endl;
	cout << "Size : " << q->qSize() << endl;
	cout << q->dequeue() << endl;
	cout << q->dequeue() << endl;
	q->enqueue(3);
	q->enqueue(4);
	q->enqueue(5);
	q->enqueue(6);
	cout << "Peek : " << q->peek() << endl;
	cout << "Size : " << q->qSize() << endl;
	cout << "Is Full : " << q->isFull() << endl;
	q->remove(4);
	cout << q->dequeue() << endl;
	cout << q->dequeue() << endl;
	cout << q->dequeue() << endl;
	cout << q->dequeue() << endl;
	delete q;
	system("pause");
}