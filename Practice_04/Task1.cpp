#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node*next;
};

class LinkedList
{
public:
	LinkedList()
	{
		this->size = 0;
		this->head = NULL;
		this->tail = NULL;
	}
	void AddElement(int element);
	void MinMaxAndSum();
	long long Length();
	~LinkedList() {};
private:
	long long size;
	Node* head;
	Node*tail;
};
void LinkedList::AddElement(int element)
{
	Node*node = new Node();
	node->data = element;
	node->next = NULL;
	if (head == NULL)
	{
		this->head = node;
		this->size++;
		this->tail = node;
		node = NULL;
	}
	else
	{
		tail->next = node;
		this->tail = node;
		this->size++;
	}
}
void LinkedList::MinMaxAndSum()
{
	Node* currentElement = this->head;
	int minElement = currentElement->data;
	int maxElement = currentElement->data;
	long long sumOfElements = 0;
	while (currentElement != NULL)
	{
		sumOfElements = sumOfElements + currentElement->data;
		if (currentElement->data > maxElement)
		{
			maxElement = currentElement->data;
		}
		if (currentElement->data < minElement)
		{
			minElement = currentElement->data;
		}
		currentElement = currentElement->next;
	}
	cout << minElement << endl;
	cout << maxElement << endl;
	cout << sumOfElements << endl;
}
long long LinkedList::Length()
{
	return this->size;
}
int main()
{
	ios_base::sync_with_stdio(false);
	LinkedList list;
	int number;
	long long numberOfElements;
	long long sumOfElements = 0;
	while (cin >> number)
	{
		list.AddElement(number);
	}
	numberOfElements = list.Length();
	list.MinMaxAndSum();
	system("pause");
	return 0;
}