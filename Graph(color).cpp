#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#define Infinity 1000
using namespace std;
class Graph
{
private:
	class GraphNode
	{
	public:
		string data;
		vector<GraphNode*> next;
		char color;
		int dist;
		int ft;
		string pred;
		GraphNode(string d)
		{
			data = d;
			color = 'w';
			dist = Infinity;
			pred = "";
			ft = Infinity;
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
	void visitDFS(GraphNode &g, int &ti)
	{
		ti++;
		g.dist = ti;
		g.color = 'g';
		cout << g.data << endl;
		vector<GraphNode *> &n = g.next;
		for (int k = 0; k != n.size(); k++)
			if (n[k]->color == 'w')
			{
				n[k]->pred = g.data;
				visitDFS(*n[k], ti);
			}
		g.color = 'b';
		ti++;
		g.ft = ti;
	};
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
		int ti = 0;
		for (vector<GraphNode>::iterator it = gr.begin(); it != gr.end(); it++)
		{
			it->color = 'w';
			it->dist = Infinity;
			it->pred = "";
		}
		for (vector<GraphNode>::iterator it = gr.begin(); it != gr.end(); it++)
		{
			if (it->color == 'w')
				visitDFS(*it, ti);
		}
	}
	void showBFS(string st)
	{
		int ind;
		for (int i = 0; i < gr.size(); i++)
		{
			gr[i].color = 'w';
			gr[i].dist = Infinity;
			gr[i].pred = "";
			if (st == gr[i].data)
			{
				ind = i;
			}
		}
		gr[0].color = 'g';
		gr[0].dist = 0;
		queue<GraphNode*> q;
		queue<int> s;
		GraphNode *tmp = NULL;
		int lv = 0;
		q.push(&gr[ind]);
		s.push(lv);
		while (!q.empty())
		{
			tmp = q.front();
			q.pop();
			lv = s.front();
			s.pop();
			for (int k = 0; k < lv; k++) cout << "--";
			cout << tmp->data << endl;
			vector<GraphNode *> &n = tmp->next;
			for (int k = 0; k != n.size(); k++)
				if (n[k]->color == 'w')
				{
					n[k]->color = 'g';
					n[k]->dist = tmp->dist + 1;
					n[k]->pred = tmp->data;
					q.push(n[k]);
					s.push(lv + 1);
				}
			tmp->color = 'b';
		}
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