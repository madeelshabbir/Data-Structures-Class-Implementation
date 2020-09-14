#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class OSFSTree
{
private:

	class TreeNode
	{
	public:
		string data;
		TreeNode * left,* right;

		TreeNode(string d)
		{
			this->data = d;
			left = NULL;
			right = NULL;
		}
	};

	TreeNode *root;

public:
	OSFSTree()
	{
		root = NULL;
	}

	~OSFSTree()
	{
		// to be implemented
	}

	void dump() // display the tree node in a line
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

				if (tmp->right != NULL)
					s.push(tmp->right);
				if (tmp->left != NULL)
					s.push(tmp->left);
			}
		}
	}

	void display1()
	{
		if (root != NULL)
		{
			stack<TreeNode *> s;
			stack<int> ls;

			TreeNode *tmp = NULL;
			int lv = 0;

			s.push(root);
			ls.push(lv);

			while (!s.empty())
			{
				tmp = s.top();
				s.pop();
				lv = ls.top();
				ls.pop();

				for (int k = 0; k<lv; k++) cout << "--"; // indent two spaces
				cout << tmp->data << endl;

				if (tmp->right != NULL)
				{
					s.push(tmp->right);
					ls.push(lv + 1);
				}
				if (tmp->left != NULL)
				{
					s.push(tmp->left);
					ls.push(lv + 1);
				}
			}
		}
	}


	void display2()
	{
		if (root != NULL)
		{
			stack<TreeNode *> s;
			stack<int> ls;

			TreeNode *tmp = NULL;
			int lv = 0;

			s.push(root);
			ls.push(lv);

			while (!s.empty())
			{
				tmp = s.top();
				s.pop();
				lv = ls.top();
				ls.pop();

				if (tmp->right != NULL)
				{
					s.push(tmp->right);
					ls.push(lv + 1);
				}
				if (tmp->left != NULL)
				{
					s.push(tmp->left);
					ls.push(lv + 1);
				}

				for (int k = 0; k<lv; k++) cout << "--"; // indent two spaces
				cout << tmp->data << endl;
			}
		}
	}

	void display2q() // with queue
	{
		if (root != NULL)
		{
			queue<TreeNode *> s;
			queue<int> ls;

			TreeNode *tmp = NULL;
			int lv = 0;

			s.push(root);
			ls.push(lv);

			while (!s.empty())
			{
				tmp = s.front();
				s.pop();
				lv = ls.front();
				ls.pop();

				if (tmp->right != NULL)
				{
					s.push(tmp->right);
					ls.push(lv + 1);
				}
				if (tmp->left != NULL)
				{
					s.push(tmp->left);
					ls.push(lv + 1);
				}

				for (int k = 0; k<lv; k++) cout << "--"; // indent two spaces
				cout << tmp->data << endl;
			}
		}
	}

	void display3()
	{
		if (root != NULL)
		{
			display3(root, 0);
		}
	}

	void display3(TreeNode *sr, int lv)
	{
		for (int k = 0; k<lv; k++) cout << "--"; // indent two spaces
		cout << sr->data << endl;

		if (sr->right != NULL)
		{
			display3(sr->right, lv + 1);
		}
		if (sr->left != NULL)
		{
			display3(sr->left, lv + 1);
		}
	}

	void display4()
	{
		if (root != NULL)
		{
			display4(root, 0);
		}
	}

	void display4(TreeNode *sr, int lv)
	{
		if (sr->right != NULL)
		{
			display4(sr->right, lv + 1);
		}
		if (sr->left != NULL)
		{
			display4(sr->left, lv + 1);
		}
		for (int k = 0; k<lv; k++) cout << "--"; // indent two spaces
		cout << sr->data << endl;
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

	void addChildL(string d, string parent)
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
				if (tmp->right != NULL)
					s.push(tmp->right);
				if (tmp->left != NULL)
					s.push(tmp->left);
			}
		}
		if (parentPtr != NULL)
		{
			tmp = new TreeNode(d);
			parentPtr->left = tmp;
		}
		else
		{
			// exception
		}
	}
	void addChildR(string d, string parent)
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
				if (tmp->right != NULL)
					s.push(tmp->right);
				if (tmp->left != NULL)
					s.push(tmp->left);
			}
		}
		if (parentPtr != NULL)
		{
			tmp = new TreeNode(d);
			parentPtr->right = tmp;
		}
		else
		{
			// exception
		}
	}
};

int main()
{

	OSFSTree fsr;

	fsr.addRoot("D:");
	fsr.addChildL("PF", "D:");
	fsr.addChildR("OOP", "D:");
	fsr.addChildL("Quiz", "PF");
	fsr.addChildR("Project", "PF");
	fsr.addChildL("EntryUP", "Project");

	fsr.dump(); // Unformatted output of a tree
	cout << endl << endl << endl;
	fsr.display1(); // Formatted output of a tree using stack (process node before children)
	cout << endl << endl << endl;
	fsr.display2(); // Formatted output of a tree using stack (process node after children)
					// but it is same as above. 
					// you must change the stack with queue and see what happened
	cout << endl << endl << endl;
	fsr.display3(); // Formatted output of a tree using recursion (current before its children). 
					//  This is pre-order processing.
	cout << endl << endl << endl;
	fsr.display4(); // Formatted output of a tree using recursion (children before their parent).
					// This is post-order processing.
	cout << endl << endl << endl;

	fsr.display2q(); // Formatted output of a tree using queue    
	cout << endl << endl;
	system("pause");
	return 0;
}
