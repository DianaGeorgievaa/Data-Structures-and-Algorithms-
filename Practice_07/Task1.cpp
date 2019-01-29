#include <iostream>
#include<vector>
#include<queue>
#include<math.h>
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
	else if (element >= root->data)
	{
		root->right = insert(root->right, element);
	}
	return root;
}

void averageSum(Node* root)
{
	vector<double> result;
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) 
	{
		double sum = 0, counter = 0;
		queue<Node*> temp;
		while (!q.empty()) 
		{
			Node* node = q.front();
			q.pop();
			sum += node->data;
			counter++;
			if (node->left != NULL)
			{
				temp.push(node->left);
			}
			if (node->right != NULL)
			{
				temp.push(node->right);
			}
		}
		q = temp;
		printf("%.2f", sum / counter);
		cout << endl;
	}
}
int main()
{
	Node*root = NULL;
	int n;
	cin >> n;
	int element;

	while (n > 0)
	{
		cin >> element;
		root = insert(root, element);
		n--;
	}
	averageSum(root);
	system("pause");
	return 0;
}