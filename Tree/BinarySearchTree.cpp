#include<iostream>
using namespace std;
const int MAX_SIZE = 15000;
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
		return root = createNode(element);
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
void printInOrder(Node*root)
{
	if (root != NULL)
	{
		printInOrder(root->left);
		cout << root->data << " ";
		printInOrder(root->right);
	}
}
void printPreOrder(Node*root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}
void levelOrderTraversal(Node*root)
{
	if (root != NULL)
	{
		Node**queue = new Node*[MAX_SIZE];
		int start = 0;
		int end = 1;
		queue[start] = root;
		while (start != end)
		{
			Node*node = queue[start];
			start++;
			if (node != NULL)
			{
				cout << node->data << " ";
				queue[end] = node->left;
				end++;
				queue[end] = node->right;
				end++;
			}
		}
	}
}
int height(Node*root)
{
	if (root == NULL)
	{
		return -1;
	}
	else
	{
		int leftNodes = height(root->left);
		int rightNodes = height(root->right);
		if (leftNodes > rightNodes)
		{
			return leftNodes + 1;
		}
		else
		{
			return rightNodes + 1;
		}
	}
}
Node* minValueNode(Node*node)
{
	Node*current = node;
	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}
Node*deleteNode(Node*root, int element)
{
	if (root == NULL)
	{
		return root;
	}
	if (element < root->data)
	{
		root->left = deleteNode(root->left, element);
	}
	else if (element > root->data)
	{
		root->right = deleteNode(root->right, element);
	}
	else
	{
		if (root->left == NULL)
		{	Node*temp = root->right;
			delete root;
			return temp;
		}
		if (root->right == NULL)
		{
			Node*temp = root->left;
			delete root;
			return temp;
		}
		Node*temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

void Level(Node*root, int level)
{
	if (root == NULL)
	{
		return;
	}
	if (level == 1)
	{
		cout << root->data << " ";
	}
	else
	{
		Level(root->left, level - 1);
		Level(root->right, level - 1);
	}
};
int sum(Node*root)
{
	if (root==NULL)
	{
		return 0;
	}
	else
	{
		    int s = 0;
			s += root->data + sum(root->left);
			s += sum(root-> right);
			return s;
	}
};
void printLevelOnOneRow(Node*root)
{
	int h = height(root);
	for (int i = 1; i <= h+1; i++)
	{
		Level(root, i);
	}
};

void printLevelOnDifferentRows(Node*root)
{
	int h = height(root);
	for (int i = 1; i <= h + 1; i++)
	{
		Level(root, i);
		cout << endl;
	}
};

void PrintLevel(Node*root, int level)
{
	Level(root, level);
};

int main()
{
	Node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 60);

	system("pause");
	return 0;
}