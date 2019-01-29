#include <iostream>


using namespace std;
int countLeft = 0;
int countRight = 0;
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
		else {
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


	void leftRight(Node *root)
	{
		if (root != NULL)
		{


			if (root->rightNode != NULL)
			{
				countRight++;
				leftRight(root->rightNode);
			}
			if (root->leftNode != NULL)
			{
				countLeft++;
				leftRight(root->leftNode);
			}
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

	myTree.leftRight(root);
	cout << "[" << countLeft << "," << countRight << "]";
	return 0;
}