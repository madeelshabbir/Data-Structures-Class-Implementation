#include<iostream>
using namespace std;
template <typename Object>
class QueueADT
{
public:
	virtual bool isEmpty() const = 0;
	virtual long qSize() const = 0;
	virtual Object peek() const = 0;
	virtual void enqueue(const Object &) = 0;
	virtual Object dequeue() = 0;
	virtual void remove(const Object &) = 0;
};
template <typename Object>
class QueueL : public QueueADT<Object>
{
private:
	class ListNode
	{
	public:
		Object data;
		ListNode* next;
		ListNode(Object d)
		{
			data = d;
			next = NULL;
		}
	};
	ListNode* head;
	ListNode* tail;
	long size;
public:
	QueueL()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	~QueueL()
	{
		while (head != NULL)
		{
			ListNode *junk = head;
			head = head->next;
			delete junk;
		}
		head = NULL;
		tail = NULL;
	}
	bool isEmpty() const
	{
		return (head == NULL);
	}
	long qSize() const
	{
		return size;
	}
	Object peek() const
	{
		if (isEmpty())
		{
			throw 0;
		}
		return head->data;
	}
	void enqueue(const Object &d)
	{
		size++;
		if (isEmpty())
		{
			head = new ListNode(d);
			tail = head;
			return;
		}
		tail->next = new ListNode(d);
		tail = tail->next;
	}
	Object dequeue()
	{
		if (isEmpty())
		{
			throw 0;
		}
		ListNode* tmp = head;
		head = head->next;
		Object o = tmp->data;
		delete tmp;
		size--;
		return o;
	}
	void remove(const Object &v)
	{
		ListNode* tmp = head;
		if (head != NULL && tmp->data == v)
		{
			head = head->next;
			delete tmp;
			return;
		}
		while (tmp->next != NULL)
		{
			if (tmp->next->data == v)
			{
				ListNode* jnk = NULL;
				if (tmp->next == tail)
				{
					jnk = tail;
					tail = tmp;
					tail->next = NULL;
					delete jnk;
					return;
				}
				jnk = tmp->next;
				tmp->next = jnk->next;
				delete jnk;
				return;
			}
			tmp = tmp->next;
		}
	}
};
int main()
{
	QueueADT<int>* q = new QueueL<int>;
	cout << "Is Empty : " << q->isEmpty() << endl;
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
	q->remove(4);
	cout << q->dequeue() << endl;
	cout << q->dequeue() << endl;
	cout << q->dequeue() << endl;
	cout << q->dequeue() << endl;
	delete q;
	system("pause");
}