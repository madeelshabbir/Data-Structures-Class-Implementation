#include<iostream>
#include<algorithm>
using namespace std;
class AVLTree
{
private:
	class AVLNode
	{
	public:
		int data;
		AVLNode *left;
		AVLNode *right;
		int height;
		AVLNode(int d) : data(d), left(NULL), right(NULL), height(0) { }
	};
	AVLNode *root;
	int height(AVLNode *t) const
	{
		return t == NULL ? -1 : t->height;
	}
	AVLNode * findMin(AVLNode *t) const
	{
		if (t == NULL)
			return NULL;
		if (t->left == NULL)
			return t;
		return findMin(t->left);
	}
	void rotateWithLeftChild(AVLNode * &k2)
	{
		AVLNode *k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2->height = max(height(k2->left), height(k2->right)) + 1;
		k1->height = max(height(k1->left), k2->height) + 1;
		k2 = k1;
	}
	void rotateWithRightChild(AVLNode * &k2)
	{
		AVLNode *k1 = k2->right;
		k2->right = k1->left;
		k1->left = k2;
		k2->height = max(height(k2->right), height(k2->left)) + 1;
		k1->height = max(height(k1->right), k2->height) + 1;
		k2 = k1;
	}
	void doubleWithLeftChild(AVLNode * & k3)
	{
		rotateWithRightChild(k3->left);
		rotateWithLeftChild(k3);
	}
	void doubleWithRightChild(AVLNode * & k3)
	{
		rotateWithLeftChild(k3->right);
		rotateWithRightChild(k3);
	}
	void balance(AVLNode *&t)
	{
		if (t == NULL)
			return;
		if (height(t->left) - height(t->right) > 1)
		{
			if (height(t->left->left) >= height(t->left->right))
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);
		}
		else if (height(t->right) - height(t->left) > 1)
		{
			if (height(t->right->right) >= height(t->right->left))
				rotateWithRightChild(t);
			else
				doubleWithRightChild(t);
		}
		t->height = max(height(t->left), height(t->right)) + 1;
	}
	void remove(AVLNode *sr)
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
	bool search(const int &x, AVLNode *&t)
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
	void insert(const int &x, AVLNode *&t)
	{
		if (t == NULL)
			t = new AVLNode(x);
		else if (x < t->data)
			insert(x, t->left);
		else if (t->data < x)
			insert(x, t->right);
		balance(t);
	}
	void show(AVLNode *sr, int lv)
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
	void remove(const int &x, AVLNode *&t)
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
			AVLNode *oldNode = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete oldNode;
		}
		balance(t);
	}
public:
	AVLTree()
	{
		root = NULL;
	}
	~AVLTree()
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
	AVLTree avl;
	avl.insert(30);
	avl.insert(20);
	avl.insert(10);
	avl.insert(90);
	avl.insert(5);
	avl.insert(60);
	avl.insert(15);
	avl.insert(100);
	avl.insert(55);
	avl.insert(98);
	avl.insert(75);
	avl.insert(110);
	avl.insert(80);
	avl.insert(85);
	avl.insert(72);
	avl.insert(82);
	avl.insert(81);
	avl.show();
	if (avl.search(90))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	cout << endl;
	avl.remove(90);
	avl.show();
	if (avl.search(90))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	system("pause");
}