#include <iostream>
#include<queue>
using namespace std;
struct Point
{
	int x;
	int y;
};
struct Node
{
	Point p;
	int distance;
};
bool isValid(int row, int col, int n, int m)
{
	return (row >= 0) && (row < n) &&
		(col >= 0) && (col < m);
}
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

int BFS(int** matrix, Point src, Point destination, int n, int m)
{
	if (matrix[src.x][src.y] || matrix[destination.x][destination.y])
	{
		return -1;
	}
	bool** visited = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = new bool[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = false;
		}
	}
	visited[src.x][src.y] = true;
	queue<Node> q;
	Node s = { src, 0 };
	q.push(s);
	while (!q.empty())
	{
		Node current = q.front();
		Point pt = current.p;
		if (pt.x == destination.x && pt.y == destination.y)
		return current.distance;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];
			if (isValid(row, col, n, m) == true && matrix[row][col] == false && !visited[row][col])
			{
				visited[row][col] = true;
				Node Adjcell = { { row, col },current.distance + 1 };
				q.push(Adjcell);
			}
		}
	}
	return -1;
}
int main()
{
	int m;
	cin >> m;
	int n;
	cin >> n;
	int k;
	cin >> k;
	int**matrix = new int*[m];
	int x1;
	int y1;
	int dist;
	int* answers = new int[k];
	int index = 0;
	Point source = { 0, 0 };
	Point dest;
	for (int i = 0; i < m; i++)
	{
		matrix[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	while (k > 0)
	{
		cin >> x1;
		cin >> y1;
		dest = { x1, y1 };
		answers[index] = BFS(matrix, source, dest, n, m);
		index++;
		k--;
	}
	for (int i = 0; i < index; i++)
	{
		cout << answers[i] << endl;
	}
	delete[]answers;
	for (int i = 0; i<n; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
	system("pause");
	return 0;

}
