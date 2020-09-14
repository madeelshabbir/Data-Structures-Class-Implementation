#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Story
{
private:
	string storyName;
	int priority;
	int teamNumber;
	int storyNumber;
	bool isDone;
public:
	string stName() const
	{
		return storyName;
	}
	int stPR() const
	{
		return priority;
	}
	int stTN() const
	{
		return teamNumber;
	}
	int stSN() const
	{
		return storyNumber;
	}
	bool stDN() const
	{
		return isDone;
	}
	void setNM(string s)
	{
		storyName = s;
	}
	void setPR(int p)
	{
		priority = p;
	}
	void setTN(int t)
	{
		teamNumber = t;
	}
	void setSN(int n)
	{
		storyNumber = n;
	}
	void setDN(int b)
	{
		isDone = b;
	}
	Story()
	{
		teamNumber = 0;
		isDone = false;
	}
	Story(string sn, int p, int t, int n, bool i)
	{
		storyName = sn;
		priority = p;
		teamNumber = t;
		storyNumber = n;
		isDone = i;
	}
	Story(const Story &s)
	{
		storyName = s.storyName;
		priority = s.priority;
		teamNumber = s.teamNumber;
		storyNumber = s.storyNumber;
		isDone = s.isDone;
	}
	friend ostream& operator<<(ostream &s, const Story &st)
	{
		s << left << setw(30) << st.storyName << setw(10) << st.priority << setw(10) << st.teamNumber << setw(10) << st.storyNumber << setw(10) << st.isDone << endl;
		return s;
	}
};
class StoryList
{
private:
	class ListNode
	{
	public:
		Story stData;
		ListNode* next;
		ListNode* pre;
		ListNode()
		{
			next = NULL;
			pre = NULL;
		}
		ListNode(const Story &s)
		{
			stData = s;
			next = NULL;
			pre = NULL;
		}
	};
	ListNode* head;
	ListNode* tail;
	long lsize;
	bool tSearch(string s, ListNode* &h)
	{
		if (h->next == tail)
		{
			return false;
		}
		else if (h->next->stData.stName() == s)
		{
			return true;
		}
		return tSearch(s, h->next);
	}
	bool Search(string s)
	{
		return tSearch(s, head);
	}
	long size() const
	{
		return lsize;
	}
public:
	StoryList()
	{
		lsize = 0;
		head = new ListNode();
		tail = new ListNode();
		head->next = tail;
		tail->pre = head;
	}
	~StoryList()
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
	bool isEmpty() const
	{
		return head->next == tail;
	}
	void insertStoryAtLast(const Story &s)
	{
		ListNode* node = new ListNode(s);
		ListNode* tmp = tail->pre;
		tail->pre = node;
		tmp->next = node;
		node->pre = tmp;
		node->next = tail;
		lsize++;
	}
	void printList()
	{
		if (isEmpty())
		{
			return;
		}
		ListNode* tmp = head->next;
		cout << left << setw(30) << "STORY NAME" << setw(10) << "PRIORITY" << setw(10) << "TEAM NO" << setw(10) << "STORY NO" << setw(10) << "IS DONE" << endl;
		while (tmp != tail)
		{
			cout << tmp->stData << endl;
			tmp = tmp->next;
		}
		cout << endl;
	}
	void removeStory(string s)
	{
		ListNode* tmp = head;
		while (tmp->next != tail)
		{
			if (tmp->next->stData.stName() == s)
			{
				ListNode* jnk = tmp->next;
				tmp->next = jnk->next;
				jnk->next->pre = tmp;
				delete jnk;
				lsize--;
				return;
			}
			tmp = tmp->next;
		}
	}
	void assignPrority(string s, int p)
	{
		ListNode* tmp = head;
		while (tmp->next != tail)
		{
			if (tmp->next->stData.stName() == s)
			{
				tmp->next->stData.setPR(p);
				return;
			}
			tmp = tmp->next;
		}
	}
	void assignTeamNumber(string s, int t)
	{
		ListNode* tmp = head;
		while (tmp->next != tail)
		{
			if (tmp->next->stData.stName() == s)
			{
				tmp->next->stData.setTN(t);
				return;
			}
			tmp = tmp->next;
		}
	}
	void orberByPriority()
	{
		for (int i = 0; i < size(); i++)
		{
			ListNode* tmp = head->next;
			for (int j = 0; j < size() - i - 1; j++)
			{
				if (tmp->stData.stPR() > tmp->next->stData.stPR())
				{
					ListNode* jnk = tmp;
					tmp = tmp->next;
					jnk->pre->next = tmp;
					tmp->pre = jnk->pre;
					jnk->next = tmp->next;
					jnk->pre = tmp;
					tmp->next->pre = jnk;
					tmp->next = jnk;
				}
				tmp = tmp->next;
			}
		}
	}
	void findByPriority(int p)
	{
		ListNode* tmp = head;
		while (tmp->next != tail)
		{
			if (tmp->next->stData.stPR() == p)
			{
				cout << tmp->next->stData << endl;
				return;
			}
			tmp = tmp->next;
		}
	}
	void replaceStory(string s, const Story &st)
	{
		ListNode* tmp = head;
		while (tmp->next != tail)
		{
			if (tmp->next->stData.stName() == s)
			{
				tmp->next->stData.setNM(st.stName());
				tmp->next->stData.setPR(st.stPR());
				tmp->next->stData.setTN(st.stTN());
				tmp->next->stData.setSN(st.stSN());
				tmp->next->stData.setDN(st.stDN());
				return;
			}
			tmp = tmp->next;
		}
	}
	void addAtFirst(const Story &s)
	{
		ListNode* node = new ListNode(s);
		ListNode* tmp = head->next;
		head->next = node;
		tmp->pre = node;
		node->pre = head;
		node->next = tmp;
		lsize++;
	}
	void addAfter(string s, const Story &st)
	{
		ListNode* tmp = head->next;
		while (tmp != tail)
		{
			if (tmp->stData.stName() == s)
			{
				ListNode* node = new ListNode(st);
				ListNode* tmp1 = tmp->next;
				tmp->next = node;
				tmp1->pre = node;
				node->pre = tmp;
				node->next = tmp1;
				lsize++;
				return;
			}
			tmp = tmp->next;
		}
	}
	void addBefore(string s, const Story &st)
	{
		ListNode* tmp = head;
		while (tmp->next != tail)
		{
			if (tmp->next->stData.stName() == s)
			{
				ListNode* node = new ListNode(st);
				ListNode* tmp1 = tmp->next;
				tmp->next = node;
				tmp1->pre = node;
				node->pre = tmp;
				node->next = tmp1;
				lsize++;
				return;
			}
			tmp = tmp->next;
		}
	}
	void markStory(string s, bool b)
	{
		ListNode* tmp = head;
		while (tmp->next != tail)
		{
			if (tmp->next->stData.stName() == s)
			{
				tmp->next->stData.setDN(b);
				return;
			}
		}
	}
	void showDoneOrNotDoneStories()
	{
		if (isEmpty())
		{
			return;
		}
		ListNode* tmp = head->next;
		cout << "Done One :-" << endl;
		cout << left << setw(30) << "STORY NAME" << setw(10) << "PRIORITY" << setw(10) << "TEAM NO" << setw(10) << "STORY NO" << setw(10) << "IS DONE" << endl;
		while (tmp != tail)
		{
			if (tmp->stData.stDN() == 1)
				cout << tmp->stData << endl;
			tmp = tmp->next;
		}
		cout << endl;
		tmp = head->next;
		cout << "Not Done One :-" << endl;
		cout << left << setw(30) << "STORY NAME" << setw(10) << "PRIORITY" << setw(10) << "TEAM NO" << setw(10) << "STORY NO" << setw(10) << "IS DONE" << endl;
		while (tmp != tail)
		{
			if (tmp->stData.stDN() == 0)
				cout << tmp->stData << endl;
			tmp = tmp->next;
		}
		cout << endl;
	}

