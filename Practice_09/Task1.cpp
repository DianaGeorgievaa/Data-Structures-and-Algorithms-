#include <iostream>
using namespace std;
struct Node
{
	long long value;
	Node*next;
};
Node*createNode(long long item)
{
	Node*node = new Node;
	node->value = item;
	node->next = NULL;
	return node;
}
class HashTable
{
private:
	Node**arr;
	int numberOfElements = 0;
public:
	HashTable(int size)
	{
		this->arr = new Node*[size];
	}
	void add(long long item,int size);
	int getSize();

};
void HashTable:: add(long long item,int size)
{
	int index = item % size;
	if (index < 0)
	{
		index = index * (-1);
	}
	if (arr[index] == NULL)
	{
		arr[index] = createNode(item);
		numberOfElements++;
	}
	else if (arr[index]->value != item)
	{
		Node*current = arr[index];
		while (current->next != NULL)
		{
			if (current->value == item)
			{
				return;
			}
			current = current->next;
		}
		current-> next = createNode(item);
		numberOfElements++;
	}
}
int HashTable::getSize()
{
	return numberOfElements;
}

int main()
{

	
	int n;
	cin >> n;
	int newN = n;
	HashTable h(newN);
	long long numbers;
	while (n > 0)
	{
		cin >> numbers;
		h.add(numbers, newN);
		n--;
	}
	cout <<h.getSize() << endl;
	system("pause");
	return 0;
}