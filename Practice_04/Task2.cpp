#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
struct Node
{
	int data;
	Node*next;
};
class LinkedList
{
private:
	Node * head;
	Node*tail;
	bool binarySearch(vector<int>v, int start, int end, int x)
	{
		int middle;
		if (start <= end)
		{
			middle = (start + end) / 2;
			if (v[middle] == x)
			{
				return true;
			}
			if (v[middle] > x)
			{
				return binarySearch(v, start, middle - 1, x);
			}
			else
			{
				return binarySearch(v, middle + 1, end, x);
			}
		}
		return false;
	};
public:
	LinkedList()
	{
		this->head = NULL;
		this->tail = NULL;
	}
	~LinkedList() {}
	void AddElement(int element);
	int countPairs(vector<int>v);
	int countNotEqualPairs(vector<int>v);
};
void LinkedList::AddElement(int element)
{
	Node*node = new Node();
	node->data = element;
	node->next = NULL;
	if (head == NULL)
	{
		this->head = node;
		this->tail = node;
		node = NULL;
	}
	else
	{
		tail->next = node;
		this->tail = node;
	}
}
int LinkedList::countPairs(vector<int>v)
{
	Node* node = new Node;
	node = this->head;
	int count = 0;
	bool isExsist = false;
	while (node->next != NULL)
	{
		isExsist = binarySearch(v, 0, v.size() - 1, node->data);
		if (isExsist)
		{
			node = node->next;
			isExsist = binarySearch(v, 0, v.size() - 1, node->data);
			if (isExsist)
			{
				count = count + 1;
			}
		}
		else
		{
			node = node->next;
		}
	}
	return count;
}
int LinkedList::countNotEqualPairs(vector<int>v)
{
	int size = countPairs(v);
	int**pairs = new int*[size];
	for (int i = 0; i < size; i++)
	{
		pairs[i] = new int[2];
	}
	Node* node = new Node;
	node = this->head;
	int count = 0;
	int index = 0;
	int index1 = 0;
	int firstIndex = index1;
	int secondIndex = index;
	bool isExsist;
	while (node->next != NULL)
	{
		isExsist = binarySearch(v, 0, v.size() - 1, node->data);
		if (isExsist)
		{
			pairs[firstIndex][secondIndex] = node->data;
			secondIndex++;
			node = node->next;
			isExsist = binarySearch(v, 0, v.size() - 1, node->data);
			if (isExsist)
			{
				pairs[firstIndex][secondIndex] = node->data;
				secondIndex = 0;
				firstIndex++;
				index1 = firstIndex;
				index = secondIndex;
			}
			else
			{
				firstIndex = index1;
				secondIndex = index;
			}
		}
		else
		{
			node = node->next;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i + 1 < size && j + 1 < 2)
			{
				if ((pairs[i][j] == pairs[i + 1][j] && pairs[i][j + 1] == pairs[i + 1][j + 1]) || (pairs[i][j] == pairs[i + 1][j + 1] &&
					pairs[i][j + 1] == pairs[i + 1][j]))
				{
					count++;
				}
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		delete[] pairs[i];
	}
	delete[]pairs;
	return size - count;

}
int main()
{
	LinkedList list;
	int n;
	cin >> n;
	int p;
	int element;
	int number;
	while (n != 0)
	{
		cin >> number;
		list.AddElement(number);
		n--;
	}
	cin >> p;
	vector<int>v;
	for (int i = 0; i < p; i++)
	{
		cin >> element;
		if (element <= 1234)
		{
			v.push_back(element);
		}
	}
	sort(v.begin(), v.end());
	if (list.countNotEqualPairs(v) < 0)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << list.countNotEqualPairs(v) << endl;
	}

	system("pause");
	return 0;
}