// what are the mistakes in the code

#include <iostream>

using namespace std;

class LinkedList
{
private:
	class ListNode
	{
	public:
		int data;
		ListNode *next;
		ListNode(int d)
		{
			data = d;
			next = NULL;
		}
	};

	ListNode *head;

public:
	LinkedList()
	{
		head = NULL;
	}

	~LinkedList()
	{
		ListNode *tmp = head;
		while (tmp != NULL)
		{
			ListNode *junk = tmp;
			tmp = tmp->next;
			delete junk;
		}
	}

	void append(int d)
	{
		if (head == NULL)
		{
			head = new ListNode(d);
			return;
		}

		ListNode *tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new ListNode(d);
	}

	void erase(int d)
	{
		ListNode *tmp = head;
		while (tmp != NULL && tmp->next != NULL && tmp->next->data != d)
		{
			tmp = tmp->next;
		}
		if (tmp->next != NULL)
		{
			ListNode *junk = tmp->next;
			tmp->next = tmp->next->next;
			// OR tmp->next = junk->next;
			delete junk;
		}
	}

	void display()
	{
		ListNode *tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->data << endl;
			tmp = tmp->next;
		}

	}

	int kVal(int n)
	{
		ListNode *tmp = head;
		int count = 0;
		while (count != n)
		{
			if (tmp == NULL)
				throw 0;
			tmp = tmp->next;
			count++;
		}
		return tmp->data;
	}
};


int main()
{
	LinkedList *c = new LinkedList;

	c->append(30);
	c->append(90);
	c->append(20);
	c->append(70);
	c->append(50);

	c->erase(0);
	c->display();
	delete c;
	system("pause");
}
