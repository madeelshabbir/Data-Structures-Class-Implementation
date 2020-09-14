#include<iostream>
using namespace std;
template <typename Object>
class StackADT
{
public:
	virtual bool isEmpty() const = 0;
	virtual long sSize() const = 0;
	virtual Object peek() const = 0;
	virtual void push(const Object &) = 0;
	virtual Object pop() = 0;
};
template <typename Object>
class StackL : public StackADT<Object>
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
	long size;
public:
	StackL()
	{
		head = NULL;
		size = 0;
	}
	~StackL()
	{
		while (head != NULL)
		{
			ListNode *junk = head;
			head = head->next;
			delete junk;
		}
		head = NULL;
	}
	bool isEmpty() const
	{
		return (head == NULL);
	}
	long sSize() const
	{
		return size;
	}
	Object peek() const
	{
		if(isEmpty())
		{
			throw 0;
		}
		return head->data;
	}
	void push(const Object &d)
	{
		size++;
		if(isEmpty())
		{
			head = new ListNode(d);
			return;
		}
		ListNode* tmp = new ListNode(d);
		tmp->next = head;
		head = tmp;
	}
	Object pop()
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
};
int main()
{
	StackADT<int>* s = new StackL<int>;
	s->push(0);
	s->push(1);
	s->push(2);
	s->push(3);
	s->push(4);
	s->push(5);
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