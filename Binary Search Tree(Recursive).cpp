#include <iostream>
#include <string>
#include <stack>
using namespace std;

class BSTree
{
private:

	class TreeNode
	{
	public:
		int data;
		TreeNode * left, *right;
		TreeNode(int d)
		{
			this->data = d;
			left = NULL;
			right = NULL;
		}
	};
	TreeNode *root;
	TreeNode* findMin(TreeNode *t) const
	{
		if (t == NULL)
			return NULL;
		if (t->left == NULL)
			return t;
		return findMin(t->left);
	}
	void show(TreeNode *sr, int lv)
	{
		if (sr->left != NULL)
		{
			show(sr->left, lv + 1);
		}
		for (int k = 0; k<lv; k++) cout << "--";
		cout << sr->data << endl;
		if (sr->right != NULL)
		{
			show(sr->right, lv + 1);
		}
	}
	void remove(TreeNode *sr)
	{
		if (sr->left != NULL)
		{
			remove(sr->left);
		}
		if (sr->right != NULL)
		{
			remove(sr->right);
		}
		delete sr;
	}
	bool search(const int &x, TreeNode *&t)
	{
		if (t == NULL)
			return false;
		else if (t->data == x)
			return true;
		else if (x < t->data)
			search(x, t->left);
		else if (t->data < x)
			search(x, t->right);
	}
	void insert(const int &x, TreeNode *&t)
	{
		if (t == NULL)
			t = new TreeNode(x);
		else if (x < t->data)
			insert(x, t->left);
		else if (t->data < x)
			insert(x, t->right);
	}
	void remove(const int &x, TreeNode *&t)
	{
		if (t == NULL)
			return;
		if (x < t->data)
			remove(x, t->left);
		else if (t->data < x)
			remove(x, t->right);
		else if (t->left != NULL && t->right != NULL)
		{
			bool b = (findMin(t->right)->data - t->data < t->data - findMax(t->left)->data) ? 0 : 1;
			t->data = b == 0 ? findMin(t->right)->data : findMax(t->left)->data;
			TreeNode* tmp = b == 0 ? t->right : t->left;
			remove(t->data, tmp);
		}
		else
		{
			TreeNode *oldNode = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete oldNode;
		}
	}
public:
	BSTree()
	{
		root = NULL;
	}
	~BSTree()
	{
		remove(root);
		root = NULL;
	}
	void insert(const int &x)
	{
		insert(x, root);
	}
	bool search(const int &x)
	{
		return search(x, root);
	}
	void show()
	{
		show(root, 0);
	}
	void remove(const int &x)
	{
		remove(x, root);
	}
};

int main()
{
	BSTree bst;
	bst.insert(30);
	bst.insert(20);
	bst.insert(10);
	bst.insert(90);
	bst.insert(5);
	bst.insert(60);
	bst.insert(15);
	bst.insert(100);
	bst.insert(55);
	bst.insert(98);
	bst.insert(75);
	bst.insert(110);
	bst.insert(80);
	bst.insert(85);
	bst.insert(72);
	bst.insert(82);
	bst.insert(81);
	bst.show();
	if (bst.search(90))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	cout << endl;
	bst.remove(90);
	bst.show();
	if (bst.search(90))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	system("pause");
	return 0;
}