	void deleteAll(string s)
	{
		ListNode* tmp = head;
		while (tmp->next != tail)
		{
			if (tmp->next->stData.stName() == s)
			{
				ListNode* jnk = tmp->next;
				tmp->next = jnk->next;
				jnk->next->pre = tmp;
				delete jnk;
				lsize--;
			}
			tmp = tmp->next;
		}
	}
};
int main()
{
	StoryList *s = new StoryList();
	cout << "Is Empty: " << s->isEmpty() << endl;
	Story* st1 = new Story("The Thirsty Crow", 2, 1, 1, 1);
	Story* st2 = new Story("The Greedy Dog", 4, 2, 2, 0);
	Story* st3 = new Story("Old man and his three sons", 1, 3, 3, 1);
	Story* st4 = new Story("Try Try Again", 1, 4, 4, 0);
	Story* st5 = new Story("Do Good, Have Good", 5, 5, 5, 1);
	s->insertStoryAtLast(*st1);
	s->insertStoryAtLast(*st2);
	s->addAtFirst(*st3);
	s->addAfter("The Thirsty Crow", *st4);
	s->addBefore("Old man and his three sons", *st5);
	/*s->assignPrority("The Greedy Dog", 0);
	s->assignTeamNumber("The Greedy Dog", 1);*/
	s->printList();
	s->orberByPriority();
	s->printList();
	/*s->findByPriority(5);
	s->replaceStory("The Greedy Dog", *st4);
	s->printList();*/
	s->showDoneOrNotDoneStories();
	system("pause");
}