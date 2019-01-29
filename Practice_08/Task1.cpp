#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct Node
{
	double value;
	Node *left;
	Node *right;
	int h;

	Node(double value, Node *left, Node *right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
		this->h = 0;
	}
};

class AVLTree
{
private:
	Node * root;
	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->value == value)
		{
			return true;
		}

		if (value < current->value)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->value << " ";
		printRecursive(current->right);
	}
	int height(Node* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		else
		{
			return node->h;
		}
	}

	int balance(Node* node)
	{
		if (node != NULL)
		{
			return height(node->left) - height(node->right);
		}
		return 0;
	}
	int max(int a, int b)
	{
		if (a>b)
		{
			return a;
		}
		return b;
	}
	Node *LeftRotate(Node *node)
	{
		Node *y = node->right;
		Node *t = y->left;
		y->left = node;
		node->right = t;

		node->h = max(height(node->left), height(node->right)) + 1;
		y->h = max(height(y->left), height(y->right)) + 1;
		return y;
	}
	Node *RightRotate(Node *node)
	{
		Node *x = node->left;
		Node *t = x->right;
		x->right = node;
		node->left = t;
		node->h = max(height(node->left), height(node->right)) + 1;
		x->h = max(height(x->left), height(x->right)) + 1;
		return x;
	}
	Node* minValue(Node* node)
	{
		if (node == NULL)
		{
			return NULL;
		}
		if (node->left != NULL)
		{
			return minValue(node->left);

		}
		return node;
	}
	Node* insert(Node* node, double key)
	{
		if (node == NULL)
		{
			node = new Node(key, NULL, NULL);
		}
		if (key < node->value)
		{
			node->left = insert(node->left, key);
		}
		else if (key > node->value)
		{
			node->right = insert(node->right, key);
		}
		else
		{
			return node;
		}
		int b = balance(node);
		node->h = max(height(node->left), height(node->right)) + 1;

		if (b > 1 && key < node->left->value)
		{
			return RightRotate(node);
		}

		if (b < -1 && key> node->right->value)
		{
			return LeftRotate(node);
		}
		if (b > 1 && key> node->left->value)
		{
			node->left = LeftRotate(node->left);
			return RightRotate(node);
		}
		if (b < -1 && key < node->right->value)
		{
			node->right = RightRotate(node->right);
			return LeftRotate(node);
		}

		return node;
	}

	Node* deleteNode(Node*node, double key)
	{
		Node* temp;
		if (node == NULL)
		{
			return root;
		}
		if (key < node->value)
		{
			node->left = deleteNode(node->left, key);

		}
		else if (key> node->value)
		{
			node->right = deleteNode(node->right, key);

		}
		else
		{
			if ((node->left == NULL) || (node->right == NULL))
			{
				temp = node->left ? node->left : node->right; ;
				if (temp == NULL)
				{
					temp = node;
					node = NULL;
				}
				else
				{
					*node = *temp;
					free(temp);
				}
			}
			else
			{
				temp = minValue(node->right);
				node->value = temp->value;
				node->right = deleteNode(node->right, temp->value);
			}
		}
		if (node == NULL)
		{
			return node;
		}
		node->h = max(height(node->left), height(node->right)) + 1;

		int b = balance(node);

		if (b > 1 && balance(node->left) >= 0)
		{
			return RightRotate(node);
		}

		if (b> 1 && balance(node->left) < 0)
		{
			node->left = LeftRotate(node->left);
			return RightRotate(node);
		}

		if (b< -1 && balance(node->right) <= 0)
		{
			return LeftRotate(node);
		}
		if (b< -1 && balance(node->right) > 0)
		{
			node->right = RightRotate(node->right);
			return LeftRotate(node);
		}

		return node;
	}
public:
	AVLTree()
	{
		root = NULL;
	};

	void add(double value)
	{
		if (containsRecursive(root, value) == true)
		{
			cout << value << " already added" << endl;
		}
		else
		{
			root = insert(root, value);
		}
	};

	void remove(double value)
	{
		if (containsRecursive(root, value) == false)
		{
			cout << value << " not found to remove" << endl;
		}
		else
		{
			root = deleteNode(root, value);
		}

	};

	bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	};

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
		cout << endl;
	};
};

int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
	cout << fixed;

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(number);
		}
		else if (operation == "remove")
		{
			tree.remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}

	return 0;
}
