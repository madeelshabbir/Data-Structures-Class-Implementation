#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Tree
{
private:

	class TreeNode
	{
	public:
		string data;
		vector<TreeNode *> children;

		TreeNode(string d)
		{
			this->data = d;
		}
	};

	TreeNode *root;

public:
	Tree()
	{
		root = NULL;
	}

	~Tree()
	{
		// to be implemented
	}

	void show()
	{
		if (root != NULL)
		{
			stack<TreeNode *> s;
			s.push(root);

			TreeNode *tmp = NULL;

			while (!s.empty())
			{
				tmp = s.top();
				s.pop();

				cout << tmp->data << endl;
				vector<TreeNode *> &cld = tmp->children;

				int k = 0;
				while (k != cld.size())
				{
					s.push(cld[k]);
					k++;
				}
			}
		}
	}

	void addRoot(string d)
	{
		if (root == NULL)
		{
			root = new TreeNode(d);
		}
		else
		{
			// exception
		}
	}

	void addChild(string d, string parent)
	{
		TreeNode *tmp = NULL;
		TreeNode *parentPtr = NULL;

		stack<TreeNode *> s;

		s.push(root);
		while (!s.empty())
		{
			tmp = s.top();
			s.pop();

			if (tmp->data == parent)
			{
				parentPtr = tmp;
				break;
			}
			else
			{
				for (vector<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
				{
					s.push(*p);
				}
			}
		}
		if (parentPtr != NULL)
		{
			tmp = new TreeNode(d);
			parentPtr->children.push_back(tmp);
		}
		else
		{
			throw 0;
		}
	}

	bool search(string d)
	{
		if (root != NULL)
		{
			TreeNode* tmp = NULL;
			stack<TreeNode *> s;
			s.push(root);
			while (!s.empty())
			{
				tmp = s.top();
				s.pop();
				if (tmp->data == d)
				{
					return true;
				}
				for (vector<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
				{
					s.push(*p);
				}
			}
		}
		return false;
	}
	void remove(string d)
	{
		if (root != NULL)
		{
			TreeNode* tmp = NULL;
			stack<TreeNode *> s;
			s.push(root);
			while (!s.empty())
			{
				tmp = s.top();
				s.pop();
				vector<TreeNode *> &cld = tmp->children;
				int k = 0;
				for (vector<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
				{
					if (cld[k++]->data == d)
					{
						tmp->children.erase(p);
						return;
					}
					s.push(*p);
				}
			}
		}
	}
	void cut(string d, string to)
	{
		if (root != NULL)
		{
			TreeNode* tmp = NULL;
			stack<TreeNode *> s;
			TreeNode* dest = NULL;
			s.push(root);
			while (!s.empty())
			{
				tmp = s.top();
				s.pop();
				if (tmp->data == to)
				{
					dest = tmp;
					break;
				}
				for (vector<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
				{
					s.push(*p);
				}
			}
			s.push(root);
			while (!s.empty())
			{
				tmp = s.top();
				s.pop();
				vector<TreeNode *> &cld = tmp->children;
				int k = 0;
				for (vector<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
				{
					if (cld[k++]->data == d)
					{
						dest->children.push_back(*p);
						tmp->children.erase(p);
						return;
					}
					s.push(*p);
				}
			}
		}
	}
	void copy(string d, string to)
	{
		if (root != NULL)
		{
			TreeNode* tmp = NULL;
			stack<TreeNode *> s;
			TreeNode* dest = NULL;
			s.push(root);
			while (!s.empty())
			{
				tmp = s.top();
				s.pop();
				if (tmp->data == to)
				{
					dest = tmp;
					break;
				}
				for (vector<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
				{
					s.push(*p);
				}
			}
			s.push(root);
			while (!s.empty())
			{
				tmp = s.top();
				s.pop();
				vector<TreeNode *> &cld = tmp->children;
				int k = 0;
				for (vector<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
				{
					if (cld[k++]->data == d)
					{
						dest->children.push_back(*p);
						return;
					}
					s.push(*p);
				}
			}
		}
	}
};


int main()
{
	Tree t;
	t.addRoot("D:");
	t.addChild("PF", "D:");
	t.addChild("OOP", "D:");
	t.addChild("Quiz", "PF");
	t.addChild("Project", "PF");
	t.addChild("DSA", "D:");
	t.addChild("Marks", "DSA");
	t.addChild("TTTTT", "Marks");
	t.addChild("UUUUT", "D:");
	//t.copy("PF", "OOP");
	t.cut("PF", "OOP");
	t.remove("OOP");
	cout << t.search("PF") << endl;
	t.show();
	cout << endl;
	system("pause");
	return 0;
}