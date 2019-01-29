#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node*left;
	Node*right;
};
Node *createNode(int item)
{
	Node *newNode = new Node;
	newNode->data = item;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node*search(Node*root, int element)
{
	if (root == NULL || root->data == element)
	{
		return root;
	}
	if (root->data < element)
	{
		return search(root->right, element);
	}
	return search(root->left, element);
}
Node*insert(Node*root, int element)
{
	if (root == NULL)
	{
		return createNode(element);
	}
	if (element < root->data)
	{
		root->left = insert(root->left, element);
	}
	else if (element > root->data)
	{
		root->right = insert(root->right, element);
	}
	return root;
}
int main()
{
	Node*root = NULL;
	int m,n;
	cin >> m;
	root = insert(root, m);
	int firstPlayer;
	int secondPlayer;
	int counter = 1;
	cin >> n;
	while (n > 0)
	{
		cin >> firstPlayer;
		cin >> secondPlayer;
		if (search(root,firstPlayer)!=NULL)
		{
			root = insert(root, secondPlayer);
			counter++;
		}
		n--;
	}
	cout << counter << endl;
	
	system("pause");
	return 0;
}