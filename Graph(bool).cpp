#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
class Graph
{
private:
	class GraphNode
	{
	public:
		string data;
		vector<GraphNode*> next;
		bool check;
		GraphNode(string d)
		{
			data = d;
			check = 0;
		}
	};
	vector<GraphNode> gr;
	GraphNode* searchPre(string s)
	{
		for (int i = 0; i < gr.size(); i++)
			if (gr[i].data == s)
				return &gr[i];
		throw 0;
	}
public:
	void insert(string d)
	{
		GraphNode tmp(d);
		gr.push_back(tmp);
	}
	void link(string a, string b)
	{
		for (vector<GraphNode>::iterator it = gr.begin(); it != gr.end(); it++)
			if (it->data == a)
			{
				it->next.push_back(searchPre(b));
				return;
			}
		throw 0;
	}
	int size() const
	{
		return gr.size();
	}
	void showDFS()
	{
		stack<GraphNode*> s;
		stack<int> q;
		GraphNode *tmp = NULL;
		for (int m = 0; m != gr.size(); m++)
		{
			int lv = 0;
			if (gr[m].check != true)
				s.push(&gr[m]);
			else
				continue;
			q.push(lv);
			while (!s.empty())
			{
				tmp = s.top();
				s.pop();
				lv = q.top();
				q.pop();
				if (tmp->check != true)
				{
					for (int k = 0; k < lv; k++) cout << "--";
					cout << tmp->data << endl;
				}
				tmp->check = true;
				vector<GraphNode *> &n = tmp->next;
				for (int k = 0; k != n.size(); k++)
				{
					if (n[k]->check != true)
					{
						s.push(n[k]);
						q.push(lv + 1);
					}
				}
			}
		}
		for (vector<GraphNode>::iterator it = gr.begin(); it != gr.end(); it++)
			it->check = false;
	}
	void showBFS(string st)
	{
		int ind;
		for (int i = 0; i < gr.size(); i++)
		{
			if (st == gr[i].data)
				ind = i;
		}
		queue<GraphNode *> s;
		queue<int> q;
		GraphNode *tmp = NULL;
		int lv = 0;
		s.push(&gr[ind]);
		q.push(lv);
		while (!s.empty())
		{
			tmp = s.front();
			s.pop();
			lv = q.front();
			q.pop();
			if (tmp->check != true)
			{
				for (int k = 0; k < lv; k++) cout << "--";
				cout << tmp->data << endl;
			}
			tmp->check = true;
			vector<GraphNode *> &n = tmp->next;
			for (int k = n.size() - 1; k >= 0; k--)
			{
				if (n[k]->check != true)
				{
					s.push(n[k]);
					q.push(lv + 1);
				}
			}
		}
		for (vector<GraphNode>::iterator it = gr.begin(); it != gr.end(); it++)
			it->check = false;
	}
};
int main()
{
	Graph g;
	g.insert("m");
	g.insert("b");
	g.insert("a");
	g.insert("c");
	g.insert("s");
	g.insert("d");
	g.insert("t");
	g.link("m", "b");
	g.link("m", "d");
	g.link("b", "d");
	g.link("a", "m");
	g.link("a", "c");
	g.link("a", "d");
	g.link("c", "t");
	g.link("s", "a");
	g.link("s", "m");
	g.link("d", "t");
	cout << "*******BFS*******" << endl;
	g.showBFS("s");
	cout << "*******DFS*******" << endl;
	g.showDFS();
	system("pause");
}