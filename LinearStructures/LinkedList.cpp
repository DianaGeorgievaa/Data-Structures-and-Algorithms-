#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};
class Stack
{
private:
	Node * top;
	int size;
public:
	Stack()
	{
		top = NULL;
		size = 0;
	}
	void push(int element);
	int pop();
	int peek();
	bool isEmpty();
	void Print();
};
void Stack::push(int element)
{
	Node *newTop = new Node();
	newTop->data = element;
	newTop->next = top;
	top = newTop;
	size++;
}
int Stack::pop()
{
	if (top == NULL)
	{
		return 0;
	}
	int value = top->data;
	Node *nextTop = top->next;
	delete top;
	top = nextTop;
	size--;
	return value;
}
int Stack::peek()
{
	if (top!= NULL)
	{
		return top->data;
	}
}
bool Stack::isEmpty()
{
	return size == 0;
}
void Stack::Print()
{
	Node*current = top;
	while (current!=NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
}
int main()
{
	Stack stack;
	stack.push(5);
	stack.push(6);
	stack.push(7);
	stack.push(8);
	stack.Print();
	system("pause");
	return 0;
}