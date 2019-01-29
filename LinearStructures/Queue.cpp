#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class Queue
{
private:
	Node * head;
	Node*tail;
public:
	Queue()
	{
		this->head = NULL;
		this->tail = NULL;
	}
	void insert(int n);
	void deleteItem();
	void display();
};
void Queue::insert(int n)
{
	Node *newElement = new Node;
	newElement->data = n;
	newElement->next = NULL;
	if (newElement == NULL) 
	{
		return;
	}
	if (head == NULL) 
	{
		tail = newElement;
		head = newElement;
	}
	else 
	{
		tail->next = newElement;
		tail = newElement;
	}

}
void Queue::display()
{
	if (head == NULL)
	{
		return;
	}
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void Queue::deleteItem()
{
	if (head == NULL)
	{
		return;
	}

	cout << head->data << endl;
	if (head == tail)
	{
		head = tail = NULL;
	}
	else
	{
		head = head->next;
	}
}
int main()
{
	Queue q;
	q.insert(5);
	q.insert(6);
	q.insert(7);
	q.display();
	system("pause");
	return 0;
}