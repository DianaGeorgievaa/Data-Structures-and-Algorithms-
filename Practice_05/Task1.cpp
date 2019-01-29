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
		this->head = NULL;
		this->tail = NULL;
	}
	void Winner(int n);
	~LinkedList() {};
private:
	long long size;
	Node* head;
	Node*tail;
};
Node* createNode(int element)
{
	Node*curr = new Node;
	curr->next = curr;
    curr->data = element;
	return curr;
}
void LinkedList::Winner(int n)
{
	int steps = 2;
	Node* head = createNode(1);
	Node * previous = head;
	for (int i = 2; i <= n; i++)
	{
		previous->next =createNode(i);
		previous = previous->next;
	}
	previous->next = head;
	Node *h = head;
	Node* h1 = head;
	while (h->next != h)
	{
		int counter = 1;
		while (counter != steps)
		{
			h1 = h;
			h = h->next;
			counter++;
		}
		h1->next = h->next;
		h = h1->next;
	}
	cout << h->data << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	LinkedList list;
	long long n;
	cin >> n;
	list.Winner(n);
	system("pause");
	return 0;
}