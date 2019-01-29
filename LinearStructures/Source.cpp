#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Node
{
	int data;
	Node*next;
	Node(int d, Node*n)
	{
		this->data = d;
		this->next = n;
	}
};
class LinkedList
{
public:
	LinkedList()
	{
		this->head = NULL;
		this->size = 0;
	}
	void add(int val, int pos)
	{
		if (pos < 0 || pos > size)
		{
			cout << "add_last";
			pos = size;
		}

		if (!head || pos == 0)
		{
			head = new Node(val, head);
		}
		else {
			Node * cur = head;

			while (pos > 1) {
				pos--;
				cur = cur->next;
			}

			cur->next = new Node(val, cur->next);
		}
		size++;
	}
	void print()
	{
		Node*current = this->head;
		while (current != NULL)
		{
			cout << current->data << "#";
			current = current->next;
		}
	}

	void remove(int pos)
	{
		if (pos < 0 || pos >= size)
		{
			cout << "remove_failed";
			return;
		}
		Node * previous = NULL;
		Node * current = head;
		while (pos > 0)
		{
			previous = current;
			current = current->next;
			pos--;
		}

		if (previous == NULL)
		{
			previous = head->next;
			delete this->head;
			this->head = previous;
		}
		else
		{
			previous->next = current->next;
			delete current;
		}

		size--;
	}

	void reverse()
	{
		Node *current = this->head;
		Node *prev = NULL;
		Node*next = NULL;

		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		this->head = prev;
	}

	void remove_all(int val)
	{
		Node * current = head;

		while (current && current->next) {
			if (current->next->data == val) {
				Node * temp = current->next->next;
				delete current->next;
				current->next = temp;
				size--;
			}
			else
			{
				current = current->next;
			}
		}

		if (head && head->data == val)
		{
			Node * temp = head->next;
			delete head;
			head = temp;
			size--;
		}
	}

	void group(int a, int b) 
	{
		if (a < 0 ||b >= size || b < a) 
		{
			cout << "fail_grouping";
		}
		else {
			int elementsToDelete = b - a;
			Node * current = head;
			while (a > 0) 
			{
				current= current->next;
				a--;
			}

			while (elementsToDelete> 0)
			{
				Node * temp = current->next->next;
				current->data += current->next->data;
				delete current->next;
				current->next = temp;
				elementsToDelete--;
				size--;
			}
		}
	}

	void count(int val)
	{
		int counter = 0;
		Node*current = head;
		while (current != NULL)
		{
			if (current->data == val)
			{
				counter++;
			}
			current = current->next;
		}
		cout << counter;
	}

	void is_palindrome()
	{
		vector<int>v;
		Node*current = head;
		while (current != NULL)
		{
		    v.push_back(current->data);
			current = current->next;	
		}
		bool isPalindrom = true;
		for (int i = 0; i <v.size()/ 2; i++)
		{
			if (v[i] != v[size - 1 - i])
			{
				isPalindrom = false;
				break;
			}
		}
		if (isPalindrom == true)
		{
			cout << "true";
		}
		else
		{
			cout << "false";
		}
	}

	~LinkedList()
	{
		delete[] head;
	}

private:
	Node * head;
	int size;
};

int main()
{
	int cases;
	std::cin >> cases;
	for (int i = 0; i < cases; i++) {
		LinkedList ll;
		int ops;
		std::string op;
		std::cin >> ops;
		for (int j = 0; j < ops; j++) {
			std::cin >> op;

			if (op == "count") {
				int arg1;
				std::cin >> arg1;
				ll.count(arg1);
			}

			if (op == "add") {
				int arg1, arg2;
				std::cin >> arg1 >> arg2;
				ll.add(arg1, arg2);
			}

			if (op == "print") {
				ll.print();
			}

			if (op == "remove") {
				int arg1;
				std::cin >> arg1;
				ll.remove(arg1);
			}

			if (op == "reverse") {
				ll.reverse();
			}

			if (op == "remove_all") {
				int arg1;
				std::cin >> arg1;
				ll.remove_all(arg1);
			}

			if (op == "group") {
				int arg1, arg2;
				std::cin >> arg1 >> arg2;
				ll.group(arg1, arg2);
			}

			if (op == "is_palindrom") {
				ll.is_palindrome();
			}
		}

		std::cout << std::endl;

	}
	system("pause");
	return 0;
}