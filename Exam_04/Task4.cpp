#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node *leftNode;
	Node *rightNode;
	Node(int d) {
		data = d;
		leftNode = NULL;
		rightNode = NULL;
	}
};

class Solution {
public:
	Node * insert(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		}
		else
		{
			Node* cur;
			if (data <= root->data) {
				cur = insert(root->leftNode, data);
				root->leftNode = cur;
			}
			else {
				cur = insert(root->rightNode, data);
				root->rightNode = cur;
			}

			return root;
		}
	}

	int height(Node*root)
	{
		if (root != NULL)
		{
			int left = height(root->leftNode);
			int right = height(root->rightNode);
			if (left > right)
			{
				return left + 1;
			}
			else
			{
				return right + 1;
			}
		}
		else
		{
			return 0;
		}
	}
	void l(Node*root, int level, int &count)
	{
		if (root == NULL)
		{
			return;
		}
		else if (level == 1)
		{
			count++;
		}
		else
		{
			l(root->leftNode, level - 1, count);
			l(root->rightNode, level - 1, count);
		}
	}
	void count(Node *root)
	{
		int c = 0;
		for (int i = 1; i<height(root) + 1; i++)
		{
			l(root, i, c);
			if (i + 1 == height(root) + 1)
			{
				cout << c;
			}
			else
			{

				cout << c << ";";
			}
			c = 0;
		}
	}


}; 

int main() {

	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0) {
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	myTree.count(root);
	return 0;
}