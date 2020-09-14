#include<iostream>
using namespace std;
template <typename Object>
class MyList
{
public:
	virtual void push_last(const Object &) = 0;
	// push an Object at end of MyList

	virtual void push_first(const Object &) = 0;
	// push an Object at start of MyList

	virtual Object last() = 0;
	// just returns an Object at end of MyList

	virtual Object first() const = 0;
	// just returns an Object at end of MyList

	virtual void display_mylist() = 0;
	// output all Objects in MyList sequentially

	virtual void pop_last() = 0;
	// removes an Object at end of MyList

	virtual void pop_first() = 0;
	// removes an Object at end of MyList

	virtual long indexOf(const Object &) = 0;
	// Zero based integer as location of an Object in MyList

	virtual void pop_at(const long &) = 0;
	// removes an Object from MyList at location

	virtual bool isEmpty() const = 0;
	// returns about the emptiness of MyList

	virtual long size() const = 0;
	// returns the size of MyList

};
template <typename Object>
class MyListArray : public MyList<Object>
{
private:
	Object *data;
	long tsize;
	long top;
	void createList(long s)
	{
		data = new Object[s];
		tsize = s;
		top = 0;
	}
	bool validation()
	{
		return top < tsize;
	}
public:
	MyListArray()
	{
		createList(100);
	}
	MyListArray(long s)
	{
		createList(s);
	}
	~MyListArray()
	{
		delete[] data;
		data = NULL;
	}
	void push_last(const Object &l)
	{
		if(!validation())
			throw 0;
		data[top++] = l;
	}
	void push_first(const Object &l)
	{
		if (!validation())
			throw 0;
		for (int i = top; i > 0; i--)
			data[i] = data[i - 1];
		data[0] = l;
		top++;
	}
	Object last()
	{
		return data[top - 1];
	}
	Object first() const
	{
		return data[0];
	}
	void display_mylist()
	{
		for (int i = 0; i < top; i++)
			cout << data[i] << " ";
		cout << endl;
	}
	void pop_last()
	{
		if (isEmpty())
			throw 0;
		top--;
	}
	void pop_first()
	{
		if (isEmpty())
			throw 0;
		for (int i = 0; i < top; i++)
			data[i] = data[i+1];
		top--;
	}
	long indexOf(const Object &l)
	{
		for (int i = 0; i < top; i++)
			if (data[i] == l)
				return i;
		return -1;
	}
	void pop_at(const long &n)
	{
		if (n >= top && n < 0)
			throw 0;
		for (int i = n; i < top; i++)
			data[i] = data[i + 1];
		top--;
	}
	bool isEmpty() const
	{
		return top == 0;
	}
	long size() const
	{
		return top;
	}
};
template <typename Object>
class MyListLinked : public MyList<Object>
{
private:
	class ListNode
	{
	public:
		Object data;
		ListNode* next;
		ListNode* pre;
		ListNode()
		{
			next = NULL;
			pre = NULL;
		}
		ListNode(Object d)
		{
			data = d;
			next = NULL;
			pre = NULL;
		}
	};
	ListNode* head;
	ListNode* tail;
	long lsize;
public:
	MyListLinked()
	{
		lsize = 0;
		head = new ListNode();
		tail = new ListNode();
		head->next = tail;
		tail->pre = head;
	}
	~MyListLinked()
	{
		ListNode* tmp = head;
		while (tmp != NULL)
		{
			ListNode *junk = tmp;
			tmp = tmp->next;
			delete junk;
		}
		head = NULL;
		tail = NULL;
	}
	void push_last(const Object &l)
	{
		ListNode* node = new ListNode(l);
		ListNode* tmp = tail->pre;
		tail->pre = node;
		tmp->next = node;
		node->pre = tmp;
		node->next = tail;
		lsize++;
	}
	void push_first(const Object &l)
	{
		ListNode* node = new ListNode(l);
		ListNode* tmp = head->next;
		head->next = node;
		tmp->pre = node;
		node->pre = head;
		node->next = tmp;
		lsize++;
	}
	Object last()
	{
		return tail->pre->data;
	}
	Object first() const
	{
		return head->next->data;
	}
	void display_mylist()
	{
		ListNode* tmp = head->next;
		while (tmp != tail)
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	void pop_last()
	{
		ListNode* junk = tail->pre;
		tail->pre = junk->pre;
		junk->pre->next = tail;
		delete junk;
		lsize--;
	}
	void pop_first()
	{
		ListNode* junk = head->next;
		head->next = junk->next;
		junk->next->pre = head;
		delete junk;
		lsize--;
	}
	long indexOf(const Object &l)
	{
		long i = 0;
		ListNode* tmp = head->next;
		while (tmp != tail)
		{
			if (tmp->data == l)
				return i;
			tmp = tmp->next;
			i++;
		}
		return -1;
	}
	void pop_at(const long &n)
	{
		if (n >= lsize)
			throw 0;
		ListNode* tmp = NULL;
		if (n > lsize - n)
		{
			tmp = tail->pre;
			for (long i = lsize-1; i > n; i--)
				tmp = tmp->pre;
		}
		else
		{
			tmp = head->next;
			for (long i = 0; i < n; i++)
				tmp = tmp->next;
		}
		ListNode* junk = tmp;
		tmp = junk->pre;
		tmp->next = junk->next;
		junk->next->pre = tmp;
		delete junk;
		lsize--;
	}
	bool isEmpty() const
	{
		return head->next == tail;
	}
	long size() const
	{
		return lsize;
	}
};
int main()
{
	cout << "Array Implementation:-" << endl;
	MyList<int> *mla = new MyListArray<int>(10);
	mla->push_last(1);
	mla->push_last(2);
	mla->push_last(3);
	mla->push_last(4);
	mla->push_first(5);
	mla->push_last(6);
	mla->push_first(7);
	mla->push_last(8);
	mla->push_first(9);
	mla->push_last(10);
	mla->display_mylist();
	cout << "Last: " << mla->last() << endl;
	mla->pop_last();
	cout << "Last: " << mla->last() << endl;
	cout << "First: " << mla->first() << endl;
	mla->pop_first();
	cout << "First: " << mla->first() << endl;
	mla->pop_at(mla->indexOf(5));
	mla->display_mylist();
	cout << "Is Empty: " << mla->isEmpty() << endl;
	cout << "Size: " << mla->size() << endl;
	delete mla;
	cout << "\nLinked List Implementation:-" << endl;
	MyList<int> *mll = new MyListLinked<int>;
	mll->push_last(1);
	mll->push_last(2);
	mll->push_last(3);
	mll->push_last(4);
	mll->push_first(5);
	mll->push_last(6);
	mll->push_first(7);
	mll->push_last(8);
	mll->push_first(9);
	mll->push_last(10);
	mll->display_mylist();
	cout << "Last: " << mll->last() << endl;
	mll->pop_last();
	cout << "Last: " << mll->last() << endl;
	cout << "First: " << mll->first() << endl;
	mll->pop_first();
	cout << "First: " << mll->first() << endl;
	mll->pop_at(mll->indexOf(5));
	mll->display_mylist();
	cout << "Is Empty: " << mll->isEmpty() << endl;
	cout << "Size: " << mll->size() << endl;
	delete mll;
	system("pause");
}