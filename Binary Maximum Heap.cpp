#include<iostream>
using namespace std;
class BinMaxHeap
{
private:
	int *arr;
	int heapsize;
public:
	BinMaxHeap()
	{
		arr = new int[100];
		heapsize = 0;
	}
	BinMaxHeap(int s)
	{
		arr = new int[s];
		heapsize = 0;
	}
	void insert(int v)
	{
		arr[heapsize++] = v;
		pushupward(heapsize - 1);
	}
	void remove(int i)
	{
		arr[i] = arr[--heapsize];
		pushdownward(i);
	}
	void extractmax()
	{
		remove(0);
	}
	int getmax()
	{
		return arr[0];
	}
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	int left(int i)
	{
		return 2 * i + 1;
	}
	int right(int i)
	{
		return 2 * i + 2;
	}
	void pushupward(int i)
	{
		if (i > 0)
		{
			int p = parent(i);
			if (arr[i] > arr[p])
			{
				swap(arr[i], arr[p]);
				pushupward(p);
			}
		}
	}
	void pushdownward(int i)
	{
		if (i < heapsize)
		{
			int l = left(i);
			int r = right(i);
			if (l < heapsize)
			{
				int t = arr[l] > arr[r] ? l : r;
				swap(arr[t], arr[i]);
				pushdownward(t);
			}
		}
	}
	bool isEmpty() const
	{
		return heapsize == 0;
	}
};
int main()
{
	BinMaxHeap n;
	n.insert(4);
	n.insert(45);
	n.insert(94);
	n.insert(62);
	n.insert(1);
	n.extractmax();
	cout << n.getmax() << endl;
	system("pause");
}